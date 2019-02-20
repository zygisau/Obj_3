#include "header.h"
#include "functions.h"
#include "readFromFile.cpp"
#include "readFromUser.cpp"

void menu(vector<student>& students) {
    int numberOfStudents;

    cout << "Įvedinėsite duomenis ranka ar iš failo? (1 - ranka, 0 - iš failo)";
    int inputSelection;
    cin >> inputSelection;
    wasStringGivenInsteadInt(inputSelection);

    while (inputSelection != 1 && inputSelection != 0) { // Ar įvestis tinkama
        cout << "Įvestas skaičius neatitinka jokio pasirinkimo. Įvedinėsite duomenis ranka ar iš failo? (1 - ranka, 0 - iš failo) ";
        cin >> inputSelection;
        cout << endl;
    }

    if (inputSelection == 1) {
        cout << "Kiek studentų įvedinėsite: ";
        cin >> numberOfStudents;
        wasStringGivenInsteadInt(numberOfStudents);
        students.reserve((unsigned)numberOfStudents);
        readFromUser(numberOfStudents, students);
    } else {
        readFromFile(students);
    }
    cout << endl << "Press enter to continue ..." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}