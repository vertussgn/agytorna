#ifndef GAMETYPES_H
#define GAMETYPES_H

#include <QString>
#include <QVector>
#include <QStringList>

// --- ENUMOK (Kosztel Tamás / SQL) ---
enum class Language {
    Hungarian = 0,
    English = 1,
    German = 2,
    Russian = 3
};

enum class Category {
    Vocabulary = 0,
    Grammar = 1,
    Sentences = 2,
    Listening = 3
};

enum class Difficulty {
    Beginner = 0,
    Intermediate = 1,
    Advanced = 2
};

// --- STRUKTÚRÁK ---

// Kérdés (Bányai Bence / Kosztel Tamás)
struct Question {
    int id;
    QString questionText;
    QString word;
    QStringList answers;
    int correctAnswer;
    int points;
    
    Language language;
    Category category;
    Difficulty difficulty;
};

// Statisztika (Nagy Attila)
struct PlayerStats {
    int totalScore;
    int totalQuestionsAnswered;
    int correctAnswers;
    QString lastPlayedDate;
};

#endif // GAMETYPES_H