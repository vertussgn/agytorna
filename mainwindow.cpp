#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QVBoxLayout>
#include "databasemanager.h"
#include "ui_mainwindow.h"
#include "qamanager.h"
#include <QInputDialog>
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , correctAnswers(0)
    , totalPoints(0)
    , answerSelected(false)
    , selectedAnswerIndex(-1)
    , selectedLanguage(Language::Hungarian)
    , selectedCategory(Category::Vocabulary)
    , selectedDifficulty(Difficulty::Beginner)
    , currentStreak(5)
    , totalWordsLearned(97)
    , selectedCategoryButton(nullptr)
    , selectedDifficultyButton(nullptr)
{
    ui->setupUi(this);
    if (ui->listeningButton) {
        ui->listeningButton->hide();
    }
    setupConnections();
    showMainMenu();
    loadStatisticsFromBackend();

    QaManager::logSystem("Főablak inicializálva.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ============================================================================
// OLDALAK MEGJELENÍTÉSE
// ============================================================================

void MainWindow::showMainMenu()
{
    setMainMenuVisibility(true, false);
    ui->stackedWidget->setCurrentWidget(ui->mainMenuPage);
    loadStatisticsFromBackend();
}

void MainWindow::showLanguageSelectOnly()
{
    setMainMenuVisibility(false, true);
    ui->stackedWidget->setCurrentWidget(ui->mainMenuPage);
}

void MainWindow::setMainMenuVisibility(bool showStats, bool showLanguages)
{
    ui->statsCard->setVisible(showStats);
    ui->statsCard_2->setVisible(showStats);
    ui->statsCard_3->setVisible(showStats);

    ui->sectionLabel->setVisible(showLanguages);
    ui->hungarianButton->setVisible(showLanguages);
    ui->englishButton->setVisible(showLanguages);
    ui->germanButton->setVisible(showLanguages);
    ui->russianButton->setVisible(showLanguages);

    if (showStats && showLanguages) {
        ui->welcomeLabel->setText("Üdvözöl az Agytorna! 🧠");
        ui->subtitleLabel->setText("Válassz nyelvet és kezdj el tanulni!");
        ui->subtitleLabel->setVisible(true);
    } else if (showLanguages && !showStats) {
        ui->welcomeLabel->setText("Nyelvválasztás 🌍");
        ui->subtitleLabel->setText("Melyik nyelvet szeretnéd gyakorolni?");
        ui->subtitleLabel->setVisible(true);
    }
}

// ============================================================================
// PROFIL KEZELÉS (Login / Regisztráció / Névváltás)
// ============================================================================

void MainWindow::showProfilePage()
{
    if (currentUserId != -1) {
        User u = DatabaseManager::instance().getUser(currentUserId);

        QMessageBox msgBox;
        msgBox.setWindowTitle("Fiók kezelése");
        msgBox.setText(QString("Bejelentkezve: <b>%1</b>\nSorozat: %2 nap").arg(u.username).arg(u.streak));
        msgBox.setIcon(QMessageBox::Information);

        // Gombok
        QPushButton *btnRename = msgBox.addButton("Névváltás ✏️", QMessageBox::ActionRole);
        QPushButton *btnLogout = msgBox.addButton("Kijelentkezés 🚪", QMessageBox::DestructiveRole);
        QPushButton *btnCancel = msgBox.addButton("Mégse", QMessageBox::RejectRole);

        msgBox.exec();

        if (msgBox.clickedButton() == btnRename) {
            handleChangeUsername();
        } else if (msgBox.clickedButton() == btnLogout) {
            currentUserId = -1;
            QaManager::logSystem("Felhasználó kijelentkezett.");
            QMessageBox::information(this, "Kilépés", "Sikeresen kijelentkeztél.");
            showMainMenu();
        }
        return;
    }

    // HA NINCS BEJELENTKEZVE
    QMessageBox msgBox;
    msgBox.setWindowTitle("Agytorna - Fiók");
    msgBox.setText("Lépj be vagy regisztrálj a haladásod mentéséhez!");
    msgBox.setIcon(QMessageBox::Question);

    QPushButton *btnLogin = msgBox.addButton("Bejelentkezés", QMessageBox::ActionRole);
    QPushButton *btnReg = msgBox.addButton("Regisztráció", QMessageBox::ActionRole);
    QPushButton *btnCancel = msgBox.addButton("Mégse", QMessageBox::RejectRole);

    msgBox.exec();

    if (msgBox.clickedButton() == btnLogin) handleLogin();
    else if (msgBox.clickedButton() == btnReg) handleRegister();
}

void MainWindow::handleLogin()
{
    bool ok;
    QString username = QInputDialog::getText(this, "Bejelentkezés",
                                             "Felhasználónév:", QLineEdit::Normal, "", &ok);
    if (!ok || username.isEmpty()) return;

    QString password = QInputDialog::getText(this, "Bejelentkezés",
                                             "Jelszó:", QLineEdit::Password, "", &ok);
    if (!ok || password.isEmpty()) return;

    int id = DatabaseManager::instance().loginUser(username, password);
    if (id != -1) {
        currentUserId = id;
        QMessageBox::information(this, "Siker", "Sikeres bejelentkezés!\nÜdv, " + username + "!");
        QaManager::logSystem("Felhasználó bejelentkezett: " + username);
        loadStatisticsFromBackend();
    } else {
        QMessageBox::warning(this, "Hiba", "Hibás felhasználónév vagy jelszó!");
    }
}

void MainWindow::handleRegister()
{
    bool ok;
    QString username = QInputDialog::getText(this, "Regisztráció",
                                             "Válassz felhasználónevet:", QLineEdit::Normal, "", &ok);
    if (!ok || username.isEmpty()) return;

    QString password = QInputDialog::getText(this, "Regisztráció",
                                             "Válassz jelszót:", QLineEdit::Password, "", &ok);
    if (!ok || password.isEmpty()) return;

    int result = DatabaseManager::instance().registerUser(username, password);

    if (result == -2) {
        QMessageBox::warning(this, "Hiba", "Ez a felhasználónév már foglalt!");
    } else if (result == -1) {
        QMessageBox::critical(this, "Hiba", "Adatbázis hiba történt a regisztráció során.\nEllenőrizd a log fájlt.");
    } else {
        currentUserId = result;
        QMessageBox::information(this, "Siker", "Sikeres regisztráció!\nJó tanulást, " + username + "!");
        QaManager::logSystem("Új felhasználó regisztrált: " + username);
        loadStatisticsFromBackend();
    }
}

void MainWindow::handleChangeUsername()
{
    User u = DatabaseManager::instance().getUser(currentUserId);

    bool ok;
    QString newName = QInputDialog::getText(this, "Névváltás",
                                            "Új felhasználónév:", QLineEdit::Normal, u.username, &ok);

    if (ok && !newName.isEmpty() && newName != u.username) {
        if (DatabaseManager::instance().updateUsername(currentUserId, newName)) {
            QMessageBox::information(this, "Siker", "Felhasználónév sikeresen módosítva!");
            QaManager::logSystem("Felhasználónév módosítva: " + u.username + " -> " + newName);

            showProfilePage(); // Újra megnyitjuk a profilt a friss névvel
        } else {
            QMessageBox::warning(this, "Hiba", "Nem sikerült a névváltás.\nLehet, hogy ez a név már foglalt.");
        }
    }
}

void MainWindow::loadStatisticsFromBackend()
{
    if (currentUserId == -1) {
        ui->completedLabel->setText("0");
        ui->wordsLearnedLabel->setText("0");
        ui->streakLabel->setText("0");
        return;
    }

    int tests  = DatabaseManager::instance().getTestCount(currentUserId);
    int words  = DatabaseManager::instance().getLearnedWords(currentUserId);
    User u     = DatabaseManager::instance().getUser(currentUserId);

    ui->completedLabel->setText(QString::number(tests));
    ui->wordsLearnedLabel->setText(QString::number(words));
    ui->streakLabel->setText(QString::number(u.streak));
}

void MainWindow::showCategoryPage()
{
    QString langText = QString("Kiválasztott nyelv: %1 %2")
                           .arg(getLanguageName(selectedLanguage))
                           .arg(getLanguageFlag(selectedLanguage));
    ui->selectedLanguageLabel->setText(langText);
    ui->stackedWidget->setCurrentWidget(ui->categoryPage);
}

// ============================================================================
// KVÍZ MEGJELENÍTÉS
// ============================================================================

void MainWindow::displayQuestion()
{
    const Question *currentQ = gameLogic.getCurrentQuestion();

    if (currentQ == nullptr) {
        showResults();
        return;
    }

    ui->questionLabel->setText(currentQ->questionText);
    ui->wordLabel->setText(currentQ->word);

    clearAnswerButtons();
    createAnswerButtons(*currentQ);

    ui->feedbackLabel->clear();
    ui->feedbackLabel->setStyleSheet("");

    answerSelected = false;
    selectedAnswerIndex = -1;
    ui->nextQuestionButton->setEnabled(false);
    ui->nextQuestionButton->setText("Válasz ellenőrzése");

    updateQuestionCounter();
    updateCurrentScore();
}

void MainWindow::updateUIState()
{
    for (QPushButton *btn : answerButtons) {
        btn->setEnabled(!answerSelected);
    }
    ui->nextQuestionButton->setEnabled(answerSelected);
}

// ============================================================================
// EREDMÉNYEK
// ============================================================================

void MainWindow::showResults()
{
    ui->stackedWidget->setCurrentWidget(ui->resultsPage);

    int quizSize = gameLogic.getTotalQuestions();

    QString scoreText = QString("%1 / %2").arg(correctAnswers).arg(quizSize);
    ui->resultLabel->setText(scoreText);

    double percentage = (quizSize > 0) ? (correctAnswers * 100.0 / quizSize) : 0.0;
    ui->percentageLabel->setText(QString("%1%").arg(QString::number(percentage, 'f', 0)));

    ui->pointsLabel->setText(QString("Pontszám: %1").arg(totalPoints));
    ui->messageLabel->setText(getMotivationalMessage(percentage));

    updateStatisticsInBackend();
}

void MainWindow::restartGame()
{
    correctAnswers = 0;
    totalPoints = 0;
    answerSelected = false;
    selectedAnswerIndex = -1;

    gameLogic.refreshQuestionPool(selectedCategory, selectedDifficulty);

    if (gameLogic.getTotalQuestions() == 0) {
        QMessageBox::information(this, "Nincs kérdés",
                                 "Ehhez a kombinációhoz még nincsenek kérdések az adatbázisban.");
        QaManager::logSystem("Újraindítás sikertelen: Nincs kérdés.", true);
        return;
    }

    QaManager::logSystem("Játék újraindítva ugyanazokkal a beállításokkal.");

    ui->stackedWidget->setCurrentWidget(ui->quizPage);
    displayQuestion();
}

void MainWindow::highlightAnswer(int answerIndex, bool isCorrect)
{
    const Question *currentQ = gameLogic.getCurrentQuestion();

    if (answerIndex >= 0 && answerIndex < answerButtons.size()) {
        QPushButton *btn = answerButtons[answerIndex];

        if (isCorrect) {
            btn->setStyleSheet("QPushButton { background-color: #27ae60; color: white; "
                               "border: 3px solid #1e8449; border-radius: 10px; padding: 15px; "
                               "font-size: 16px; font-weight: bold; text-align: left; }");
        } else {
            btn->setStyleSheet("QPushButton { background-color: #e74c3c; color: white; "
                               "border: 3px solid #c0392b; border-radius: 10px; padding: 15px; "
                               "font-size: 16px; font-weight: bold; text-align: left; }");
        }

        if (!isCorrect && currentQ != nullptr) {
            int correctIdx = currentQ->correctAnswer;
            if (correctIdx >= 0 && correctIdx < answerButtons.size()) {
                answerButtons[correctIdx]->setStyleSheet(
                    "QPushButton { background-color: #27ae60; color: white; "
                    "border: 3px solid #1e8449; border-radius: 10px; padding: 15px; "
                    "font-size: 16px; font-weight: bold; text-align: left; }");
            }
        }
    }
}

// ============================================================================
// VÁLASZKEZELÉS
// ============================================================================

void MainWindow::handleAnswer(int answerIndex)
{
    if (answerSelected) return;

    if (selectedAnswerIndex >= 0 && selectedAnswerIndex < answerButtons.size()) {
        answerButtons[selectedAnswerIndex]->setStyleSheet(
            "QPushButton { background-color: white; color: #000000; "
            "border: 2px solid #bdc3c7; border-radius: 10px; padding: 15px; "
            "font-size: 16px; text-align: left; }");
    }

    selectedAnswerIndex = answerIndex;
    if (answerIndex >= 0 && answerIndex < answerButtons.size()) {
        answerButtons[answerIndex]->setStyleSheet(
            "QPushButton { background-color: #3498db; color: white; "
            "border: 3px solid #2980b9; border-radius: 10px; padding: 15px; "
            "font-size: 16px; text-align: left; font-weight: bold; }");
        ui->nextQuestionButton->setEnabled(true);
    }
}

void MainWindow::checkSelectedAnswer()
{
    const Question *currentQ = gameLogic.getCurrentQuestion();
    if (selectedAnswerIndex < 0 || currentQ == nullptr) return;

    bool isCorrect = gameLogic.checkAnswer(selectedAnswerIndex);

    if (isCorrect) {
        correctAnswers++;
        totalPoints = gameLogic.calculateScore(totalPoints, currentQ->points);
    }

    answerSelected = true;
    sendAnswerToBackend(selectedAnswerIndex);
    highlightAnswer(selectedAnswerIndex, isCorrect);
    showFeedback(isCorrect);
    updateUIState();
    updateCurrentScore();
}

void MainWindow::showFeedback(bool isCorrect)
{
    if (isCorrect) {
        ui->feedbackLabel->setText("✓ Helyes válasz! Nagyszerű! 🎉");
        ui->feedbackLabel->setStyleSheet("QLabel { background-color: #d5f4e6; "
                                         "color: #0f5132; border: 2px solid #27ae60; border-radius: 12px; "
                                         "padding: 15px; font-size: 18px; font-weight: bold; }");
    } else {
        const Question *currentQ = gameLogic.getCurrentQuestion();
        QString correctAns = "";
        if (currentQ != nullptr) {
            int idx = currentQ->correctAnswer;
            if (idx >= 0 && idx < currentQ->answers.size()) {
                correctAns = currentQ->answers[idx];
            }
        }
        ui->feedbackLabel->setText(QString("✗ Helytelen! A helyes válasz: %1").arg(correctAns));
        ui->feedbackLabel->setStyleSheet("QLabel { background-color: #f8d7da; "
                                         "color: #721c24; border: 2px solid #e74c3c; border-radius: 12px; "
                                         "padding: 15px; font-size: 18px; font-weight: bold; }");
    }
}

void MainWindow::enableNextQuestion()
{
    ui->nextQuestionButton->setEnabled(true);
}

// ============================================================================
// NYELVVÁLASZTÁS
// ============================================================================

void MainWindow::onHungarianSelected()
{
    selectedLanguage = Language::Hungarian;
    gameLogic.setLanguage(Language::Hungarian);
    gameLogic.loadLanguageData();
    showCategoryPage();
}

void MainWindow::onEnglishSelected()
{
    selectedLanguage = Language::English;
    gameLogic.setLanguage(Language::English);
    gameLogic.loadLanguageData();
    showCategoryPage();
}

void MainWindow::onGermanSelected()
{
    selectedLanguage = Language::German;
    gameLogic.setLanguage(Language::German);
    gameLogic.loadLanguageData();
    showCategoryPage();
}

void MainWindow::onRussianSelected()
{
    selectedLanguage = Language::Russian;
    gameLogic.setLanguage(Language::Russian);
    gameLogic.loadLanguageData();
    showCategoryPage();
}

// ============================================================================
// KATEGÓRIA ÉS NEHÉZSÉG
// ============================================================================

void MainWindow::onVocabularySelected()
{
    handleCategorySelection(ui->vocabularyButton, Category::Vocabulary);
}

void MainWindow::onGrammarSelected()
{
    handleCategorySelection(ui->grammarButton, Category::Grammar);
}

void MainWindow::onSentencesSelected()
{
    handleCategorySelection(ui->sentencesButton, Category::Sentences);
}

void MainWindow::handleCategorySelection(QPushButton *button, Category category)
{
    if (selectedCategoryButton == button) {
        button->setStyleSheet("background-color: rgb(0, 0, 0);");
        selectedCategoryButton = nullptr;
        return;
    }

    if (selectedCategoryButton != nullptr) {
        selectedCategoryButton->setStyleSheet("background-color: rgb(0, 0, 0);");
    }

    button->setStyleSheet("QPushButton { background-color: rgb(231, 76, 60); "
                          "color: white; border: 3px solid rgb(192, 57, 43); border-radius: 10px; }");

    selectedCategoryButton = button;
    selectedCategory = category;
}

void MainWindow::onBeginnerSelected()
{
    handleDifficultySelection(ui->beginnerButton, Difficulty::Beginner);
}

void MainWindow::onIntermediateSelected()
{
    handleDifficultySelection(ui->intermediateButton, Difficulty::Intermediate);
}

void MainWindow::onAdvancedSelected()
{
    handleDifficultySelection(ui->advancedButton, Difficulty::Advanced);
}

void MainWindow::handleDifficultySelection(QPushButton *button, Difficulty difficulty)
{
    if (selectedDifficultyButton == button) {
        button->setStyleSheet("background-color: rgb(0, 0, 0);");
        selectedDifficultyButton = nullptr;
        return;
    }

    if (selectedDifficultyButton != nullptr) {
        selectedDifficultyButton->setStyleSheet("background-color: rgb(0, 0, 0);");
    }

    button->setStyleSheet("QPushButton { background-color: rgb(255, 165, 0); "
                          "color: white; border: 3px solid rgb(255, 140, 0); border-radius: 10px; }");

    selectedDifficultyButton = button;
    selectedDifficulty = difficulty;
}

// ============================================================================
// NAVIGÁCIÓ ÉS JÁTÉK INDÍTÁS
// ============================================================================

// --- Páll László: Játéklogika inicializálása ---
void MainWindow::startGame()
{
    QaManager::logSystem("startGame() meghívva: Játéklogika inicializálása...");

    gameLogic.refreshQuestionPool(selectedCategory, selectedDifficulty);

    // 2. Ellenőrzés, hogy van-e kérdés
    if (gameLogic.getTotalQuestions() == 0) {
        QMessageBox::information(this, "Nincs kérdés",
                                 "Ehhez a kombinációhoz még nincsenek kérdések az adatbázisban.");
        return;
    }

    // UI változók és pontszám alaphelyzetbe állítása
    correctAnswers = 0;
    totalPoints = 0;
    answerSelected = false;
    selectedAnswerIndex = -1;

    //Kvíz oldal megjelenítése
    QaManager::logSystem("Kvíz indul: " + getCategoryName(selectedCategory) + " - " + getDifficultyName(selectedDifficulty));

    QString categoryInfo = QString("%1 %2 | %3 %4")
                               .arg(getCategoryIcon(selectedCategory))
                               .arg(getCategoryName(selectedCategory))
                               .arg(getDifficultyIcon(selectedDifficulty))
                               .arg(getDifficultyName(selectedDifficulty));
    ui->categoryInfoLabel->setText(categoryInfo);

    ui->stackedWidget->setCurrentWidget(ui->quizPage);
    displayQuestion();
}

void MainWindow::onStartQuiz()
{
    startGame();
}

void MainWindow::onBackFromCategory()
{
    showMainMenu();
}

void MainWindow::onBackToMenu()
{
    showMainMenu();
}

void MainWindow::onNextQuestion()
{
    if (!answerSelected && selectedAnswerIndex >= 0) {
        checkSelectedAnswer();
        ui->nextQuestionButton->setText("Következő ➡");
        return;
    }

    if (answerSelected) {
        gameLogic.nextQuestion();
        displayQuestion();
    }
}

void MainWindow::onQuitQuiz()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Kilépés",
                                                              "Biztosan abbahagyod a kvízt? Az eredmények nem lesznek mentve.",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QaManager::logSystem("Felhasználó megszakította a kvízt.");
        showMainMenu();
    }
}

