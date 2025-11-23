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

    // 1. Véletlenszerű kérdés lekérése az adatbázisból (jelenleg memória)
    Question getRandomQuestion(Language lang, Category cat, Difficulty diff);

    // 2. Válasz ellenőrzése
    bool checkAnswer(const Question& question, int selectedAnswerIndex);

    // 3. Pontszám frissítése
    int calculateScore(int currentScore, int pointsToAdd);

    // ========================================================================
    // Kosztel Tamás
    // ========================================================================

    // 1. Nyelv beállítása
    void setLanguage(Language lang);

    // 2. Kerdéspool betöltése
    void loadLanguageData();

    // 3. Kérdések frissítése
    void refreshQuestionPool(Category cat, Difficulty diff);

    // 4. Kvíz navigáció
    const Question* getCurrentQuestion() const;
    void nextQuestion();
    int getTotalQuestions() const { return currentQuizQuestions.size(); }
    bool isQuizFinished() const;

    int getCurrentQuestionIndex() const { return currentQuestionIndex; }

private:
    // ========================================================================
    // Bányai Bence
    // ========================================================================
    // Ideiglenes adatbázis a teszteléshez (amíg Viktória el nem készül az SQL-lel)
    QVector<Question> mockDatabase;
    void initMockDatabase();

    // ========================================================================
    // Kosztel Tamás
    // ========================================================================
    QVector<Question> currentQuizQuestions; // A szűrt, aktuális kérdéssor
    int currentQuestionIndex = -1;

    // Aktuálisan kiválasztott beállítások tárolása
    Language currentLanguage;
    Category currentCategory;
    Difficulty currentDifficulty;

    // Segédfüggvény a szűrés logikájához
    QVector<Question> filterQuestions(Language lang, Category cat, Difficulty diff);

    Language selectedLanguage;
};

#endif // GAMELOGIC_H
