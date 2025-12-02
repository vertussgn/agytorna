#ifndef QAMANAGER_H
#define QAMANAGER_H

#include <QDebug>
#include <QString>

class QaManager
{
public:
    QaManager();

    //SQLite kapcsolat vizsgálata
    static bool verifyDatabaseConnection();

    //Pontozási hibák jelentése
    static void generateErrorReport(int currentScore, int maxPossibleScore);

    //Futási hibák és állapotjelentések naplózása
    static void logSystem(const QString &message, bool isError = false);
};

#endif