void MainWindow::onRestartSame()
{
    restartGame();
}

void MainWindow::onNextLevel()
{
    if (selectedDifficulty == Difficulty::Beginner) {
        selectedDifficulty = Difficulty::Intermediate;
    } else if (selectedDifficulty == Difficulty::Intermediate) {
        selectedDifficulty = Difficulty::Advanced;
    } else {
        QMessageBox::information(this, "Maximális szint", "Már a legmagasabb szinten vagy! 🏆");
        return;
    }

    QaManager::logSystem("Felhasználó szintet lépett: " + getDifficultyName(selectedDifficulty));
    restartGame();
}

// ============================================================================
// SIDEBAR
// ============================================================================

void MainWindow::onHomeClicked()
{
    showMainMenu();
}

void MainWindow::onLanguagesClicked()
{
    showLanguageSelectOnly();
}

void MainWindow::onStatsClicked()
{
    if (currentUserId == -1) {
        QMessageBox::warning(this, "Nincs belépés", "Előbb jelentkezz be!");
        return;
    }
    showStatisticsPage();
}
void MainWindow::onProfileClicked()
{
    showProfilePage();
}

void MainWindow::onLogoutClicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Kijelentkezés",
                                                              "Biztosan ki szeretnél jelentkezni?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QaManager::logSystem("Felhasználó kijelentkezett.");
        close();
    }
}

