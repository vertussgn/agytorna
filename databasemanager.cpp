#include "databasemanager.h"
#include "qamanager.h"
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
    if (m_db.isOpen()) return true;

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbPath);

    if (!m_db.open()) {
        QaManager::logSystem("Adatbázis megnyitási hiba: " + m_db.lastError().text(), true);
        return false;
    }

    QSqlQuery q(m_db);

    // Táblák alapvető létrehozása
    q.exec("CREATE TABLE IF NOT EXISTS users ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT, "
           "username TEXT UNIQUE, "
           "password TEXT, "
           "last_streak_date TEXT, "
           "streak_count INTEGER DEFAULT 0)");

    q.exec("CREATE TABLE IF NOT EXISTS user_scores ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT, "
           "user_id INTEGER, "
           "language INTEGER, "
           "correct_answers INTEGER, "
           "total_questions INTEGER, "
           "total_points INTEGER, "
           "played_at DATETIME DEFAULT CURRENT_TIMESTAMP, "
           "FOREIGN KEY(user_id) REFERENCES users(id))");

    q.exec("CREATE TABLE IF NOT EXISTS questions ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT, "
           "question_text TEXT, "
           "word TEXT, "
           "answer_a TEXT, "
           "answer_b TEXT, "
           "answer_c TEXT, "
           "answer_d TEXT, "
           "correct_answer INTEGER, "
           "points INTEGER, "
           "language INTEGER, "
           "category INTEGER, "
           "difficulty INTEGER)");

    //létezik-e a streak_count oszlop
    bool hasStreakCol = false;
    QSqlQuery check(m_db);
    check.exec("PRAGMA table_info(users)");
    while (check.next()) {
        if (check.value(1).toString() == "streak_count") {
            hasStreakCol = true;
        }
    }

    if (!hasStreakCol) {
        QaManager::logSystem("Adatbázis javítása: 'streak_count' oszlop hozzáadása...");
        if (!q.exec("ALTER TABLE users ADD COLUMN streak_count INTEGER DEFAULT 0")) {
            QaManager::logSystem("Hiba az oszlop pótlásakor: " + q.lastError().text(), true);
        }
        q.exec("ALTER TABLE users ADD COLUMN last_streak_date TEXT");
    }
    // ----------------------------------------------------

    QaManager::logSystem("SQLite adatbázis sikeresen megnyitva: " + dbPath);
    return true;
}

bool DatabaseManager::isOpen() const
{
    return m_db.isOpen();
}

QVector<Question> DatabaseManager::loadQuestions(Language language,
                                                 Category category,
                                                 Difficulty difficulty,
                                                 int limit)
{
    QVector<Question> list;
    if (!m_db.isOpen()) return list;

    QSqlQuery q(m_db);
    q.prepare("SELECT id, question_text, word, answer_a, answer_b, answer_c, answer_d, "
              "correct_answer, points "
              "FROM questions "
              "WHERE language = :lang AND category = :cat AND difficulty = :diff "
              "ORDER BY RANDOM() LIMIT :limit");

    q.bindValue(":lang", static_cast<int>(language));
    q.bindValue(":cat", static_cast<int>(category));
    q.bindValue(":diff", static_cast<int>(difficulty));
    q.bindValue(":limit", limit);

    if (q.exec()) {
        while (q.next()) {
            Question qu;
            qu.id = q.value(0).toInt();
            qu.questionText = q.value(1).toString();
            qu.word = q.value(2).toString();
            qu.answers = {q.value(3).toString(), q.value(4).toString(),
                          q.value(5).toString(), q.value(6).toString()};
            qu.correctAnswer = q.value(7).toInt();
            qu.points = q.value(8).toInt();
            qu.language = language;
            qu.category = category;
            qu.difficulty = difficulty;
            list.append(qu);
        }
    }
    return list;
}

int DatabaseManager::getOrCreateUser(const QString &username)
{
    if (!m_db.isOpen()) return -1;
    QSqlQuery q(m_db);
    q.prepare("SELECT id FROM users WHERE username = :u");
    q.bindValue(":u", username);
    q.exec();
    if (q.next()) return q.value(0).toInt();

    QSqlQuery ins(m_db);
    ins.prepare("INSERT INTO users (username, password, streak_count) VALUES (:u, 'default', 0)");
    ins.bindValue(":u", username);
    if (!ins.exec()) return -1;
    return ins.lastInsertId().toInt();
}

int DatabaseManager::registerUser(const QString &username, const QString &password)
{
    if (!m_db.isOpen()) return -1;

    QSqlQuery check(m_db);
    check.prepare("SELECT id FROM users WHERE username = :u");
    check.bindValue(":u", username);
    if (!check.exec()) {
        QaManager::logSystem("Ellenőrzési hiba: " + check.lastError().text(), true);
        return -1;
    }
    if (check.next()) return -2; // Foglalt név

    QSqlQuery ins(m_db);
    ins.prepare("INSERT INTO users (username, password, last_streak_date, streak_count) "
                "VALUES (:u, :p, date('now'), 1)");
    ins.bindValue(":u", username);
    ins.bindValue(":p", password);

    if (!ins.exec()) {
        QaManager::logSystem("Regisztrációs HIBA: " + ins.lastError().text(), true);
        return -1;
    }

    int newId = ins.lastInsertId().toInt();
    QaManager::logSystem("Sikeres regisztráció: " + username);
    return newId;
}

