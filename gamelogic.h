#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "gametypes.h"
#include <QVector>

class GameLogic
{
public:
    GameLogic();

    // --- Bányai Bence ---
    Question getRandomQuestion(Language lang, Category cat, Difficulty diff);
    bool checkAnswer(int selectedAnswerIndex); // JAVÍTVA: Csak index kell
    int calculateScore(int currentScore, int pointsToAdd);

    // --- Nagy Attila ---
    void updateStatistics(int userId);
    QString getPlayerStats(int userId);
    void resetGameData();
    int getScore() const { return currentScore; }

    // --- Kosztel Tamás ---
    void setLanguage(Language lang);
    void loadLanguageData();
    void refreshQuestionPool(Category cat, Difficulty diff);

    const Question* getCurrentQuestion() const;
    void nextQuestion();
    int getTotalQuestions() const { return currentQuizQuestions.size(); }
    int getCurrentQuestionIndex() const { return currentQuestionIndex; }
    bool isQuizFinished() const;

private:
    QVector<Question> currentQuizQuestions;
    int currentQuestionIndex;
    
    // Attila változói (ezek hiányoztak)
    int currentScore;
    int correctAnswersCount;

    Language currentLanguage;
    Category currentCategory;
    Difficulty currentDifficulty;
};

#endif // GAMELOGIC_H