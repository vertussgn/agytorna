#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include "databasemanager.h"
#include "mainwindow.h"
#include "qamanager.h"
#include "testrunner.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString dbPath = QCoreApplication::applicationDirPath() + "/agytorna.db";


    DatabaseManager::instance().open(dbPath);



    TestRunner::runAllTests();


    if (QaManager::verifyDatabaseConnection()) {
        // Ha a kapcsolat sikeres, a logSystem() függvényt használjuk
        QaManager::logSystem("--------------------------------------------------");
        QaManager::logSystem("SIKERES INDÍTÁS: Adatbázis kapcsolat aktív.");
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

    // A főablak megjelenítése
    MainWindow w;
    w.show();

    return a.exec();
}
