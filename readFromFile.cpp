//#include "header.h"
#include "functions.h"

template < typename container >
void readFromFile(container students, container vargsiukai, const string& fileName) {
    Timer timer;
    ifstream fd (fileName);

    if (fd.fail()) {
        cout << "Įvyko klaida atidarant duomenų failą. Prašome įsitikinti, ar failas tinkamoje direktorijoje." << endl;
        exit(EXIT_FAILURE);
    }

    string info, fname, lname;;
    int ind = 0, gradeInt, maxString = 0;
    string gradeStr, message;
    std::getline(fd, info);

    while (std::getline(fd, info)) {
        std::istringstream reading(info);

        vector <int> grade;

        reading >> lname;
        compareStrings(maxString, fname);

        reading >> fname;
        compareStrings(maxString, lname);

        message = "Pažymys studentui " + fname + " " + lname + " neįrašytas. \nJei vykdote spartos analizę, ši klaida gali sugadinti rezultatus. Kad to išvengtumėte, rekomenduojame dar kartą patikrinti, ar duomenų faile nėra klaidų ir paleisti programą iš naujo. \n ARBA Įrašykite pažymį: ";

        while (!reading.eof()) {
            reading >> gradeStr;
            gradeInt = checkGrade(gradeStr, message);
            grade.push_back(gradeInt);
        }
        checkGradesCount(grade, fname, lname);
        students.push_back(student()); //emplace_back
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