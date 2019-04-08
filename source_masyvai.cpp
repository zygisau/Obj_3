#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <random>
#include <ctime>
#include "./classes/Student/Student.h"

using std::cout; using std::cin; using std::endl; using std::string; using std::setw; using std::left; using std::setprecision; using std::fixed;
using std::sort; using std::stoi;

void compareStrings(int& base, string string) {
   if (base < string.size()) {
       base = string.size();
   }
}
void printResult (const string choose, const int maxString, const int numberOfStudents, const Student *stud) {
       if (choose == "v" || choose == "vi" || choose == "vid") {
           cout << left << setw(maxString+10) << "Vardas" << setw(maxString+10) << "Pavardė" << setw(maxString+10) << "Galutinis (Vid.)" << endl;
       } else {
           cout << left << setw(maxString+10) << "Vardas" << setw(maxString+10) << "Pavardė" << setw(maxString+10) << "Galutinis (Med.)" << endl;
       }
       for (int i = 0; i < 3*(maxString+10); i++) cout << "-";
       cout << endl;

       std::streamsize prec = cout.precision();

       for (int i = 0; i < numberOfStudents; i++) {
           cout << setw(maxString+10) << stud[i].getName()
           << setw(maxString+10) << stud[i].getSurname()
           << setw(maxString+10) << setprecision(2)
           << fixed << stud[i].getGalutinis() << setprecision(prec) << endl;
       }
}
//
int main() {
   int maxString = 0; // Ilgiausia simbolių eilutė rezultatų spausdinimui
   int numberOfStudents, isNeededToGenerate;
   cout << "Kiek studentų įvedinėsite: ";
   cin >> numberOfStudents;
   wasStringGivenInsteadInt(numberOfStudents);
   Student *stud = new Student[numberOfStudents];
   for (int i=0; i<numberOfStudents; i++) { // Įrašinėja visų studentų duomenis
       cout << "Įveskite studento vardą: ";
       stud[i].setName(cin);
       compareStrings(maxString, stud[i].getName()); // Tikrinama įvestis, ieškomas ilgiausias žodis
       cout << "Įveskite studento pavardę: ";
       stud[i].setSurname(cin);
       compareStrings(maxString, stud[i].getSurname());
       cout << "Ar norite, jog pažymiai būtų sugeneruoti už Jus? (1 - taip, 0 - ne) ";
       cin >> isNeededToGenerate;
       cout << endl;
       wasStringGivenInsteadInt(isNeededToGenerate);
       while (isNeededToGenerate != 1 && isNeededToGenerate != 0) { // Ar įvestis tinkama
           cout << "Įvestas skaičius neatitinka jokio pasirinkimo. Ar norite, jog pažymiai būtų sugeneruoti už Jus? (1 - taip, 0 - ne) ";
           cin >> isNeededToGenerate;
           cout << endl;
       }
       if (isNeededToGenerate == 1) {
           stud[i].generateGrades();
       } else {
           cout << "Įveskite pažymius" << endl;
           stud[i].setGrades();
           cout << "Koks studento egzamino pažymys: ";
           stud[i].setExam(cin);
           while(stud[i].getExam() > 10) {
               cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
               cout << "Pažymys: ";
               stud[i].setExam(cin);
           }
       }
   }
   cout << "Norite, jog galutinis pažymys būtų skaičiuojamas pagal vidurkį (vid) ar medianą (med)? ";
   string choose;
   cin >> choose;
   while (choose !="v" && choose != "vi" && choose != "vid" && choose != "m" && choose != "me" && choose != "med") {
       cout << choose << endl;
       cout << "Netinkamas parametras. Norite, jog galutinis pažymys būtų skaičiuojamas pagal vidurkį (vid) ar medianą (med)?";
       cin.clear();
       cin.ignore();
       cin >> choose;
   }
   for (int i = 0; i < numberOfStudents; i++) {
       stud[i].setGalutinis();
   }
   cout << endl;
   // Spausdinimas
   printResult(choose, maxString, numberOfStudents, stud);
   cout << "Press enter to continue ..." << endl;
   cin.get();
   return 0;
}