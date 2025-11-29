#include "databasemanager.h"
#include <QDate>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

DatabaseManager &DatabaseManager::instance()
{
    static DatabaseManager inst;
    return inst;
}

DatabaseManager::DatabaseManager() {}

bool DatabaseManager::open(const QString &dbPath)
{
    if (m_db.isOpen())
        return true;

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbPath);

    if (!m_db.open()) {
        qDebug() << "Adatbázis megnyitási hiba:" << m_db.lastError().text();
        return false;
    }
    qDebug() << "SQLite megnyitva:" << dbPath;
    return true;
}

bool DatabaseManager::isOpen() const
{
    return m_db.isOpen();
}

// ITT VOLT A HIBA, EZT JAVÍTOTTUK:
QVector<Question> DatabaseManager::loadQuestions(Language language,
                                                 Category category,
                                                 Difficulty difficulty,
                                                 int limit)
{
    QVector<Question> list;
    if (!m_db.isOpen())
        return list;

    QSqlQuery q(m_db);

    // JAVÍTÁS: R"(...)" helyett sima stringeket használunk, összefűzve.
    // Így biztosan nem lesz gond a sortörésekkel vagy rejtett karakterekkel.
    q.prepare("SELECT id, question_text, word, answer_a, answer_b, answer_c, answer_d, "
              "correct_answer, points "
              "FROM questions "
              "WHERE language = :lang AND category = :cat AND difficulty = :diff "
              "ORDER BY RANDOM() LIMIT :limit");

    q.bindValue(":lang", static_cast<int>(language));
    q.bindValue(":cat", static_cast<int>(category));
    q.bindValue(":diff", static_cast<int>(difficulty));
    q.bindValue(":limit", limit);

    if (!q.exec()) {
        // Ha hiba van, részletesen kiírjuk a konzolra
        qDebug() << "------------------------------------------------";
        qDebug() << "LEKÉRDEZÉSI HIBA (loadQuestions)!";
        qDebug() << "Hibaüzenet:" << q.lastError().text();
        qDebug() << "------------------------------------------------";
        return list;
    }

    while (q.next()) {
        Question qu;
        qu.id = q.value(0).toInt();
        qu.questionText = q.value(1).toString();
        qu.word = q.value(2).toString();
        qu.answers = {q.value(3).toString(),
                      q.value(4).toString(),
                      q.value(5).toString(),
                      q.value(6).toString()};
        qu.correctAnswer = q.value(7).toInt();
        qu.points = q.value(8).toInt();
        qu.language = language;
        qu.category = category;
        qu.difficulty = difficulty;
        list.append(qu);
    }
    return list;
}

int DatabaseManager::getOrCreateUser(const QString &username)
{
    if (!m_db.isOpen())
        return -1;

    QSqlQuery q(m_db);
    q.prepare("SELECT id FROM users WHERE username = :u");
    q.bindValue(":u", username);
    q.exec();

    if (q.next())
        return q.value(0).toInt();

    QSqlQuery ins(m_db);
    ins.prepare("INSERT INTO users (username, password) VALUES (:u, 'default')");
    ins.bindValue(":u", username);

    if (!ins.exec())
        return -1;
    return ins.lastInsertId().toInt();
}

bool DatabaseManager::saveUserScore(
    int userId, Language language, int correctAnswers, int totalQuestions, int totalPoints)
{
    if (!m_db.isOpen())
        return false;
    QSqlQuery q(m_db);
    q.prepare("INSERT INTO user_scores (user_id, language, correct_answers, total_questions, "
              "total_points) VALUES (:uid, :lang, :ca, :tq, :tp)");
    q.bindValue(":uid", userId);
    q.bindValue(":lang", static_cast<int>(language));
    q.bindValue(":ca", correctAnswers);
    q.bindValue(":tq", totalQuestions);
    q.bindValue(":tp", totalPoints);
    return q.exec();
}

QStringList DatabaseManager::loadHighScores(int limit)
{
    QStringList results;
    if (!m_db.isOpen())
        return results;

    QSqlQuery q(m_db);
    q.prepare("SELECT u.username, SUM(s.total_points) as grand_total FROM user_scores s JOIN users "
              "u ON s.user_id = u.id GROUP BY u.id ORDER BY grand_total DESC LIMIT :limit");
    q.bindValue(":limit", limit);

    if (q.exec()) {
        int rank = 1;
        while (q.next()) {
            results.append(QString("%1. %2 - %3 pont")
                               .arg(rank++)
                               .arg(q.value(0).toString())
                               .arg(q.value(1).toInt()));
        }
    }
    return results;
}

PlayerStats DatabaseManager::getPlayerStatistics(int userId)
{
    PlayerStats stats = {0, 0, 0, "Még nem játszott"};
    if (!m_db.isOpen())
        return stats;

    QSqlQuery q(m_db);
    q.prepare("SELECT SUM(total_points), SUM(total_questions), SUM(correct_answers), "
              "MAX(played_at) FROM user_scores WHERE user_id = :uid");
    q.bindValue(":uid", userId);

    if (q.exec() && q.next() && !q.value(0).isNull()) {
        stats.totalScore = q.value(0).toInt();
        stats.totalQuestionsAnswered = q.value(1).toInt();
        stats.correctAnswers = q.value(2).toInt();
        stats.lastPlayedDate = q.value(3).toString();
    }
    return stats;
}
