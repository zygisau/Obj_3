//#include <iostream>
//#include <string>
//#include <iomanip>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//using std::cout; using std::cin; using std::endl; using std::string; using std::setw; using std::left; using std::setprecision; using std::fixed;
//using std::sort; using std::stoi; using std::vector;
//void wasStringGivenInsteadInt(int &param);
//struct student {
//    string name = "Vardas";
//    string surname = "Pavardė";
//    vector<int> grades;
//    int exam=0;
//    double galutinis=0;
//    int numberOfGrades=0;
//
//    void getGrades() {
//        grades.reserve(5);
//        int input;
//        string escKey;
//        numberOfGrades = -1;
//        while (escKey != "n") {
//            numberOfGrades++;
//            cout << "Pažymys: ";
//            cin >> input;
//            wasStringGivenInsteadInt(input);
//            while(input > 10) {
//                cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
//                cout << "Pažymys: ";
//                cin >> input;
//                wasStringGivenInsteadInt(input);
//            }
//            grades.push_back(input);
//            cout << "Paspauskite n, kad baigtumėte įrašyti pažymius, bet ką kitą, jei norite tęsti: ";
//            cin >> escKey;
//        }
//        numberOfGrades++; // Šis parametras toliau naudojamas kaip masyvo elementų skaičius, kuris turi būti didesnis nei auksčiausias masyvo elementų indeksas
//    }
//    float getAverage() {
//        int sum = 0;
//        float average;
//        for ( auto &grade : grades) {
//            sum += grade;
//        }
//        average = (float)sum/grades.size();
//        return average;
//    }
//    float getMedian() {
//        sort(grades.begin(), grades.end());
//        float median;
//        int middleIndex = numberOfGrades/2;
//        if (grades.size() % 2 == 0) {
//            median = (float)(grades[middleIndex] + grades[--middleIndex])/2;
//        } else {
//            median = grades[--middleIndex];
//        }
//        return median;
//    }
//    void getGalutinis(const string& param) {
//        float multiplier;
//        if (param == "v" || param == "vi" || param == "vid") {
//            multiplier = getAverage();
//        } else {
//            multiplier = getMedian();
//        }
//        galutinis = 0.4 * multiplier + 0.6 * exam;
//    }
//};
////
//void wasStringGivenInsteadInt(int &param) {
//    while (cin.fail()) {
//        cout << "Parametras neįrašytas. Prašome pateikti teisingą parametrą: ";
//        cin.clear();
//        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        cin >> param;
//    }
//}
//void compareStrings(int& base, string& string) {
//    if (base < string.size()) {
//        base = string.size();
//    }
//}
////
//int main() {
//    int maxString = 0;
//    int sk;
//    cout << "Kiek mokinių įvedinėsite: ";
//    cin >> sk;
//    wasStringGivenInsteadInt(sk);
//    student *stud = new student[sk];
//    for (int i=0; i<sk; i++) {
//        cout << "Įveskite mokinio vardą: ";
//        cin >> stud[i].name;
//        compareStrings(maxString, stud[i].name);
//        cout << "Įveskite mokinio pavardę: ";
//        cin >> stud[i].surname;
//        compareStrings(maxString, stud[i].surname);
//        cout << "Įveskite pažymius" << endl;
//        stud[i].getGrades();
//        cout << "Koks mokinio egzamino pažymys: ";
//        cin >> stud[i].exam;
//        wasStringGivenInsteadInt(stud[i].exam);
//    }
//    cout << "Norite, jog galutinis pažymys būtų skaičiuojamas pagal vidurkį (vid) ar medianą (med)? ";
//    string choose;
//    cin >> choose;
//    while (choose !="v" && choose != "vi" && choose != "vid" && choose != "m" && choose != "me" && choose != "med") {
//        cout << choose << endl;
//        cout << "Netinkamas parametras. Norite, jog galutinis pažymys būtų skaičiuojamas pagal vidurkį (vid) ar medianą (med)?";
//        cin.clear();
//        cin.ignore();
//        cin >> choose;
//    }
//    for (int i = 0; i < sk; i++) {
//        stud[i].getGalutinis(choose);
//    }
//    cout << endl;
//
//    if (choose == "v" || choose == "vi" || choose == "vid") {
//        cout << left << setw(maxString+10) << "Vardas" << setw(maxString+10) << "Pavardė" << setw(maxString+10) << "Galutinis (Vid.)" << endl;
//    } else {
//        cout << left << setw(maxString+10) << "Vardas" << setw(maxString+10) << "Pavardė" << setw(maxString+10) << "Galutinis (Med.)" << endl;
//    }
//    for (int i = 0; i < 3*(maxString+10); i++) cout << "-";
//    cout << endl;
//    for (int i = 0; i < sk; i++) {
//        cout << setw(maxString+10) << stud[i].name << setw(maxString+10) << stud[i].surname << setw(maxString+10) << setprecision(2) << fixed << stud[i].galutinis << endl;
//    }
//}