void MainWindow::onBackFromStatsClicked()
{
    showMainMenu();
}

// ============================================================================
// UI SEGÉDFÜGGVÉNYEK
// ============================================================================

void MainWindow::setupConnections()
{
    connect(ui->hungarianButton, &QPushButton::clicked, this, &MainWindow::onHungarianSelected);
    connect(ui->englishButton, &QPushButton::clicked, this, &MainWindow::onEnglishSelected);
    connect(ui->germanButton, &QPushButton::clicked, this, &MainWindow::onGermanSelected);
    connect(ui->russianButton, &QPushButton::clicked, this, &MainWindow::onRussianSelected);

    connect(ui->vocabularyButton, &QPushButton::clicked, this, &MainWindow::onVocabularySelected);
    connect(ui->grammarButton, &QPushButton::clicked, this, &MainWindow::onGrammarSelected);
    connect(ui->sentencesButton, &QPushButton::clicked, this, &MainWindow::onSentencesSelected);

    connect(ui->beginnerButton, &QPushButton::clicked, this, &MainWindow::onBeginnerSelected);
    connect(ui->intermediateButton, &QPushButton::clicked, this, &MainWindow::onIntermediateSelected);
    connect(ui->advancedButton, &QPushButton::clicked, this, &MainWindow::onAdvancedSelected);

    connect(ui->startQuizButton, &QPushButton::clicked, this, &MainWindow::onStartQuiz);
    connect(ui->backFromCategoryButton, &QPushButton::clicked, this, &MainWindow::onBackFromCategory);
    connect(ui->backToMenuButton, &QPushButton::clicked, this, &MainWindow::onBackToMenu);
    connect(ui->nextQuestionButton, &QPushButton::clicked, this, &MainWindow::onNextQuestion);
    connect(ui->quitQuizButton, &QPushButton::clicked, this, &MainWindow::onQuitQuiz);
    connect(ui->restartSameButton, &QPushButton::clicked, this, &MainWindow::onRestartSame);
    connect(ui->nextLevelButton, &QPushButton::clicked, this, &MainWindow::onNextLevel);
    connect(ui->backFromStatsButton, &QPushButton::clicked, this, &MainWindow::onBackFromStatsClicked);

    connect(ui->homeButton, &QPushButton::clicked, this, &MainWindow::onHomeClicked);
    connect(ui->languagesButton, &QPushButton::clicked, this, &MainWindow::onLanguagesClicked);
    connect(ui->statsButton, &QPushButton::clicked, this, &MainWindow::onStatsClicked);
    connect(ui->profileButton, &QPushButton::clicked, this, &MainWindow::onProfileClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &MainWindow::onLogoutClicked);
}

