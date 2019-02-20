#ifndef FUNCTIONS_H

#define FUNCTIONS_H

void compareStrings(int& base, const string& string);
bool sortByName(const student & stud1, const student & stud2);
void sortStudents(vector<student>& students);
void printResult(vector<student>students, int maxString);

void compareStrings(int& base, const string& string) {
    if (base < string.size()) {
        base = string.size();
    }
}
bool sortByName(const student & stud1, const student & stud2) {
    return (stud1.name < stud2.name) ||
           ((stud1.name == stud2.name) && (stud1.surname > stud2.surname));
}
void sortStudents(vector<student>& students) {
    sort(students.begin(), students.end(), sortByName);
}
void printResult(vector<student>students, int maxString) {
    for (auto &student : students) {
        student.getGalutinis();
        float multiplier = student.getMedian();
        student.galutinisMedian = 0.4 * multiplier + 0.6 * student.exam;
    }
    cout << left << setw(maxString+20) << "Vardas" << setw(maxString+20) << "Pavardė" << setw(maxString+20) << "Galutinis (Vid.)" << setw(maxString+20) << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 4*(maxString+20); i++) cout << "-";
    cout << endl;
    sortStudents(students);
    for (auto &student : students) {
        cout << setw(maxString+20) << student.name << setw(maxString+20) << student.surname << setw(maxString+20) << setprecision(2) << fixed << student.galutinis << setw(maxString+20) << setprecision(2) << fixed << student.galutinisMedian << endl;
    }
}




#endif