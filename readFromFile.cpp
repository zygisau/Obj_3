#include "functions.h"

void readFromFile(vector<student> students) {
    ifstream fd ("kursiokai.txt");
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

    students.shrink_to_fit();
    
    printResult(students, maxString);
}