void MainWindow::createAnswerButtons(const Question &q)
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->answersWidget->layout());

    if (!layout) {
        layout = new QVBoxLayout(ui->answersWidget);
        layout->setSpacing(15);
        layout->setContentsMargins(0, 0, 0, 0);
    }

    for (int i = 0; i < q.answers.size(); i++) {
        QPushButton *btn = new QPushButton(q.answers[i], ui->answersWidget);
        btn->setMinimumHeight(60);
        btn->setMaximumHeight(60);
        btn->setCursor(Qt::PointingHandCursor);
        btn->setStyleSheet("QPushButton { background-color: white; color: #000000; "
                           "border: 2px solid #bdc3c7; border-radius: 10px; padding: 15px; "
                           "font-size: 16px; text-align: left; } "
                           "QPushButton:hover { background-color: #ecf0f1; border-color: #000000; }");

        connect(btn, &QPushButton::clicked, [this, i]() { handleAnswer(i); });

        layout->addWidget(btn);
        answerButtons.append(btn);
    }
}

void MainWindow::clearAnswerButtons()
{
    for (QPushButton *btn : answerButtons) {
        btn->deleteLater();
    }
    answerButtons.clear();
}

void MainWindow::updateQuestionCounter()
{
    int currentIdx = gameLogic.getCurrentQuestionIndex();
    int totalCount = gameLogic.getTotalQuestions();
    QString counterText = QString("Kérdés %1/%2").arg(currentIdx + 1).arg(totalCount);
    ui->questionNumberLabel->setText(counterText);
}

