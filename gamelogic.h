#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "gametypes.h"
#include <QVector>

class GameLogic
{
public:
    // ========================================================================
    // Bányai Bence
    // ========================================================================
    GameLogic();

    // Véletlenszerű kérdés lekérése az adatbázisból (jelenleg memória)
    Question getRandomQuestion(Language lang, Category cat, Difficulty diff);

    // Válasz ellenőrzése
    bool checkAnswer(const Question& question, int selectedAnswerIndex);

    // Pontszám frissítése
    int calculateScore(int currentScore, int pointsToAdd);
};

#endif // GAMELOGIC_H
