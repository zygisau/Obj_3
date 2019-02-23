#include "functions.h"

void readFromUser(const int numberOfStudents, vector<student>& students) {
    int maxString = 0; // Ilgiausia simbolių eilutė rezultatų spausdinimui
    for (int i=0; i<numberOfStudents; i++) { // Įrašinėja visų studentų duomenis
        students.push_back(student());

        cout << "Įveskite studento vardą: ";
        cin >> students[i].name;
        compareStrings(maxString, students[i].name); // Tikrinama įvestis, ieškomas ilgiausias žodis

        cout << "Įveskite studento pavardę: ";
        cin >> students[i].surname;
        compareStrings(maxString, students[i].surname);

        cout << "Ar norite, jog pažymiai būtų sugeneruoti už Jus? (1 - taip, 0 - ne) ";
        int isNeededToGenerate;
        cin >> isNeededToGenerate;
        wasStringGivenInsteadInt(isNeededToGenerate);

        while (isNeededToGenerate != 1 && isNeededToGenerate != 0) { // Ar įvestis tinkama
            cout << "Įvestas skaičius neatitinka jokio pasirinkimo. Ar norite, jog pažymiai būtų sugeneruoti už Jus? (1 - taip, 0 - ne) ";
            cin >> isNeededToGenerate;
            cout << endl;
        }

        if (isNeededToGenerate == 1) {
            students[i].generateGrades();
        } else {
            cout << "Įveskite pažymius. Įveskite ne skaičių, jog baigtumėte įrašymą." << endl;
            students[i].getGrades();

            cout << "Koks studento egzamino pažymys: ";
            cin >> students[i].exam;

            wasStringGivenInsteadInt(students[i].exam);

            while(students[i].exam > 10) {
                cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
                cout << "Pažymys: ";
                cin >> students[i].exam;
                wasStringGivenInsteadInt(students[i].exam);
            }
        }
        cout << endl;
    }
    for (auto &student : students) {
        student.getGalutinis();
    }
    cout << endl;
    printResult(students, maxString);
}