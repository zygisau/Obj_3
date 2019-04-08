#include "./classes/Student/Student.h"
#include "./classes/Timer/Timer.h"
#include "functions.h"

template < typename container >
void readFromFile(container students, container vargsiukai, const string& fileName, bool strat1) {
    Timer timer;
    ifstream fd (fileName);

    if (fd.fail()) {
        cout << "Įvyko klaida atidarant duomenų failą. Prašome įsitikinti, ar failas tinkamoje direktorijoje." << endl;
        exit(EXIT_FAILURE);
    }

    string info;
    int gradeInt, maxString = 0;
    string gradeStr, message;
    Student stud;

    std::getline(fd, info);

// Susižinome kiek pažymių gali būti daugiausiai faile
    std::istringstream reading(info);
    string testInfo;
    int gradesCount = -2;
    while(reading >> testInfo) { // einama, kol pasiekiamas eilutės galas
        gradesCount++;
    }
// Rezervuojame didžiausią galimą pažymių skaičių
    stud.reserveGrades(gradesCount);

    while (std::getline(fd, info)) { // Pagrindinis nuskaitymas
        std::istringstream reading(info);

        stud.setName(reading);
        compareStrings(maxString, stud.getName());

        stud.setSurname(reading);
        compareStrings(maxString, stud.getSurname());

        // Klaidos žinutė
        message = "Pažymys studentui " + stud.getName() + " " + stud.getSurname() + " neįrašytas. \nJei vykdote spartos analizę, ši klaida gali sugadinti rezultatus. Kad to išvengtumėte, rekomenduojame dar kartą patikrinti, ar duomenų faile nėra klaidų ir paleisti programą iš naujo. \n ARBA Įrašykite pažymį: ";

        while (!reading.eof()) { // kol nepasibaigs eilutė
            reading >> gradeStr;
            gradeInt = checkGrade(gradeStr, message);
            stud.pushBackGrades(gradeInt);
        }
        stud.checkGradesCount();

        stud.setExamFromGrades();

        students.push_back(stud); //emplace_back
//        Student *studentPtr = &students.back();
//        (*studentPtr).name = stud.name;
//        (*studentPtr).name = stud.surname;
//        (*studentPtr).galutinis = stud.galutinis;

//        students.push_back(stud); // ŠITIE VARIANTAI NEVEIKIA SU STD::LIST KONTEINERIU. NEĮRAŠO Į KONTEINERĮ NIEKO
//        students.insert(students.end(), stud);
        stud = {};
    }
    fd.close();
    cout << "Nuskaitymas iš failo truko: " << timer.elapsed() << " s" << endl;

    timer.reset();

    sortStudents(students);

    if (strat1) {
        container kietiakai;
        filterStudentsStrat1(students, vargsiukai, kietiakai);
        cout << "Studentų filtravimas (skirstymas) truko: " << timer.elapsed() << " s" << endl;

        timer.reset();
        printToFile(kietiakai, maxString, "kietuoliai.txt");
        printToFile(vargsiukai, maxString, "vargsiukai.txt");
        cout << "Įrašymas į failą truko: " << timer.elapsed() << " s" << endl;

        students.clear();
        kietiakai.clear();
        vargsiukai.clear();
    } else {
        filterStudents(students, vargsiukai);
        cout << "Studentų filtravimas (skirstymas) truko: " << timer.elapsed() << " s" << endl;

        timer.reset();
        printToFile(students, maxString, "kietuoliai.txt");
        printToFile(vargsiukai, maxString, "vargsiukai.txt");
        cout << "Įrašymas į failą truko: " << timer.elapsed() << " s" << endl;

        students.clear();
        vargsiukai.clear();
    }
}