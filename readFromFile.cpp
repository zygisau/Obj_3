#include "functions.h"

template < typename container >
void readFromFile(container students, container vargsiukai, const string& fileName) {
    ifstream fd (fileName);
    students.reserve(30);

    string info;
    int ind = 0, grade, maxString = 0;
    std::getline(fd, info);

    while (std::getline(fd, info)) {
        std::istringstream reading(info);

        students.push_back(student()); //emplace_back

        reading >> students[ind].surname;
        compareStrings(maxString, students[ind].surname);

        reading >> students[ind].name;
        compareStrings(maxString, students[ind].name);

        while (reading) {
            reading >> grade;
            students[ind].grades.push_back(grade);
        }

        students[ind].exam = students[ind].grades.back();
        students[ind].grades.pop_back();
        students[ind].getGalutinis();

        ind++;
    }
    fd.close();

    students.shrink_to_fit();
    sortStudents(students);
    filterStudents(students, vargsiukai);

    printToFile(students, maxString, "kietuoliai.txt");
    printToFile(vargsiukai, maxString, "vargsiukai.txt");

    students.clear();
    vargsiukai.clear();
}