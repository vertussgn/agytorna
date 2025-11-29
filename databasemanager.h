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

    bool open(const QString &dbPath);
    bool isOpen() const;

    // --- Lukács Viktória (Adatbázis/Integráció) ---

    QVector<Question> loadQuestions(Language language,
                                    Category category,
                                    Difficulty difficulty,
                                    int limit);

    int getOrCreateUser(const QString &username);

    bool saveUserScore(
        int userId, Language language, int correctAnswers, int totalQuestions, int totalPoints);

    QStringList loadHighScores(int limit = 10);
    PlayerStats getPlayerStatistics(int userId);

private:
    DatabaseManager();
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
