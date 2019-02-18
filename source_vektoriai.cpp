#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>
using std::cout; using std::cin; using std::endl; using std::string; using std::setw; using std::left; using std::setprecision; using std::fixed;
using std::sort; using std::stoi; using std::vector; using std::ifstream;
void wasStringGivenInsteadInt(int &param);
struct student {
    string name = "Vardenis";
    string surname = "Pavardenis";
    vector<int> grades;
    int exam=0;
    double galutinis=0; // Galutinis studento pažymys
    double galutinisMedian = 0;
    int numberOfGrades=0;

    void getGrades() {
        grades.reserve(5);
        int input;
        cout << "Pažymys: ";
        cin >> input;
        numberOfGrades = -1;
        while (cin.good()) { // Ciklas, kol nebus įvestas simbolis n ir baigtas studentų įrašymas
            while(input > 10) {
                cout << "Parametras neįrašytas. Prašome pateikti teisingą parametrą: " << endl;
                cout << "Pažymys: ";
                cin >> input;
            }
            numberOfGrades++;
            grades.push_back(input);
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Pažymys: ";
            cin >> input;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        numberOfGrades++; // Šis kintamasis toliau naudojamas kaip masyvo elementų skaičius, kuris turi būti didesnis nei auksčiausias masyvo elementų indeksas
    }
    float getAverage() {
        int sum = 0;
        float average;
        for ( auto &grade : grades) { // pereina per kiekvieną pažymį
            sum += grade;
        }
        average = (float)sum/grades.size();
        return average;
    }
    float getMedian() {
        sort(grades.begin(), grades.end());
        float median;
        int middleIndex = (double) grades.size()/2;
        if (grades.size() == 1) {
            median = grades[0];
        } else if (grades.size() % 2 == 0) {
            median = (float)(grades[middleIndex] + grades[--middleIndex])/2;
        } else {
            median = grades[--middleIndex];
        }
        return median;
    }
    void getGalutinis() {
        float multiplier;
        multiplier = getAverage();
        galutinis = 0.4 * multiplier + 0.6 * exam;
        multiplier = getMedian();
        galutinisMedian = 0.4 * multiplier + 0.6 * exam;
    }
    void generateGrades() {
        cout << "Kiek pažymių generuoti? ";
        cin >> numberOfGrades;
        wasStringGivenInsteadInt(numberOfGrades);
        grades.reserve(numberOfGrades);
        const unsigned int seed = time(0);
        std::mt19937_64 rng(seed);
        std::uniform_int_distribution<> random(1, 10);
        for (int i=0; i<numberOfGrades; i++) { // pereina per kiekvieną pažymį
            grades.push_back(random(rng));
//            cout << grades[i] << " ";
        }
//        cout << endl;
        exam = random(rng);
    }
};
// Globalūs kintamieji
vector<student> students;
int maxString = 0; // Ilgiausia simbolių eilutė rezultatų spausdinimui
// Funkcijos
void wasStringGivenInsteadInt(int &param) {
    while (cin.fail()) { // ciklas, kol bus įvestas skaičius
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
bool sortByName(const student & stud1, const student & stud2) {
    return (stud1.name < stud2.name) ||
           ((stud1.name == stud2.name) && (stud1.surname > stud2.surname));
}
void sortStudents() {
    sort(students.begin(), students.end(), sortByName);
}
void printResult() {
    for (auto &student : students) {
        student.getGalutinis();
        float multiplier = student.getMedian();
        student.galutinisMedian = 0.4 * multiplier + 0.6 * student.exam;
    }
    cout << left << setw(maxString+20) << "Vardas" << setw(maxString+20) << "Pavardė" << setw(maxString+20) << "Galutinis (Vid.)" << setw(maxString+20) << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 4*(maxString+20); i++) cout << "-";
    cout << endl;
    sortStudents();
    for (auto &student : students) {
        cout << setw(maxString+20) << student.name << setw(maxString+20) << student.surname << setw(maxString+20) << setprecision(2) << fixed << student.galutinis << setw(maxString+20) << setprecision(2) << fixed << student.galutinisMedian << endl;
    }
}
void readFromUser(const int numberOfStudents) {
    for (int i=0; i<numberOfStudents; i++) { // Įrašinėja visų studentų duomenis
        students.push_back(student());
        cout << "Įveskite studento vardą: ";
        cin >> students[i].name;
        compareStrings(maxString, students[i].name); // Tikrinama įvestis, ieškomas ilgiausias žodis
        cout << "Įveskite studento pavardę: ";
        cin >> students[i].surname;
        compareStrings(maxString, students[i].surname);
        cout << "Ar norite, jog pažymiai būtų sugeneruoti už Jus? (1 - taip, 0 - ne) ";
        int isNeededToGenerate;
        cin >> isNeededToGenerate;
        wasStringGivenInsteadInt(isNeededToGenerate);
        while (isNeededToGenerate != 1 && isNeededToGenerate != 0) { // Ar įvestis tinkama
            cout << "Įvestas skaičius neatitinka jokio pasirinkimo. Ar norite, jog pažymiai būtų sugeneruoti už Jus? (1 - taip, 0 - ne) ";
            cin >> isNeededToGenerate;
            cout << endl;
        }
        if (isNeededToGenerate == 1) {
            students[i].generateGrades();
        } else {
            cout << "Įveskite pažymius. Įveskite ne skaičių, jog baigtumėte įrašymą." << endl;
            students[i].getGrades();
            cout << "Koks studento egzamino pažymys: ";
            cin >> students[i].exam;
            wasStringGivenInsteadInt(students[i].exam);
            while(students[i].exam > 10) {
                cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
                cout << "Pažymys: ";
                cin >> students[i].exam;
                wasStringGivenInsteadInt(students[i].exam);
            }
        }
        cout << endl;
    }
    for (auto &student : students) {
        student.getGalutinis();
    }
    cout << endl;
}
void readFromFile() {
    ifstream fd ("kursiokai.txt");
    string info;
    int ind = 0, grade;
    std::getline(fd, info);
    while (std::getline(fd, info)) {
        std::istringstream reading(info);
        students.push_back(student()); //emplace_back
        reading >> students[ind].surname;
        reading >> students[ind].name;
        while (reading) {
            reading >> grade;
            students[ind].grades.push_back(grade);
        }
        students[ind].exam = students[ind].grades.back();
        students[ind].grades.pop_back();
        students[ind].getGalutinis();
        ind++;
    }
}
//
int main() {
    int numberOfStudents;

    cout << "Įvedinėsite duomenis ranka ar iš failo? (1 - ranka, 0 - iš failo)";
    int inputSelection;
    cin >> inputSelection;
    wasStringGivenInsteadInt(inputSelection);
    while (inputSelection != 1 && inputSelection != 0) { // Ar įvestis tinkama
        cout << "Įvestas skaičius neatitinka jokio pasirinkimo. Įvedinėsite duomenis ranka ar iš failo? (1 - ranka, 0 - iš failo) ";
        cin >> inputSelection;
        cout << endl;
    }

    if (inputSelection == 1) {
        cout << "Kiek studentų įvedinėsite: ";
        cin >> numberOfStudents;
        wasStringGivenInsteadInt(numberOfStudents);
        students.reserve((unsigned)numberOfStudents);
        readFromUser(numberOfStudents);
        printResult();
    } else {
        readFromFile();
        printResult();
    }
    cout << endl << "Press enter to continue ..." << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}