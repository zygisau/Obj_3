//
// Created by zygisau on 01/04/2019.
//

#ifndef DUOMENU_APDOROJIMAS_STUDENT_H
#define DUOMENU_APDOROJIMAS_STUDENT_H

#include "../../includes.h"
#include "../Human/Human.h"

// Funkcija, kurios reikia klasėje esančioms funkcijoms, taigi įdėta čia
void wasStringGivenInsteadInt(int &param);

class Student : public Human {
private:
    vector<int> grades;
    int exam=0;
    double galutinis=0; // Galutinis studento pažymys
    double galutinisMedian = 0;
    int numberOfGrades=0;
    bool vargsiukas=false;

public:
    Student() : Human("Vardenis", "Pavardenis"), exam(0), galutinis(0), galutinisMedian(0), numberOfGrades(0), vargsiukas(false) {}
    Student(const Student& stud) : Human(stud.name, stud.surname), grades(stud.grades), exam(stud.exam), galutinis(stud.galutinis), galutinisMedian(stud.galutinisMedian), numberOfGrades(stud.numberOfGrades), vargsiukas(stud.vargsiukas) {}
    ~Student() { grades.clear(); }
    // getters
    double getGalutinis() const {return galutinis; }
    double getGalutinisMedian() const {return galutinisMedian; }
    int getNumberOfGrades() const {return numberOfGrades; }
    bool isVargsiukas() const { return vargsiukas; }
    vector<int> getGrades() const { return grades; }
    // setters
    void setExam( istream & stream );
    int getExam() const { return exam; }
    void reserveGrades( int & number) { grades.reserve(number); }
    void pushBackGrades( int & grade ) { grades.push_back(grade); }

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

// Operatorių persidengimas
    bool operator>(const Student& stud);
    bool operator<(const Student& stud);
    bool operator==(const Student& stud);
    bool operator!=(const Student& stud);
    bool operator>=(const Student& stud);
    bool operator<=(const Student& stud);
    Student& operator=(const Student& stud);
};

#endif //DUOMENU_APDOROJIMAS_STUDENT_H
