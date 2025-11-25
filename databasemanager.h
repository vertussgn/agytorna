#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QVector>
#include "gametypes.h"

class DatabaseManager
{
public:
    static DatabaseManager& instance();

    bool open(const QString& dbPath);
    bool isOpen() const;

    QVector<Question> loadQuestions(
        Language language,
        Category category,
        Difficulty difficulty,
        int limit
        );

    int getOrCreateUser(const QString& username);

    bool saveUserScore(
        int userId,
        Language language,
        int correctAnswers,
        int totalQuestions,
        int totalPoints
        );

private:
    DatabaseManager();
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
