#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager inst;
    return inst;
}

DatabaseManager::DatabaseManager() {}

bool DatabaseManager::open(const QString& dbPath)
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

QVector<Question> DatabaseManager::loadQuestions(
    Language language,
    Category category,
    Difficulty difficulty,
    int limit )
{
    QVector<Question> list;

    if (!m_db.isOpen())
        return list;

    QSqlQuery q(m_db);


    QString sql = "SELECT id, question_text, word, "
                  "answer_a, answer_b, answer_c, answer_d, "
                  "correct_answer, points "
                  "FROM questions "
                  "WHERE language = :lang "
                  "AND category = :cat "
                  "AND difficulty = :diff "
                  "ORDER BY RANDOM() "
                  "LIMIT :limit";

    if (!q.prepare(sql)) {
        qDebug() << "SQL Prepare hiba:" << q.lastError();
        return list;
    }

    qDebug() << "Parameterek:" << (int)language << (int)category << (int)difficulty << limit;

    // Paraméterek kötése
    q.bindValue(":lang", static_cast<int>(language));
    q.bindValue(":cat", static_cast<int>(category));
    q.bindValue(":diff", static_cast<int>(difficulty));
    q.bindValue(":limit", limit);

    if (!q.exec()) {
        qDebug() << "Kérdés lekérdezési hiba:" << q.lastError();
        return list;
    }

    while (q.next()) {
        Question qu;
        qu.id = q.value(0).toInt();
        qu.questionText = q.value(1).toString();
        qu.word = q.value(2).toString();
        qu.answers = {
            q.value(3).toString(),
            q.value(4).toString(),
            q.value(5).toString(),
            q.value(6).toString()
        };
        qu.correctAnswer = q.value(7).toInt();
        qu.points = q.value(8).toInt();

        qu.language = language;
        qu.category = category;
        qu.difficulty = difficulty;

        list.append(qu);
    }

    return list;
}

int DatabaseManager::getOrCreateUser(const QString& username)
{
    if (!m_db.isOpen())
        return -1;

    QSqlQuery q(m_db);
    q.prepare("SELECT id FROM users WHERE username = ?");
    q.addBindValue(username);
    q.exec();

    if (q.next())
        return q.value(0).toInt();

    QSqlQuery ins(m_db);
    ins.prepare("INSERT INTO users (username) VALUES (?)");
    ins.addBindValue(username);

    if (!ins.exec())
        return -1;

    return ins.lastInsertId().toInt();
}

bool DatabaseManager::saveUserScore(
    int userId,
    Language language,
    int correctAnswers,
    int totalQuestions,
    int totalPoints )
{
    if (!m_db.isOpen())
        return false;

    QSqlQuery q(m_db);
    q.prepare(R"(
        INSERT INTO user_scores
            (user_id, language, correct_answers, total_questions, total_points)
        VALUES
            (?, ?, ?, ?, ?)
    )");

    q.addBindValue(userId);
    q.addBindValue(static_cast<int>(language));
    q.addBindValue(correctAnswers);
    q.addBindValue(totalQuestions);
    q.addBindValue(totalPoints);

    return q.exec();
}
