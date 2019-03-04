#ifndef FUNCTIONS_H

#define FUNCTIONS_H

//void speedTest(vector<student> students, vector<student> vargsiukai);
void compareStrings(int& base, const string& string);

bool sortByName(const student & stud1, const student & stud2);

template < typename container >
void sortStudents(container& students);

void printResult(vector<student>students, int maxString);

template < typename container >
void filterStudents(container& students, container& vargsiukai);

void generateFile(string fileName, int size);

template < typename container >
void printToFile(container students, int maxString, string fileName);

#include "functions.cpp"

#endif