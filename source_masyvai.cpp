#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
using std::cout; using std::cin; using std::endl; using std::string; using std::setw; using std::left; using std::setprecision; using std::fixed;
using std::sort; using std::stoi;
void wasStringGivenInsteadInt(int &param);
struct student {
    string name = "Vardas";
    string surname = "Pavardė";
    int *grades = nullptr;
    int exam=0;
    double galutinis=0;
    int numberOfGrades=0;
    void arrayPush (int *& array) {
        int *temp = new int[numberOfGrades + 6]; // Kadangi numberOfGrades indeksas, reik pridėt +5 ir +1
        for (int i = 0; i < numberOfGrades+1; i++) {
            temp [i] = array [i];
        }
        delete[] array;
        array = temp;
    }
    void getGrades() {
        grades = new int[5];
        string escKey;
        numberOfGrades = -1;
        while (escKey != "n") {
            numberOfGrades++;
            if (numberOfGrades%5 == 0 && numberOfGrades != 0) {
                arrayPush(grades);
            }
            cout << "Pažymys: ";
            cin >> grades[numberOfGrades];
            wasStringGivenInsteadInt(grades[numberOfGrades]);
            while(grades[numberOfGrades] > 10) {
                cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
                cout << "Pažymys: ";
                cin >> grades[numberOfGrades];
                wasStringGivenInsteadInt(grades[numberOfGrades]);
            }
            cout << "Paspauskite n, kad baigtumėte įrašyti pažymius, bet ką kitą, jei norite tęsti: ";
            cin >> escKey;
        }
        numberOfGrades++; // Šis parametras toliau naudojamas kaip masyvo elementų skaičius, kuris turi būti didesnis nei auksčiausias masyvo elementų indeksas
    }
    float getAverage() {
        int sum = 0;
        float average;
        for (int i=0; i<numberOfGrades; i++) {
            sum += grades[i];
        }
        average = (float)sum/numberOfGrades;
        return average;
    }
    float getMedian() {
        sort(grades, grades + numberOfGrades - 1);
        float median;
        int middleIndex = numberOfGrades/2;
        if (numberOfGrades % 2 == 0) {
            median = (float)(grades[middleIndex] + grades[--middleIndex])/2;
        } else {
            median = grades[--middleIndex];
        }
        return median;
    }
    void getGalutinis(const string& param) {
        float multiplier;
        if (param == "v" || param == "vi" || param == "vid") {
            multiplier = getAverage();
        } else {
            multiplier = getMedian();
        }
        galutinis = 0.4 * multiplier + 0.6 * exam;
    }
};
//
void wasStringGivenInsteadInt(int &param) {
    while (cin.fail()) {
        cout << "Parametras neįrašytas. Prašome pateikti teisingą parametrą: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> param;
    }
}
void compareStrings(int& base, string& string) {
    if (base < string.size()) {
        base = string.size();
    }
}
//
int main() {
    int maxString = 0;
    int sk;
    cout << "Kiek mokinių įvedinėsite: ";
    cin >> sk;
    wasStringGivenInsteadInt(sk);
    student *stud = new student[sk];
    for (int i=0; i<sk; i++) {
        cout << "Įveskite mokinio vardą: ";
        cin >> stud[i].name;
        compareStrings(maxString, stud[i].name);
        cout << "Įveskite mokinio pavardę: ";
        cin >> stud[i].surname;
        compareStrings(maxString, stud[i].surname);
        cout << "Įveskite pažymius" << endl;
        stud[i].getGrades();
        cout << "Koks mokinio egzamino pažymys: ";
        cin >> stud[i].exam;
        wasStringGivenInsteadInt(stud[i].exam);
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
    for (int i = 0; i < sk; i++) {
        stud[i].getGalutinis(choose);
    }
    cout << endl;

    if (choose == "v" || choose == "vi" || choose == "vid") {
        cout << left << setw(maxString+10) << "Vardas" << setw(maxString+10) << "Pavardė" << setw(maxString+10) << "Galutinis (Vid.)" << endl;
    } else {
        cout << left << setw(maxString+10) << "Vardas" << setw(maxString+10) << "Pavardė" << setw(maxString+10) << "Galutinis (Med.)" << endl;
    }
    for (int i = 0; i < 3*(maxString+10); i++) cout << "-";
    cout << endl;
    for (int i = 0; i < sk; i++) {
        cout << setw(maxString+10) << stud[i].name << setw(maxString+10) << stud[i].surname << setw(maxString+10) << setprecision(2) << fixed << stud[i].galutinis << endl;
    }
}