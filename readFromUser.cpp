#include "functions.h"
#include "./classes/Student/Student.h"

void readFromUser(const int numberOfStudents, vector<Student>& students) {
    int maxString = 0; // Ilgiausia simbolių eilutė rezultatų spausdinimui

    for (int i=0; i<numberOfStudents; i++) { // Įrašinėja visų studentų duomenis
        students.push_back(Student());

        cout << "Įveskite studento vardą: ";
        students[i].setName(cin);
        compareStrings(maxString, students[i].getName()); // Tikrinama įvestis, ieškomas ilgiausias žodis

        cout << "Įveskite studento pavardę: ";
        students[i].setSurname(cin);
        compareStrings(maxString, students[i].getSurname());

// Ar reikia generuoti studentui pažymius
        cout << "Ar norite, jog pažymiai būtų sugeneruoti už Jus? (1 - taip, 0 - ne) ";
        int isNeededToGenerate;
        cin >> isNeededToGenerate;
        wasStringGivenInsteadInt(isNeededToGenerate);
        checkIfBinary(isNeededToGenerate, "Įvestas skaičius neatitinka jokio pasirinkimo. Ar norite, jog pažymiai būtų sugeneruoti už Jus? (1 - taip, 0 - ne) ");

        if (isNeededToGenerate == 1) {
            students[i].generateGrades();
        } else {
            cout << "Įveskite pažymius. Įveskite ne skaičių, jog baigtumėte įrašymą." << endl;
            students[i].setGrades();

            cout << "Koks studento egzamino pažymys: ";
            students[i].setExam(cin);

        }

        students[i].setGalutinis();

        cout << endl;
    }

    cout << endl;
    printResult(students, maxString);
}