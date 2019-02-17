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
    string name = "Vardas";
    string surname = "Pavardė";
    vector<int> grades;
    int exam=0;
    double galutinis=0; // Galutinis studento pažymys
    int numberOfGrades=0;

    void getGrades() {
        grades.reserve(5);
        int input;
        string escKey; // Įvestis, kurią suvedus baigsis pažymių įrašinėjimas
        numberOfGrades = -1;
        while (escKey != "n") { // Ciklas, kol nebus įvestas simbolis n ir baigtas studentų įrašymas
            numberOfGrades++;
            cout << "Pažymys: ";
            cin >> input;
            wasStringGivenInsteadInt(input);
            while(input > 10) {
                cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
                cout << "Pažymys: ";
                cin >> input;
                wasStringGivenInsteadInt(input);
            }
            grades.push_back(input);
            cout << "Paspauskite n, kad baigtumėte įrašyti pažymius, bet ką kitą, jei norite tęsti: ";
            cin >> escKey;
        }
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
        int middleIndex = (double) numberOfGrades/2;
        if (numberOfGrades == 1) {
            median = grades[0];
        } else if (grades.size() % 2 == 0) {
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
    void generateGrades() {
        cout << "Kiek pažymių generuoti? ";
        cin >> numberOfGrades;
        wasStringGivenInsteadInt(numberOfGrades);
        grades.reserve(numberOfGrades);
        const unsigned int seed = time(0);
        std::mt19937_64 rng(seed);
        std::uniform_real_distribution<double> random(1, 10);
        for (int i=0; i<numberOfGrades; i++) { // pereina per kiekvieną pažymį
            grades.push_back((int)random(rng));
//            cout << grades[i] << " ";
        }
//        cout << endl;
        exam = (int)random(rng);
    }
};
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
void printResult(const string choose, const int maxString, const int numberOfStudents, const student *stud) {
    if (choose == "v" || choose == "vi" || choose == "vid") {
        cout << left << setw(maxString+10) << "Vardas" << setw(maxString+10) << "Pavardė" << setw(maxString+10) << "Galutinis (Vid.)" << endl;
    } else {
        cout << left << setw(maxString+10) << "Vardas" << setw(maxString+10) << "Pavardė" << setw(maxString+10) << "Galutinis (Med.)" << endl;
    }
    for (int i = 0; i < 3*(maxString+10); i++) cout << "-";
    cout << endl;
    for (int i = 0; i < numberOfStudents; i++) {
        cout << setw(maxString+10) << stud[i].name << setw(maxString+10) << stud[i].surname << setw(maxString+10) << setprecision(2) << fixed << stud[i].galutinis << endl;
    }
}
void readFromFile() {
    ifstream file ("kursiokai.txt");
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int ind = 0, grade;
    char names[13];
    vector<student> stud;
    stud.reserve(5);
    while(!file.eof()) {
        stud.push_back(student());
        file.get(names, 12);
        stud[ind].surname = names;
        file.get(names, 12);
        stud[ind].name = names;
        stud[ind].grades.reserve(5);
        for (int i=0; i<5; i++) {
            file >> grade;
            stud[ind].grades.push_back(grade);
        }
        file.ignore();
        ind++;
        cout << stud[ind].name << endl;
    }
}
//
int main() {
    int maxString = 0; // Ilgiausia simbolių eilutė rezultatų spausdinimui
    int numberOfStudents, isNeededToGenerate;
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
        student *stud = new student[numberOfStudents];
        for (int i=0; i<numberOfStudents; i++) { // Įrašinėja visų studentų duomenis
            cout << "Įveskite studento vardą: ";
            cin >> stud[i].name;
            compareStrings(maxString, stud[i].name); // Tikrinama įvestis, ieškomas ilgiausias žodis
            cout << "Įveskite studento pavardę: ";
            cin >> stud[i].surname;
            compareStrings(maxString, stud[i].surname);
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
                stud[i].getGrades();
                cout << "Koks studento egzamino pažymys: ";
                cin >> stud[i].exam;
                wasStringGivenInsteadInt(stud[i].exam);
                while(stud[i].exam > 10) {
                    cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
                    cout << "Pažymys: ";
                    cin >> stud[i].exam;
                    wasStringGivenInsteadInt(stud[i].exam);
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
            stud[i].getGalutinis(choose);
        }
        cout << endl;
        printResult(choose, maxString, numberOfStudents, stud);
    } else {
        readFromFile();
    }
    // cout << "Norite, jog galutinis pažymys būtų skaičiuojamas pagal vidurkį (vid) ar medianą (med)? ";
    // string choose;
    // cin >> choose;
    // while (choose !="v" && choose != "vi" && choose != "vid" && choose != "m" && choose != "me" && choose != "med") {
    //     cout << choose << endl;
    //     cout << "Netinkamas parametras. Norite, jog galutinis pažymys būtų skaičiuojamas pagal vidurkį (vid) ar medianą (med)?";
    //     cin.clear();
    //     cin.ignore();
    //     cin >> choose;
    // }
    // for (int i = 0; i < numberOfStudents; i++) {
    //     stud[i].getGalutinis(choose);
    // }
    // cout << endl;
    // Spausdinimas
    cout << "Press enter to continue ..." << endl; 
    cin.get(); 
    return 0;
}