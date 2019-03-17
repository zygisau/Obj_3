#include "header.h"
#include "functions.h"
#include "readFromFile.cpp"
#include "readFromUser.cpp"
//
template < typename container >
void speedTest(container & students, container & vargsiukai, bool strat1) {
    cout.flush();
    Timer t;
    readFromFile(students, vargsiukai, "kursiokai10.txt", strat1);
    cout << "Darbas su \"kursiokai10.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai100.txt", strat1);
    cout << "Darbas su \"kursiokai100.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai1000.txt", strat1);
    cout << "Darbas su \"kursiokai1000.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai10000.txt", strat1);
    cout << "Darbas su \"kursiokai10000.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai100000.txt", strat1);
    cout << "Darbas su \"kursiokai100000.txt\" užtruko: " << t.elapsed() << " s" << endl;
}

void containerTest() {
    cout << "Startegija 2" << endl << endl;

    cout << "Pradedamas darbas naudojant vector konteinerį..." << endl;
    Timer t;
    vector<student> students;
    vector<student> vargsiukai;
    speedTest(students, vargsiukai, false);
    cout << "Darbas su STD::VECTOR konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    cout << "Pradedamas darbas naudojant list konteinerį..." << endl;
    t.reset();
    list<student> studentsList;
    list<student> vargsiukaiList;
    speedTest(studentsList, vargsiukaiList, false);
    cout << "Darbas su STD::LIST konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    cout << "Pradedamas darbas naudojant deque konteinerį..." << endl;
    t.reset();
    deque<student> studentsDeque;
    deque<student> vargsiukaiDeque;
    speedTest(studentsDeque, vargsiukaiDeque, false);
    cout << "Darbas su STD::DEQUE konteineriu užtruko: " << t.elapsed() << " s" << endl;
}

void containerTestBadStrat() {
    cout << "Startegija 1" << endl << endl;

    cout << "Pradedamas darbas naudojant vector konteinerį..." << endl;
    Timer t;
    vector<student> students;
    vector<student> vargsiukai;
    speedTest(students, vargsiukai, true);
    cout << "Darbas su STD::VECTOR konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    cout << "Pradedamas darbas naudojant list konteinerį..." << endl;
    t.reset();
    list<student> studentsList;
    list<student> vargsiukaiList;
    speedTest(studentsList, vargsiukaiList, true);
    cout << "Darbas su STD::LIST konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    cout << "Pradedamas darbas naudojant deque konteinerį..." << endl;
    t.reset();
    deque<student> studentsDeque;
    deque<student> vargsiukaiDeque;
    speedTest(studentsDeque, vargsiukaiDeque, true);
    cout << "Darbas su STD::DEQUE konteineriu užtruko: " << t.elapsed() << " s" << endl;
}
//
void menu() {
    int numberOfStudents, inputSelection;

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

    cout << "Ar norite atlikti konteinerių testavimą? (1 - taip, 0 - ne) ";
    cin >> inputSelection;
    wasStringGivenInsteadInt(inputSelection);
    checkIfBinary(inputSelection, "Ar norite atlikti konteinerių testavimą? (1 - taip, 0 - ne)");

    if (inputSelection == 1) {
        containerTest();
        cout << endl;
        exit(0);
    }

    vector<student> students;
    vector<student> vargsiukai;

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
    } else {
        cout << "Ar norite atlikti programos veikimo greičio (spartos) analizę? (1 - taip, 0 - ne) ";
        cin >> inputSelection;
        wasStringGivenInsteadInt(inputSelection);
        checkIfBinary(inputSelection, "Ar norite atlikti programos veikimo greičio (spartos) analizę? (1 - taip, 0 - ne) ");

        if (inputSelection == 1) {
            cout << "Ar norite realizuoti dvi strategijas? Jei ne, bus naudojama tik antra strategija. (1-taip 2-ne): ";
            cin >> inputSelection;
            wasStringGivenInsteadInt(inputSelection);
            checkIfBinary(inputSelection, "Netinkama įvestis. Ar norite realizuoti dvi strategijas? Jei ne, bus naudojama tik antra strategija. (1-taip 2-ne): ");

            if (inputSelection == 1) {
                containerTestBadStrat();
                containerTest();
            } else  {
                speedTest(students, vargsiukai, false);
            }
        } else {
            Timer clock;
            readFromFile(students, vargsiukai, "kursiokai100000.txt", false);
            cout << "Darbas su vektoriaus konteneiriu truko " << clock.elapsed() << " s" << endl;
        }
    }
    cout << endl << "Press enter to continue ..." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}