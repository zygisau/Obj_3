//
// Created by zygisau on 01/04/2019.
//

#ifndef DUOMENU_APDOROJIMAS_STUDENT_H
#define DUOMENU_APDOROJIMAS_STUDENT_H

#include "../../includes.h"

// Funkcija, kurios reikia klasėje esančioms funkcijoms, taigi įdėta čia
void wasStringGivenInsteadInt(int &param);

class Student {
private:
    string name = "Vardenis";
    string surname = "Pavardenis";
    vector<int> grades;
    int exam=0;
    double galutinis=0; // Galutinis studento pažymys
    double galutinisMedian = 0;
    int numberOfGrades=0;
    bool vargsiukas=false;

public:
    Student() : name("Vardenis"), surname("Pavardenis"), exam(0), galutinis(0), galutinisMedian(0), numberOfGrades(0), vargsiukas(false) {}
    Student(const Student& stud) : name(stud.name), surname(stud.surname), grades(stud.grades), exam(stud.exam), galutinis(stud.galutinis), galutinisMedian(stud.galutinisMedian), numberOfGrades(stud.numberOfGrades), vargsiukas(stud.vargsiukas) {}
    ~Student() { grades.clear(); }
    // getters
    string getName() const { return name; }
    string getSurname() const { return surname; }
    double getGalutinis() const {return galutinis; }
    double getGalutinisMedian() const {return galutinisMedian; }
    int getNumberOfGrades() const {return numberOfGrades; }
    bool isVargsiukas() const { return vargsiukas; }
    // setters
    void setName( istream & stream ) { stream >> name; }
    void setSurname( istream & stream ) { stream >> surname; }
    void setExam( istream & stream );
    int getExam() const { return exam; }
    void reserveGrades( int & number) { grades.reserve(number); }
    void pushBackGrades( int & grade ) { grades.push_back(grade); }
    vector<int> getGrades() const { return grades; }

// Nustatomas egzamino pažymys, panaikinant
    void setExamFromGrades();

// Ar pažymių užtenka, nes paskutinis pažymys visada bus egzaminas
    void checkGradesCount();

// Per konsolę įrašomi pažymiai
    void setGrades();

// Apskaičiuoja vidurkį
    float setAverage();

// Apskaičiuoja medianą
    float setMedian();

// Apskaičiuoja abu galutinius pažymius
    void setGalutinis();

// Pažymių generavimas studentui
    void generateGrades();

// Operators overloading
    bool operator>(const Student& stud);
    bool operator<(const Student& stud);
    bool operator==(const Student& stud);
    bool operator!=(const Student& stud);
    bool operator>=(const Student& stud);
    bool operator<=(const Student& stud);
    Student& operator=(const Student& stud);
};

#endif //DUOMENU_APDOROJIMAS_STUDENT_H
