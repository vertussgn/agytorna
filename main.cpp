#include "mainwindow.h"

#include <QApplication>

#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!DatabaseManager::instance().open("agytorna.db")) {

    }
    MainWindow w;
    w.show();
    return a.exec();

}
