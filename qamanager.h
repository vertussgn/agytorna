#ifndef QAMANAGER_H
#define QAMANAGER_H

#include <QString>
#include <QDebug>
// Nincs szükség külön include-ra itt a fájlkezeléshez, mert az a cpp-ben lesz,
// de a QString és QDebug kell.

class QaManager
{
public:
    QaManager();

    // 1. feladat: SQLite kapcsolat vizsgálata
    static bool verifyDatabaseConnection();

    // 2. feladat: Pontozási hibák jelentése
    static void generateErrorReport(int currentScore, int maxPossibleScore);

    // 3. feladat: Futási hibák és állapotjelentések naplózása
    static void logSystem(const QString &message, bool isError = false);
};

#endif
