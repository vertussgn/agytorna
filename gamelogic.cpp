#include "gamelogic.h"
#include <QDebug>
#include "databasemanager.h"
#include "qamanager.h" // ÚJ: QA modul importálása

GameLogic::GameLogic()
{
    // Konstruktorban hívjuk a reset-et, ez inicializál mindent
    resetGameData();
    currentLanguage = Language::English;

    // QA: Naplózzuk az inicializálást
    QaManager::logSystem("GameLogic példányosítva, adatok alaphelyzetben.");
}

// --- Bányai Bence ---

Question GameLogic::getRandomQuestion(Language lang, Category cat, Difficulty diff)
{
    QVector<Question> result = DatabaseManager::instance().loadQuestions(lang, cat, diff, 1);
    if (!result.isEmpty()) {
        return result.first();
    }

    // QA: Ha nincs kérdés, ez kritikus hiba, amit naplózni kell
    QaManager::logSystem("HIBA: getRandomQuestion üres listát kapott!", true);

    Question emptyQ;
    emptyQ.id = -1;
    emptyQ.questionText = "Hiba: Nincs kérdés";
    return emptyQ;
}

bool GameLogic::checkAnswer(int selectedAnswerIndex)
{
    const Question *q = getCurrentQuestion();
    if (!q) {
        QaManager::logSystem("HIBA: checkAnswer hívás érvénytelen kérdésnél!", true);
        return false;
    }

    bool isCorrect = (q->correctAnswer == selectedAnswerIndex);

    if (isCorrect) {
        currentScore += q->points;
        correctAnswersCount++;


        QaManager::generateErrorReport(currentScore, 1000);

        QaManager::logSystem(QString("Helyes válasz! Új pontszám: %1").arg(currentScore));
    } else {
        QaManager::logSystem("Helytelen válasz.", false);
    }

    return isCorrect;
}

int GameLogic::calculateScore(int currentScore, int pointsToAdd)
{
    return currentScore + pointsToAdd;
}

// --- Nagy Attila ---

void GameLogic::updateStatistics(int userId)
{
    bool success = DatabaseManager::instance().saveUserScore(userId,
                                                             currentLanguage,
                                                             correctAnswersCount,
                                                             currentQuizQuestions.size(),
                                                             currentScore);

    if(success) {
        QaManager::logSystem(QString("Statisztika mentve UserID: %1 részére.").arg(userId));
    } else {
        QaManager::logSystem(QString("HIBA a statisztika mentésekor UserID: %1 részére!").arg(userId), true);
    }
}

QString GameLogic::getPlayerStats(int userId)
{
    PlayerStats stats = DatabaseManager::instance().getPlayerStatistics(userId);

    return QString("Összpontszám: %1\nMegválaszolt: %2\nHelyes: %3\nUtoljára: %4")
        .arg(stats.totalScore)
        .arg(stats.totalQuestionsAnswered)
        .arg(stats.correctAnswers)
        .arg(stats.lastPlayedDate);
}

void GameLogic::resetGameData()
{
    currentScore = 0;
    correctAnswersCount = 0;
    currentQuestionIndex = -1;
    currentQuizQuestions.clear();
}


void GameLogic::setLanguage(Language lang)
{
    currentLanguage = lang;
    QaManager::logSystem("Nyelv beállítva: " + QString::number((int)lang));
}

void GameLogic::loadLanguageData()
{ /* Opcionális */
}

void GameLogic::refreshQuestionPool(Category cat, Difficulty diff)
{
    // QA: Mielőtt lekérdezzük, ellenőrizzük a kapcsolatot (biztonsági játék)
    if (!QaManager::verifyDatabaseConnection()) {
        QaManager::logSystem("Nem lehet frissíteni a kérdéseket: Nincs adatbázis kapcsolat!", true);
        return;
    }

    resetGameData();
    currentCategory = cat;
    currentDifficulty = diff;

    QaManager::logSystem("Kérdések betöltése adatbázisból...");
    currentQuizQuestions = DatabaseManager::instance().loadQuestions(currentLanguage, cat, diff, 10);

    if (!currentQuizQuestions.isEmpty()) {
        currentQuestionIndex = 0;
        QaManager::logSystem(QString("Siker! %1 kérdés betöltve.").arg(currentQuizQuestions.size()));
    }
    else {
        currentQuestionIndex = -1;
        QaManager::logSystem("FIGYELEM: Nem érkezett kérdés a megadott paraméterekkel.", true);
    }
}

const Question *GameLogic::getCurrentQuestion() const
{
    if (currentQuestionIndex >= 0 && currentQuestionIndex < currentQuizQuestions.size()) {
        return &currentQuizQuestions[currentQuestionIndex];
    }
    return nullptr;
}

void GameLogic::nextQuestion()
{
    if (currentQuestionIndex < currentQuizQuestions.size())
        currentQuestionIndex++;
}

bool GameLogic::isQuizFinished() const
{
    if (currentQuestionIndex == -1)
        return true;
    return currentQuestionIndex >= currentQuizQuestions.size();
}
