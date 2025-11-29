#include "gamelogic.h"
#include <QDebug>
#include "databasemanager.h"

GameLogic::GameLogic()
{
    // Konstruktorban hívjuk a reset-et, ez inicializál mindent
    resetGameData();
    currentLanguage = Language::English;
}

// --- Bányai Bence ---

Question GameLogic::getRandomQuestion(Language lang, Category cat, Difficulty diff)
{
    QVector<Question> result = DatabaseManager::instance().loadQuestions(lang, cat, diff, 1);
    if (!result.isEmpty())
        return result.first();

    Question emptyQ;
    emptyQ.id = -1;
    emptyQ.questionText = "Hiba: Nincs kérdés";
    return emptyQ;
}

bool GameLogic::checkAnswer(int selectedAnswerIndex)
{
    const Question *q = getCurrentQuestion();
    if (!q)
        return false;

    bool isCorrect = (q->correctAnswer == selectedAnswerIndex);

    if (isCorrect) {
        currentScore += q->points;
        correctAnswersCount++;
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
    DatabaseManager::instance().saveUserScore(userId,
                                              currentLanguage,
                                              correctAnswersCount,
                                              currentQuizQuestions.size(),
                                              currentScore);
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

// --- Kosztel Tamás ---

void GameLogic::setLanguage(Language lang)
{
    currentLanguage = lang;
}

void GameLogic::loadLanguageData()
{ /* Opcionális */
}

void GameLogic::refreshQuestionPool(Category cat, Difficulty diff)
{
    resetGameData();
    currentCategory = cat;
    currentDifficulty = diff;

    currentQuizQuestions = DatabaseManager::instance().loadQuestions(currentLanguage, cat, diff, 10);

    if (!currentQuizQuestions.isEmpty())
        currentQuestionIndex = 0;
    else
        currentQuestionIndex = -1;
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
