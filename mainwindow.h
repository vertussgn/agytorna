#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QTimer>
#include <QVector>
#include "gamelogic.h"
#include "gametypes.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Oldalak megjelenítése
    void showMainMenu();
    void showLanguageSelectOnly();
    void showProfilePage();
    void showStatisticsPage();
    void showCategoryPage();

    // Kvíz funkciók
    void displayQuestion();
    void updateUIState();
    void showResults();
    void restartGame();
    void highlightAnswer(int answerIndex, bool isCorrect);
    void handleAnswer(int answerIndex);
    void checkSelectedAnswer();
    void showFeedback(bool isCorrect);
    void enableNextQuestion();

private slots:
    // Nyelvválasztó gombok
    void onHungarianSelected();
    void onEnglishSelected();
    void onGermanSelected();
    void onRussianSelected();

    // Kategória gombok
    void onVocabularySelected();
    void onGrammarSelected();
    void onSentencesSelected();
    void onListeningSelected();

    // Nehézségi szint gombok
    void onBeginnerSelected();
    void onIntermediateSelected();
    void onAdvancedSelected();

    // Navigációs gombok
    void onStartQuiz();
    void onBackFromCategory();
    void onBackToMenu();
    void onNextQuestion();
    void onQuitQuiz();
    void onRestartSame();
    void onNextLevel();

    // Sidebar gombok
    void onHomeClicked();
    void onLanguagesClicked();
    void onStatsClicked();
    void onProfileClicked();
    void onLogoutClicked();

    // Statisztika
    void onBackFromStatsClicked();

private:
    Ui::MainWindow *ui;
    GameLogic gameLogic;

    // Játék állapot változók
    QVector<Question> currentQuestions;
    QVector<Question> questions;
    int currentQuestionIndex;
    int correctAnswers;
    int totalPoints;
    bool answerSelected;
    int selectedAnswerIndex;

    // Kiválasztott beállítások
    Language selectedLanguage;
    Category selectedCategory;
    Difficulty selectedDifficulty;

    // Statisztika változók
    int currentStreak;
    int totalWordsLearned;

    // UI elemek
    QVector<QPushButton *> answerButtons;
    QPushButton *selectedCategoryButton;
    QPushButton *selectedDifficultyButton;

    // Segédfüggvények
    void setupConnections();
    void createAnswerButtons();
    void clearAnswerButtons();
    void updateQuestionCounter();
    void updateCurrentScore();
    void setMainMenuVisibility(bool showStats, bool showLanguages);

    // Kijelölés kezelő függvények
    void handleCategorySelection(QPushButton *button, Category category);
    void handleDifficultySelection(QPushButton *button, Difficulty difficulty);

    // UI szövegek
    QString getLanguageName(Language lang);
    QString getLanguageFlag(Language lang);
    QString getCategoryName(Category cat);
    QString getCategoryIcon(Category cat);
    QString getDifficultyName(Difficulty diff);
    QString getDifficultyIcon(Difficulty diff);
    QString getMotivationalMessage(double accuracy);

    // Backend interface
    void loadQuestionsFromBackend();
    void sendAnswerToBackend(int answerIndex);
    void updateStatisticsInBackend();
    void loadStatisticsFromBackend();
    void loadDemoQuestions();
    void updateStatistics();
    void filterQuestions();
};

#endif // MAINWINDOW_H
