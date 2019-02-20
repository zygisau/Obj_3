#include "functions.h"

void readFromFile() {
    ifstream fd ("kursiokai.txt");
    string info;
    int ind = 0, grade;
    std::getline(fd, info);
    while (std::getline(fd, info)) {
        std::istringstream reading(info);
        students.push_back(student()); //emplace_back
        reading >> students[ind].surname;
        reading >> students[ind].name;
        while (reading) {
            reading >> grade;
            students[ind].grades.push_back(grade);
        }
        students[ind].exam = students[ind].grades.back();
        students[ind].grades.pop_back();
        students[ind].getGalutinis();
        ind++;
    }
    printResult();
}