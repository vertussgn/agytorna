#include "testrunner.h"
#include "qamanager.h"
#include "databasemanager.h"
#include "gamelogic.h"
#include <QDebug>
#include <QCoreApplication>
#include <QFile>
#include <QDate>

void TestRunner::runAllTests()
{
    QaManager::logSystem("==========================================");
    QaManager::logSystem("=== AUTOMATIKUS QA TESZTEK INDÍTÁSA ===");
    QaManager::logSystem("==========================================");

    testDatabaseConnection();
    testLoggingSystem();
    testUserDatabaseOperations();
    testQuestionDataIntegrity();
    testGameLogicCalculation();
    testGameLogicSimulation();

    QaManager::logSystem("==========================================");
    QaManager::logSystem("=== MINDEN TESZT BEFEJEZŐDÖTT ===");
    QaManager::logSystem("==========================================");
}

// 1. ADATBÁZIS KAPCSOLAT
void TestRunner::testDatabaseConnection()
{
    bool isConnected = QaManager::verifyDatabaseConnection();
    if (isConnected) {
        QaManager::logSystem("[TESZT OK] Adatbázis kapcsolat aktív.");
    } else {
        QaManager::logSystem("[TESZT KRITIKUS HIBA] Adatbázis nem elérhető! A további tesztek bukhatnak.", true);
    }
}

// 2. NAPLÓZÓ RENDSZER
void TestRunner::testLoggingSystem()
{
    QString logPath = QCoreApplication::applicationDirPath() + "/system_log.txt";
    QFile file(logPath);

    if (file.exists()) {
        QaManager::logSystem("[TESZT OK] Log fájl (system_log.txt) fizikailag létezik.");
    } else {
        QaManager::logSystem("[TESZT HIBA] Log fájl nem található a mappában!", true);
    }
}

// 3. FELHASZNÁLÓ ÉS STATISZTIKA
void TestRunner::testUserDatabaseOperations()
{
    QString testUser = "QA_TEST_BOT";
    int userId = DatabaseManager::instance().getOrCreateUser(testUser);

    if (userId == -1) {
        QaManager::logSystem("[TESZT HIBA] Nem sikerült teszt felhasználót létrehozni!", true);
        return;
    }
    QaManager::logSystem(QString("[TESZT OK] Teszt felhasználó azonosítva (ID: %1).").arg(userId));

    bool saveSuccess = DatabaseManager::instance().saveUserScore(userId, Language::English, 5, 10, 50);

    if (saveSuccess) {
        QaManager::logSystem("[TESZT OK] Statisztika mentése sikeres.");
    } else {
        QaManager::logSystem("[TESZT HIBA] Statisztika mentése SQL hibát dobott!", true);
    }

    PlayerStats stats = DatabaseManager::instance().getPlayerStatistics(userId);
    if (stats.totalScore >= 50 && stats.totalQuestionsAnswered >= 10) {
        QaManager::logSystem("[TESZT OK] Statisztika visszaolvasása valid adatokkal.");
    } else {
        QaManager::logSystem("[TESZT HIBA] A visszaolvasott statisztika nem egyezik a mentettel!", true);
    }
}

// 4. ADAT INTEGRITÁS
void TestRunner::testQuestionDataIntegrity()
{
    QVector<Question> questions = DatabaseManager::instance().loadQuestions(
        Language::English, Category::Vocabulary, Difficulty::Beginner, 5
        );

    if (questions.isEmpty()) {
        QaManager::logSystem("[TESZT FIGYELMEZTETÉS] Üres az adatbázis kérdés táblája (vagy szűrési hiba).", true);
        return;
    }

    int errorCount = 0;
    for (const Question &q : questions) {
        if (q.questionText.isEmpty() || q.answers.size() != 4 || q.correctAnswer < 0 || q.correctAnswer > 3) {
            errorCount++;
            QaManager::logSystem(QString("[TESZT HIBA] Hibás kérdés adat ID: %1").arg(q.id), true);
        }
    }

    if (errorCount == 0) {
        QaManager::logSystem(QString("[TESZT OK] %1 kérdés ellenőrizve: Szerkezetileg mind helyes.").arg(questions.size()));
    }
}

// 5. JÁTÉK LOGIKA - MATEK
void TestRunner::testGameLogicCalculation()
{
    GameLogic logic;

    int s1 = logic.calculateScore(100, 20);
    if (s1 == 120) {
        QaManager::logSystem("[TESZT OK] Pontszámítás (100+20) helyes.");
    } else {
        QaManager::logSystem(QString("[TESZT HIBA] Pontszámítás rossz: 100+20 != %1").arg(s1), true);
    }

    // Extrém érték tesztelése a QA modulon keresztül
    QaManager::generateErrorReport(99999, 1000);
    QaManager::logSystem("[TESZT OK] QA Error Report modul válaszol.");
}

// 6. JÁTÉK LOGIKA - SZIMULÁCIÓ
void TestRunner::testGameLogicSimulation()
{
    GameLogic logic;

    logic.setLanguage(Language::English);
    logic.refreshQuestionPool(Category::Vocabulary, Difficulty::Beginner);

    if (logic.getTotalQuestions() == 0) {
        QaManager::logSystem("[TESZT SKIP] Nincs elég kérdés a játék szimulációhoz.");
        return;
    }

    const Question* q = logic.getCurrentQuestion();
    if (!q) {
        QaManager::logSystem("[TESZT HIBA] Játék indítás után nincs aktív kérdés!", true);
        return;
    }

    int correctIdx = q->correctAnswer;
    bool result = logic.checkAnswer(correctIdx);

    if (result) {
        QaManager::logSystem("[TESZT OK] Játék logikája elfogadta a helyes választ.");
    } else {
        QaManager::logSystem("[TESZT HIBA] Játék logikája elutasította a helyes választ!", true);
    }


#if defined(Q_COMPILER_MANGLES_RETURN_TYPE)
    int currentPoints = logic.getScore();
#else
    // Ha a getScore() sem létezne, de a currentScore public, akkor logic.currentScore
    // De a hibaüzenet szerint a getScore() létezik.
    int currentPoints = 0;
    // Megpróbáljuk a szabványos Qt getter mintát
    currentPoints = logic.getScore();
#endif

    if (currentPoints > 0) {
        QaManager::logSystem("[TESZT OK] Pontszám növekedett a helyes válasz után.");
    } else {
        QaManager::logSystem("[TESZT HIBA] Nem járt pont a helyes válaszért!", true);
    }

    logic.nextQuestion();
    if (logic.getCurrentQuestionIndex() == 1 || logic.isQuizFinished()) {
        QaManager::logSystem("[TESZT OK] Következő kérdésre lépés működik.");
    } else {
        QaManager::logSystem("[TESZT HIBA] nextQuestion() nem léptette az indexet megfelelően.", true);
    }
}
