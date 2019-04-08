#ifndef FUNCTIONS_H

#define FUNCTIONS_H

#include "./classes/Student/Student.h"

int checkGrade(string &param, const string& message);
void compareStrings(int& base, const string& string);
void checkIfBinary (int& input, const string& message);

bool sortByName(const Student & stud1, const Student & stud2);

void sortStudents(vector<Student> & students);
void sortStudents(deque<Student> & students);
void sortStudents(list<Student> & students);

void printResult(vector<Student>students, int maxString);

void filterStudents (vector<Student>& students, vector<Student>& vargsiukai);
void filterStudents(list<Student>& students, list<Student>& vargsiukai);
void filterStudents (deque<Student>& students, deque<Student>& vargsiukai);

void filterStudentsStrat1 (list<Student>& students, list<Student>& vargsiukai, list<Student>& kietiakai);
void filterStudentsStrat1 (deque<Student>& students, deque<Student>& vargsiukai, deque<Student>& kietiakai);
void filterStudentsStrat1 (vector<Student>& students, vector<Student>& vargsiukai, vector<Student>& kietiakai);


void generateFile(string fileName, int size);

template < typename container >
void printToFile(const container & students, int maxString, string fileName);


#endif