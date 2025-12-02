#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include "databasemanager.h"
#include "mainwindow.h"
#include "qamanager.h"
#include "testrunner.h"

// --- Páll László: Adatbázis kapcsolat inicializálása ---
bool connectToDatabase()
{
    QString dbPath = QCoreApplication::applicationDirPath() + "/agytorna.db";

    // Ez a függvény végzi a tényleges csatlakozást
    bool success = DatabaseManager::instance().open(dbPath);

    if (success) {
        // Ha a kapcsolat sikeres, a logSystem() függvényt használjuk
        QaManager::logSystem("--------------------------------------------------");
        QaManager::logSystem("SIKERES INDÍTÁS: Adatbázis kapcsolat aktív (connectToDatabase).");
        QaManager::logSystem("Adatbázis útvonala: " + dbPath);

        // Ellenőrizzük, hogy vannak-e táblák, és ezt is naplózzuk
        QStringList tables = QSqlDatabase::database().tables();
        QaManager::logSystem("Megtalált táblák az adatbázisban: " + tables.join(", "));
        QaManager::logSystem("--------------------------------------------------");
    } else {
        // Hiba esetén a logSystem hibajelző (true) paraméterét használjuk
        QaManager::logSystem("--------------------------------------------------", true);
        QaManager::logSystem("KRITIKUS HIBA! Nem sikerült megnyitni az adatbázist!", true);
        QaManager::logSystem("Keresett útvonal: " + dbPath, true);
        QaManager::logSystem("A program korlátozott módban fut tovább.", true);
        QaManager::logSystem("--------------------------------------------------", true);
    }

    return success;
}

// --- Páll László: A program belépési pontja ---
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. lépés: Kapcsolódás az adatbázishoz
    if (!connectToDatabase()) {
        qDebug() << "Adatbázis hiba, ellenőrizd a logokat!";
    }

    // Tesztek futtatása
    TestRunner::runAllTests();

    // 2. lépés: GUI komponensek beállítása
    MainWindow w;
    w.show();

    return a.exec();
}
