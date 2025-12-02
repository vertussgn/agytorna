#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QStringList>
#include <QVector>
#include "gametypes.h"

class DatabaseManager
{
public:
    static DatabaseManager &instance();
    QPair<int, int> getStatsForLanguage(int userId, Language lang);

    bool open(const QString &dbPath);
    bool isOpen() const;

    // --- Lukács Viktória (Adatbázis/Integráció) ---

    QVector<Question> loadQuestions(Language language,
                                    Category category,
                                    Difficulty difficulty,
                                    int limit);

    int getOrCreateUser(const QString &username);
    int registerUser(const QString &username, const QString &password);
    int loginUser(const QString &username, const QString &password);
    User getUser(int userId);
    bool updateUsername(int userId, const QString &newUsername);
    bool updateStreak(int userId);
    int getTestCount(int userId);
    int getLearnedWords(int userId);

    bool saveUserScore(
        int userId, Language language, int correctAnswers, int totalQuestions, int totalPoints);

    QStringList loadHighScores(int limit = 10);
    PlayerStats getPlayerStatistics(int userId);

private:
    DatabaseManager();
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
