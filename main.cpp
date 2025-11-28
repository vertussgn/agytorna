#include "mainwindow.h"
#include "databasemanager.h"
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString dbPath = QCoreApplication::applicationDirPath() + "/agytorna.db";


    if (DatabaseManager::instance().open(dbPath)) {
        qDebug() << "--------------------------------------------------";
        qDebug() << "SIKERES KAPCSOLAT!";
        qDebug() << "Adatbázis útvonala:" << dbPath;

        // Ellenőrizzük, hogy vannak-e táblák (ha üres a lista, rossz a fájl)
        QStringList tables = QSqlDatabase::database().tables();
        qDebug() << "Megtalált táblák:" << tables;
        qDebug() << "--------------------------------------------------";
    } else {
        qDebug() << "--------------------------------------------------";
        qDebug() << "HIBA! Nem sikerült megnyitni az adatbázist!";
        qDebug() << "Keresett útvonal:" << dbPath;
        qDebug() << "--------------------------------------------------";
    }

    MainWindow w;
    w.show();
    return a.exec();
}