int DatabaseManager::loginUser(const QString &username, const QString &password)
{
    if (!m_db.isOpen()) return -1;
    QSqlQuery q(m_db);
    q.prepare("SELECT id FROM users WHERE username = :u AND password = :p");
    q.bindValue(":u", username);
    q.bindValue(":p", password);
    if (q.exec() && q.next()) return q.value(0).toInt();
    return -1;
}

User DatabaseManager::getUser(int userId)
{
    User u{};
    if (!m_db.isOpen()) return u;
    QSqlQuery q(m_db);
    q.prepare("SELECT username, last_streak_date, streak_count FROM users WHERE id = :id");
    q.bindValue(":id", userId);
    if (q.exec() && q.next()) {
        u.id = userId;
        u.username = q.value(0).toString();
        u.lastStreakDate = q.value(1).toString();
        u.streak = q.value(2).toInt();
    }
    return u;
}

bool DatabaseManager::updateUsername(int userId, const QString &newUsername)
{
    if (!m_db.isOpen()) return false;
    QSqlQuery q(m_db);
    q.prepare("UPDATE users SET username = :new WHERE id = :id");
    q.bindValue(":new", newUsername);
    q.bindValue(":id", userId);
    return q.exec();
}

bool DatabaseManager::updateStreak(int userId)
{
    if (!m_db.isOpen()) return false;
    QSqlQuery q(m_db);
    q.prepare("UPDATE users SET streak_count = streak_count + 1, last_streak_date = date('now') "
              "WHERE id = :id AND date(last_streak_date) < date('now')");
    q.bindValue(":id", userId);
    return q.exec();
}

int DatabaseManager::getTestCount(int userId)
{
    if (!m_db.isOpen()) return 0;
    QSqlQuery q(m_db);
    q.prepare("SELECT COUNT(*) FROM user_scores WHERE user_id = :id");
    q.bindValue(":id", userId);
    if (q.exec() && q.next()) return q.value(0).toInt();
    return 0;
}

int DatabaseManager::getLearnedWords(int userId)
{
    if (!m_db.isOpen()) return 0;
    QSqlQuery q(m_db);
    q.prepare("SELECT SUM(correct_answers) FROM user_scores WHERE user_id = :id");
    q.bindValue(":id", userId);
    if (q.exec() && q.next() && !q.value(0).isNull()) return q.value(0).toInt();
    return 0;
}

bool DatabaseManager::saveUserScore(int userId, Language language, int correctAnswers, int totalQuestions, int totalPoints)
{
    if (!m_db.isOpen()) return false;
    QSqlQuery q(m_db);
    q.prepare("INSERT INTO user_scores (user_id, language, correct_answers, total_questions, total_points) "
              "VALUES (:uid, :lang, :ca, :tq, :tp)");
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
    if (!m_db.isOpen()) return results;
    QSqlQuery q(m_db);
    q.prepare("SELECT u.username, SUM(s.total_points) as grand_total FROM user_scores s JOIN users u "
              "ON s.user_id = u.id GROUP BY u.id ORDER BY grand_total DESC LIMIT :limit");
    q.bindValue(":limit", limit);
    if (q.exec()) {
        int rank = 1;
        while (q.next()) {
            results.append(QString("%1. %2 - %3 pont").arg(rank++).arg(q.value(0).toString()).arg(q.value(1).toInt()));
        }
    }
    return results;
}

PlayerStats DatabaseManager::getPlayerStatistics(int userId)
{
    PlayerStats stats = {0, 0, 0, "Még nem játszott"};
    if (!m_db.isOpen()) return stats;
    QSqlQuery q(m_db);
    q.prepare("SELECT SUM(total_points), SUM(total_questions), SUM(correct_answers), MAX(played_at) "
              "FROM user_scores WHERE user_id = :uid");
    q.bindValue(":uid", userId);
    if (q.exec() && q.next() && !q.value(0).isNull()) {
        stats.totalScore = q.value(0).toInt();
        stats.totalQuestionsAnswered = q.value(1).toInt();
        stats.correctAnswers = q.value(2).toInt();
        stats.lastPlayedDate = q.value(3).toString();
    }
    return stats;
}

QPair<int, int> DatabaseManager::getStatsForLanguage(int userId, Language lang)
{
    QPair<int, int> result(0, 0);
    if (!m_db.isOpen()) return result;

    QSqlQuery q(m_db);
    // Összeadjuk a helyes válaszokat (correct_answers) és az összes kérdést (total_questions)
    q.prepare("SELECT SUM(correct_answers), SUM(total_questions) "
              "FROM user_scores WHERE user_id = :uid AND language = :lang");
    q.bindValue(":uid", userId);
    q.bindValue(":lang", static_cast<int>(lang));

    if (q.exec() && q.next()) {
        result.first = q.value(0).toInt();  // Helyes válaszok (megtanult szavak)
        result.second = q.value(1).toInt(); // Összes feltett kérdés
    }
    return result;
}
