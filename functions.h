#ifndef FUNCTIONS_H

#define FUNCTIONS_H

int checkGrade(string &param, const string& message);
void checkGradesCount(vector<student>& grades, const string& fname, const string& lname);
void compareStrings(int& base, const string& string);

bool sortByName(const student & stud1, const student & stud2);

void sortStudents(vector<student> & students);
void sortStudents(deque<student> & students);
void sortStudents(list<student> & students);

void printResult(vector<student>students, int maxString);

void filterStudents (vector<student>& students, vector<student>& vargsiukai);
void filterStudents(list<student>& students, list<student>& vargsiukai);
void filterStudents (deque<student>& students, deque<student>& vargsiukai);

void generateFile(string fileName, int size);

template < typename container >
void printToFile(container students, int maxString, string fileName);

#include "functions.cpp"

#endif