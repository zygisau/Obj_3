#ifndef FUNCTIONS_H

#define FUNCTIONS_H

void compareStrings(int& base, const string& string);
bool sortByName(const student & stud1, const student & stud2);
void sortStudents(vector<student>& students);
void printResult(vector<student>students, int maxString);

#include "functions.cpp"

#endif