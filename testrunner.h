#ifndef TESTRUNNER_H
#define TESTRUNNER_H

#include <QString>

class TestRunner
{
public:
    static void runAllTests();

private:
    // --- Rendszer és Adatbázis tesztek ---
    static void testDatabaseConnection();
    static void testLoggingSystem();
    static void testUserDatabaseOperations();

    // --- Adat Integritás tesztek ---
    static void testQuestionDataIntegrity();

    // --- Játék Logika tesztek ---
    static void testGameLogicCalculation();
    static void testGameLogicSimulation();
};

#endif // TESTRUNNER_H
