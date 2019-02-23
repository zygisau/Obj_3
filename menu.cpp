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
        readFromFile(students);
    }
    cout << endl << "Press enter to continue ..." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}