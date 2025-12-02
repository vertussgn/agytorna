#include "qamanager.h"
#include "databasemanager.h"
#include <QDate>
#include <QTime>
#include <QFile>            // Fájlkezeléshez
#include <QTextStream>      // Szöveg írásához
#include <QCoreApplication> // Hogy megtaláljuk az exe melletti mappát

QaManager::QaManager() {}

// --- 1. SQLite kapcsolat ellenőrzése ---
bool QaManager::verifyDatabaseConnection()
{
    bool isOpen = DatabaseManager::instance().isOpen();

    if (isOpen) {
        logSystem("Adatbázis kapcsolat: AKTÍV és MEGFELELŐ.", false);
    } else {
        logSystem("KRITIKUS HIBA: Az adatbázis kapcsolat nem él!", true);
    }

    return isOpen;
}

// --- 2. Pontozási hibák jelentése ---
void QaManager::generateErrorReport(int currentScore, int maxPossibleScore)
{
    if (currentScore < 0) {
        logSystem(QString("PONTOZÁSI HIBA: A pontszám negatív! (%1)").arg(currentScore), true);
    }
    else if (currentScore > maxPossibleScore) {
        logSystem(QString("PONTOZÁSI HIBA: A pontszám meghaladja a maximumot! (%1 / %2)")
                      .arg(currentScore).arg(maxPossibleScore), true);
    }
    else {

    }
}

// --- 3. Naplózó rendszer (KONZOL + TXT) ---
void QaManager::logSystem(const QString &message, bool isError)
{
    // 1. Időbélyeg és formátum összeállítása
    QString timestamp = QDate::currentDate().toString("yyyy-MM-dd") + " " +
                        QTime::currentTime().toString("HH:mm:ss");

    QString prefix = isError ? "[HIBA]" : "[INFO]";
    QString finalLogMessage = QString("%1 %2: %3").arg(timestamp).arg(prefix).arg(message);

    // 2. Kiírás a KONZOLRA (megmaradt a régi működés)
    qDebug() << qPrintable(finalLogMessage);

    // 3. Kiírás a FÁJLBA
    // A fájl az exe mellett jön létre 'system_log.txt' néven
    QString logFilePath = QCoreApplication::applicationDirPath() + "/system_log.txt";
    QFile file(logFilePath);

    // Megnyitás: WriteOnly (írás), Append (hozzáfűzés), Text (sortörések kezelése)
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        // Beállítjuk a kódolást UTF-8-ra a magyar ékezetek miatt
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
        out.setEncoding(QStringConverter::Utf8);
#else
        out.setCodec("UTF-8");
#endif
        out << finalLogMessage << "\n"; // Sortörés a végére
        file.close();
    } else {
        // Ha nem sikerül írni a fájlba, jelezzük a konzolon (fallback)
        qDebug() << "[QA-SYSTEM] Nem sikerült megnyitni a log fájlt írásra:" << logFilePath;
    }
}
