//#include "header.h"
#include "functions.h"

template < typename container >
void readFromFile(container students, container vargsiukai, const string& fileName) {
    Timer timer;
    ifstream fd (fileName);

    string info, fname, lname;;
    int ind = 0, gradeInt, maxString = 0;
    std::getline(fd, info);

    while (std::getline(fd, info)) {
        std::istringstream reading(info);

        vector <int> grade;

        reading >> fname;
        compareStrings(maxString, fname);

        reading >> lname;
        compareStrings(maxString, lname);

        while (reading) {
            reading >> gradeInt;
            grade.push_back(gradeInt);
        }
        students.push_back(student()); //emplace_back
//        auto<student>::iterator it = students.back();
        student *studentPtr = &students.back();
        (*studentPtr).name = lname;
        (*studentPtr).name = fname;
        (*studentPtr).exam = grade.back();
        grade.pop_back();
        (*studentPtr).grades = grade;
        (*studentPtr).getGalutinis();
        grade.clear();
        ind++;
    }
    fd.close();
    cout << "Nuskaitymas iš failo truko: " << timer.elapsed() << " s" << endl;
//    students.shrink_to_fit(); //
    timer.reset();
    sortStudents(students);
    filterStudents(students, vargsiukai);
    cout << "Studentų filtravimas (skirstymas) truko: " << timer.elapsed() << " s" << endl;

    timer.reset();
    printToFile(students, maxString, "kietuoliai.txt");
    printToFile(vargsiukai, maxString, "vargsiukai.txt");
    cout << "Įrašymas į failą truko: " << timer.elapsed() << " s" << endl;

    students.clear();
    vargsiukai.clear();
}