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
    Student(const Student& stud) : Human(stud.name, stud.surname), grades(stud.grades), exam(stud.exam),
        galutinis(stud.galutinis), galutinisMedian(stud.galutinisMedian), numberOfGrades(stud.numberOfGrades), vargsiukas(stud.vargsiukas) {}
    Student(Student&& stud) noexcept : Human(stud.name, stud.surname), grades(stud.grades), exam(stud.exam),
        galutinis(stud.galutinis), galutinisMedian(stud.galutinisMedian), numberOfGrades(stud.numberOfGrades), vargsiukas(stud.vargsiukas) {}
    ~Student() { grades.clear(); }
    // getters
    double getGalutinis() const {return galutinis; }
    double getGalutinisMedian() const {return galutinisMedian; }
    int getNumberOfGrades() const {return numberOfGrades; }
    bool isVargsiukas() const { return vargsiukas; }
    vector<int> getGrades() const { return grades; }
    int getExam() const { return exam; }
    // setters
    void setExam( istream & stream );
    void setName(const string & name) { this->name = name; }
    void setSurname(const string & surname) { this->surname = surname; }
    void setVargsiukas(const bool & vargsiukasState) { vargsiukas = vargsiukasState; }
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
    void setGalutinis(const double & paz) { galutinis = paz; }
    void setGalutinisMedian(const double & paz) { galutinisMedian = paz; }

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
    Student& operator=(Student&& stud) noexcept;
};

#endif //DUOMENU_APDOROJIMAS_STUDENT_H
