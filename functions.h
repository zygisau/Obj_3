#ifndef FUNCTIONS_H

#define FUNCTIONS_H

void speedTest(vector<student> students, vector<student> vargsiukai);
void compareStrings(int& base, const string& string);
bool sortByName(const student & stud1, const student & stud2);
void sortStudents(vector<student>& students);
void printResult(vector<student>students, int maxString);
void filterStudents(vector<student>& students, vector<student>& vargsiukai);
void generateFile(string fileName, int size);
void printToFile(vector<student>students, int maxString, string fileName);

#include "functions.cpp"

#endif