void MainWindow::updateCurrentScore()
{
    ui->currentScoreLabel->setText(QString("Pontszám: %1").arg(totalPoints));
}

// ============================================================================
// SZÖVEGEK ÉS IKONOK
// ============================================================================

QString MainWindow::getLanguageName(Language lang)
{
    switch (lang) {
    case Language::Hungarian: return "Magyar";
    case Language::English: return "English";
    case Language::German: return "Deutsch";
    case Language::Russian: return "Русский";
    default: return "Ismeretlen";
    }
}

QString MainWindow::getLanguageFlag(Language lang)
{
    switch (lang) {
    case Language::Hungarian: return "🇭🇺";
    case Language::English: return "🇬🇧";
    case Language::German: return "🇩🇪";
    case Language::Russian: return "🇷🇺";
    default: return "🌍";
    }
}

QString MainWindow::getCategoryName(Category cat)
{
    switch (cat) {
    case Category::Vocabulary: return "Szókincs";
    case Category::Grammar: return "Nyelvtan";
    case Category::Sentences: return "Mondatok";
    case Category::Listening: return "Hallás utáni";
    default: return "Ismeretlen";
    }
}

QString MainWindow::getCategoryIcon(Category cat)
{
    switch (cat) {
    case Category::Vocabulary: return "📖";
    case Category::Grammar: return "✏️";
    case Category::Sentences: return "💬";
    case Category::Listening: return "🎧";
    default: return "📚";
    }
}

