#include "./classes/Student/Student.h"

// Ieškomas ilgiausias string
void compareStrings(int& base, const string& string) {
    if (base < string.size()) {
        base = string.size();
    }
}

// Tikrinama, ar įvestis yra 0 arba 1
void checkIfBinary (int& input, const string& message) {
    while (input != 1 && input != 0) { // Ar įvestis tinkama
        cout << message;
        cin >> input;
        cout << endl;
    }
}

// Rikiavimas pagal vardą
bool sortByName(const Student & stud1, const Student & stud2) {
    string name1 = stud1.getName();
    string name2 = stud2.getName();
    string surname1 = stud1.getSurname();
    string surname2 = stud2.getSurname();
    return (name1 < name2) ||
           ((name1 == name2) && (surname1 > surname2));
}

// Rikiavimo funkcijos visiems trims konteineriams
void sortStudents(vector<Student> & students) {
    sort(students.begin(), students.end(), sortByName);
}

void sortStudents(deque<Student> & students) {
    sort(students.begin(), students.end(), sortByName);
}

void sortStudents(list<Student> & students) {
    students.sort(sortByName);
}

// Rezultatų išvedimas į konsolę
void printResult(vector<Student>students, int maxString) {

    // Visiems studentams suskaičiuojamas galutinis pažymys
    for (auto &student : students) {
        student.setGalutinis();
    }

    sortStudents(students);

    cout << left << setw(maxString+20) << "Vardas" << setw(maxString+20) << "Pavardė" << setw(maxString+20) << "Galutinis (Vid.)" << setw(maxString+20) << "Galutinis (Med.)" << endl;

// Linijos spausdinimas
    for (int i = 0; i < 4*(maxString+20); i++) cout << "-";
    cout << endl;

// Išsaugomas tikslumas, kad paskui atstatytume į pradinį
    std::streamsize prec = cout.precision();

// Spausdinami studentai
    for (auto &student : students) {
        cout << setw(maxString+20) << student.getName()
             << setw(maxString+20) << student.getSurname()
             << setw(maxString+20) << setprecision(2) << fixed << student.getGalutinis()
             << setw(maxString+20) << setprecision(2) << fixed << student.getGalutinisMedian()
             << endl;
    }
// Atstatomas tikslumas
    cout << setprecision(prec);
}

// Spausdinimas į failą
template < typename container >
void printToFile (const container & students, int maxString, string fileName) {
    std::ofstream file (fileName);

    file << left << setw(maxString+20) << "Vardas"
         << setw(maxString+20) << "Pavardė"
         << setw(maxString+20) << "Galutinis (Vid.)"
         << setw(maxString+20) << "Galutinis (Med.)" << endl;

    // Linijos spausdinimas
    for (int i = 0; i < 4*(maxString+20); i++) {
    file << "-";
    }
    file << endl;

// Išsaugomas tikslumas, kad paskui atstatytume į pradinį
    std::streamsize prec = file.precision();

// Spausdinami studentai
    for (auto &student : students) {
        file << setw(maxString + 20) << student.getName()
             << setw(maxString + 20) << student.getSurname()
             << setw(maxString + 20) << setprecision(2) << fixed << student.getGalutinis()
             << setw(maxString + 20) << setprecision(2) << fixed << student.getGalutinisMedian()
             << endl;
    }

    // Atstatomas tikslumas
    file << setprecision(prec);
    file.close();
}

// Filtruojami studentai į du tipus: vargsiukus ir studentus (negavusius skolos) visais konteineriais pagal antrąją strategiją
void filterStudents(list<Student>& students, list<Student>& vargsiukai) {
    for (list<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        if ((*it).isVargsiukas()) {
            vargsiukai.push_back((*it));
            students.erase(it);
        }
    }
}

