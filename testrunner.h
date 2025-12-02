#ifndef TESTRUNNER_H
#define TESTRUNNER_H

#include <QString>

class TestRunner
{
public:
    // Ez a fő függvény, ami sorban meghívja az alteszteket
    static void runAllTests();

private:
    // --- 1. Rendszer és Adatbázis tesztek ---
    static void testDatabaseConnection();
    static void testLoggingSystem();
    static void testUserDatabaseOperations(); // ÚJ: User létrehozás és statisztika teszt

    // --- 2. Adat Integritás tesztek ---
    static void testQuestionDataIntegrity(); // Kérdések helyessége

    // --- 3. Játék Logika tesztek ---
    static void testGameLogicCalculation(); // Matek teszt
    static void testGameLogicSimulation();  // ÚJ: Egy teljes kör szimulálása (kérdés -> válasz -> pont)
};

#endif // TESTRUNNER_H