QString MainWindow::getDifficultyName(Difficulty diff)
{
    switch (diff) {
    case Difficulty::Beginner: return "Kezdő";
    case Difficulty::Intermediate: return "Haladó";
    case Difficulty::Advanced: return "Profi";
    default: return "Ismeretlen";
    }
}

QString MainWindow::getDifficultyIcon(Difficulty diff)
{
    switch (diff) {
    case Difficulty::Beginner: return "🌱";
    case Difficulty::Intermediate: return "⭐";
    case Difficulty::Advanced: return "🏆";
    default: return "🎯";
    }
}

QString MainWindow::getMotivationalMessage(double accuracy)
{
    if (accuracy >= 90) return "Fantasztikus! Te egy nyelvzseni vagy! 🌟";
    if (accuracy >= 80) return "Nagyszerű munka! Így tovább! 👍";
    if (accuracy >= 70) return "Jó munka! Még egy kicsit és tökéletes leszel! 💪";
    if (accuracy >= 60) return "Szép teljesítmény! Folytasd a gyakorlást! 📚";
    if (accuracy >= 50) return "Jó kezdés! A gyakorlás teszi a mestert! 🎯";
    return "Ne add fel! Minden mester gyakorlással kezdte! 🚀";
}

// ============================================================================
// BACKEND
// ============================================================================