void filterStudents (deque<Student>& students, deque<Student>& vargsiukai) {
    auto bound = std::stable_partition(students.begin(), students.end(),
                                       [&](const auto& x) { return !(x.getVargsiukas()); });

    vargsiukai.insert(vargsiukai.end(), std::make_move_iterator(bound),
                      std::make_move_iterator(students.end()));

    students.erase(bound, students.end());

// Blogesnė versija
//    int ind = 0;
//    for (auto &stud : students) {
//        if (stud.vargsiukas) {
//            vargsiukai.push_back(stud);
//            students.erase(students.begin() + ind);
//            ind++;
//        }
//    }
}

void filterStudents (vector<Student>& students, vector<Student>& vargsiukai) {
    auto bound = std::stable_partition(students.begin(), students.end(),
                                   [&](const auto& x) { return !(x.getVargsiukas()); });

    vargsiukai.insert(vargsiukai.end(), std::make_move_iterator(bound),
                  std::make_move_iterator(students.end()));

    students.erase(bound, students.end());

// Blogesnis variantas
//    int ind = 0;
//    for (auto &stud : students) {
//        if (stud.vargsiukas) {
//            vargsiukai.push_back(stud);
//            students.erase(students.begin() + ind);
//            ind++;
//        }
//    }
}

// Filtruojami studentai į du tipus: vargsiukus ir studentus (negavusius skolos) visais konteineriais pagal pirmąją strategiją
void filterStudentsStrat1 (list<Student>& students, list<Student>& vargsiukai, list<Student>& kietiakai) {
    for (list<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        if ((*it).isVargsiukas()) {
            vargsiukai.push_back((*it));
        } else {
            kietiakai.push_back((*it));
        }
    }
}

void filterStudentsStrat1 (deque<Student>& students, deque<Student>& vargsiukai, deque<Student>& kietiakai) {
    int ind = 0;
    for (auto &stud : students) {
        if (stud.isVargsiukas()) {
            vargsiukai.push_back(stud);
        } else {
            kietiakai.push_back(stud);
        }
        ind++;
    }
}

void filterStudentsStrat1 (vector<Student>& students, vector<Student>& vargsiukai, vector<Student>& kietiakai) {
    int ind = 0;
    for (auto &stud : students) {
        if (stud.isVargsiukas()) {
            vargsiukai.push_back(stud);
        } else {
            kietiakai.push_back(stud);
        }
        ind++;
    }
}

// Failų generavimas
void generateFile(string fileName, int size) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937_64 rng(seed);
    std::uniform_int_distribution<> random(1, 10);

    std::ofstream file (fileName);

    cout << "Generuojamas failas " << fileName;

// Antraštė
    file << left << setw(30) << "Vardas"
         << setw(30) << "Pavardė"
         << setw(5) << "ND1"
         << setw(5) << "ND2"
         << setw(5) << "ND3"
         << setw(5) << "ND4"
         << setw(5) << "ND5"
         << setw(5) << "EGZ"<< endl;

// Įrašai
    for (int i = 0; i<size; i++) {
        file << left << setw(30) << ("Vardas" + std::to_string(i+1))
        << setw(30) << ("Pavardė" + std::to_string(i+1))
        << setw(5) << random(rng) << setw(5) << random(rng)
        << setw(5) << random(rng) << setw(5) << random(rng)
        << setw(5) << random(rng) << setw(5) << random(rng) << endl;
    }

    cout << "BAIGTA" << endl;

    file.close();
}

// Patikrina, ar pažymys yra skaičius ir ar tinkamas kaip pažymys
int checkGrade(string &param, const string& message) {
    int paramInt;

    try {
        paramInt = std::stoi(param);

        while(paramInt > 10) { // Ar atitinka dešimtbalę sistemą?
            cout << message << endl;
            cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
            cout << "Pažymys: ";
            cin >> paramInt;
            wasStringGivenInsteadInt(paramInt);
        }

    } catch (const std::invalid_argument & e) {
        cout << message;
        cin >> paramInt;
        wasStringGivenInsteadInt(paramInt);

        while(paramInt > 10) { // Ar atitinka dešimtbalę sistemą?
            cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
            cout << "Pažymys: ";
            cin >> paramInt;
            wasStringGivenInsteadInt(paramInt);
        }
    }

    return paramInt;
}

