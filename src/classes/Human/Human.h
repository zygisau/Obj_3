//
// Created by zygisau on 01/05/2019.
//

#ifndef DUOMENU_APDOROJIMAS_HUMAN_H
#define DUOMENU_APDOROJIMAS_HUMAN_H

#include "../../includes.h"

class Human {
protected:
    string name = "Vardenis";
    string surname = "Pavardenis";
    Human(const string inputName, const string inputSurname) : name(inputName), surname(inputSurname) {}
public:
    string getName() const { return name; }
    string getSurname() const { return surname; }
    void setName( istream & stream ) { stream >> name; }
    void setSurname( istream & stream ) { stream >> surname; }
};


#endif //DUOMENU_APDOROJIMAS_HUMAN_H