void MainWindow::loadQuestionsFromBackend()
{
    gameLogic.refreshQuestionPool(selectedCategory, selectedDifficulty);

    if (gameLogic.getTotalQuestions() == 0) {
        QMessageBox::warning(this, "Nincs kérdés",
                             "Ehhez a kombinációhoz még nincsenek kérdések az adatbázisban.");
        showMainMenu();
        return;
    }

    QaManager::logSystem("Backend: Kérdések betöltve, db: " + QString::number(gameLogic.getTotalQuestions()));
}

void MainWindow::sendAnswerToBackend(int answerIndex)
{
    QaManager::logSystem("Backend: Válasz elküldve (Index: " + QString::number(answerIndex) + ")");
}

void MainWindow::updateStatisticsInBackend()
{
    if (currentUserId == -1) return;
    DatabaseManager::instance().updateStreak(currentUserId);
    DatabaseManager::instance().saveUserScore(currentUserId, selectedLanguage,
                                              correctAnswers,
                                              gameLogic.getTotalQuestions(),
                                              totalPoints);
}

void MainWindow::loadDemoQuestions()
{
    gameLogic.refreshQuestionPool(selectedCategory, selectedDifficulty);
    QaManager::logSystem("Demo kérdések betöltése...");
}

void MainWindow::updateStatistics()
{
    QaManager::logSystem("Statisztika nézet frissítése.");
}

void MainWindow::showStatisticsPage()
{
    loadStatisticsFromBackend(); // Fejléc frissítése

    if (currentUserId == -1) {
        ui->stackedWidget->setCurrentWidget(ui->statisticsPage);
        return;
    }

    // Segédfüggvény a szöveg formázásához
    auto getStatText = [this](Language lang) -> QString {
        QPair<int, int> stats = DatabaseManager::instance().getStatsForLanguage(currentUserId, lang);
        int correct = stats.first;
        int total = stats.second;
        double percent = (total > 0) ? ((double)correct / total * 100.0) : 0.0;

        return QString("%1 szó").arg(correct).arg(QString::number(percent, 'f', 0));
    };

    // UI elemek frissítése
    ui->langStats1->setText(getStatText(Language::Hungarian));
    ui->langStats2->setText(getStatText(Language::English));
    ui->langStats3->setText(getStatText(Language::German));
    ui->langStats4->setText(getStatText(Language::Russian));

    ui->stackedWidget->setCurrentWidget(ui->statisticsPage);
}
