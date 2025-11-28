#include "gamelogic.h"
#include <QRandomGenerator>
#include "databasemanager.h"

// ========================================================================
// Bányai Bence
// =======================================================================

GameLogic::GameLogic()
{
}

Question GameLogic::getRandomQuestion(Language lang, Category cat, Difficulty diff)
{
    QVector<Question> result = DatabaseManager::instance().loadQuestions(lang, cat, diff, 1);

    if (result.isEmpty()) {
        // Ha nincs találat (pl. üres az adatbázis abban a kategóriában)
        Question emptyQ;
        emptyQ.id = -1;
        emptyQ.questionText = "Nincs elérhető kérdés az adatbázisban.";
        return emptyQ;
    }

    // Visszaadjuk a találati lista első (és egyetlen) elemét
    return result.first();
}

bool GameLogic::checkAnswer(const Question& question, int selectedAnswerIndex)
{
    // Index összehasonlítás
    return question.correctAnswer == selectedAnswerIndex;
}

int GameLogic::calculateScore(int currentScore, int pointsToAdd)
{
    // Pontszám növelése
    return currentScore + pointsToAdd;
}
