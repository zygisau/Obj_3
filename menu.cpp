#include "functions.h"
#include "readFromFile.h"
#include "readFromUser.h"
#include "speedTests.h"
#include "./classes/Student/Student.h"

void menu() {
    int numberOfStudents, inputSelection;

// Generavimas
    cout << "Ar reikia generuoti tekstinius failus \"kursiokaiXX.txt\"? (1 - taip, 0 - ne) ";
    cin >> inputSelection;
    wasStringGivenInsteadInt(inputSelection);
    checkIfBinary(inputSelection, "Ar reikia generuoti tekstinius failus \"kursiokaiXX.txt\"? (1 - taip, 0 - ne) ");

    if (inputSelection == 1) {
        cout << "Pradedama..." << endl;
        generateFile("kursiokai10.txt", 10);
        generateFile("kursiokai100.txt", 100);
        generateFile("kursiokai1000.txt", 1000);
        generateFile("kursiokai10000.txt", 10000);
        generateFile("kursiokai100000.txt", 100000);
        cout << endl;
    }

// Konteinerių analizė
    cout << "Ar norite atlikti konteinerių testavimą? (1 - taip, 0 - ne) ";
    cin >> inputSelection;
    wasStringGivenInsteadInt(inputSelection);
    checkIfBinary(inputSelection, "Ar norite atlikti konteinerių testavimą? (1 - taip, 0 - ne)");

    if (inputSelection == 1) {

// Įmanoma pasirinkti dvi strategijas. Pirma mažiau naši.
        cout << "Ar norite realizuoti dvi strategijas? Jei ne, bus naudojama tik antra strategija. (1-taip 0-ne): ";
        cin >> inputSelection;
        wasStringGivenInsteadInt(inputSelection);
        checkIfBinary(inputSelection, "Netinkama įvestis. Ar norite realizuoti dvi strategijas? Jei ne, bus naudojama tik antra strategija. (1-taip 0-ne): ");

        if (inputSelection == 1) {
            containerTestBadStrat();
            containerTest();
        } else  {
            containerTest();
        }
        cout << endl;

        cout << endl << "Press enter to continue ..." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
        exit(0);
    }

// Sukuriami pagrindiniai kintamieji
    vector<Student> students;
    vector<Student> vargsiukai;

// Ar bus pažymiai vedami ranka?
    cout << "Įvedinėsite duomenis ranka ar iš failo? (1 - ranka, 0 - iš failo)";
    cin >> inputSelection;
    wasStringGivenInsteadInt(inputSelection);
    checkIfBinary(inputSelection, "Įvestas skaičius neatitinka jokio pasirinkimo. Įvedinėsite duomenis ranka ar iš failo? (1 - ranka, 0 - iš failo) ");

    if (inputSelection == 1) {
        cout << "Kiek studentų įvedinėsite (didžiausia galima reikšmė - " << students.max_size() << "): ";
        cin >> numberOfStudents;
        wasStringGivenInsteadInt(numberOfStudents);

        try {
            students.reserve((unsigned)numberOfStudents);
        } catch (const std::length_error& error) {
            cout << "Parinktas per didelis dydis. Rezervuojama 30 studentų vietų..." << endl;
            students.reserve(30);
            numberOfStudents = 30;
        }

        readFromUser(numberOfStudents, students);

// Jei nebus ranka įrašomi pažymiai
    } else {

// Ar bus skaičiuojama std::vector sparta, dirbant su įvairiu skaičiumi studentų
        cout << "Ar norite atlikti programos veikimo greičio (spartos) analizę? (1 - taip, 0 - ne) ";
        cin >> inputSelection;
        wasStringGivenInsteadInt(inputSelection);
        checkIfBinary(inputSelection, "Ar norite atlikti programos veikimo greičio (spartos) analizę? (1 - taip, 0 - ne) ");

        if (inputSelection == 1) {
                speedTest(students, vargsiukai, false);
        } else {

// Jei nenorima atlikti jokios analiazės, tiesiog imamas kursiokai.txt failas ir daromi su juo skaičivimai.
            Timer clock;
            readFromFile(students, vargsiukai, "kursiokai.txt", false);
            cout << "Darbas su vektoriaus konteneiriu truko " << clock.elapsed() << " s" << endl;
        }
    }
    cout << endl << "Press enter to continue ..." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}