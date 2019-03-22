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
bool sortByName(const student & stud1, const student & stud2) {
    return (stud1.name < stud2.name) ||
           ((stud1.name == stud2.name) && (stud1.surname > stud2.surname));
}

// Rikiavimo funkcijos visiems trims konteineriams
void sortStudents(vector<student> & students) {
    sort(students.begin(), students.end(), sortByName);
}

void sortStudents(deque<student> & students) {
    sort(students.begin(), students.end(), sortByName);
}

void sortStudents(list<student> & students) {
    students.sort(sortByName);
}

// Rezultatų išvedimas į konsolę
void printResult(vector<student>students, int maxString) {

    // Visiems studentams suskaičiuojamas galutinis pažymys
    for (auto &student : students) {
        student.getGalutinis();
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
        cout << setw(maxString+20) << student.name
             << setw(maxString+20) << student.surname
             << setw(maxString+20) << setprecision(2) << fixed << student.galutinis
             << setw(maxString+20) << setprecision(2) << fixed << student.galutinisMedian
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
        file << setw(maxString + 20) << student.name
             << setw(maxString + 20) << student.surname
             << setw(maxString + 20) << setprecision(2) << fixed << student.galutinis
             << setw(maxString + 20) << setprecision(2) << fixed << student.galutinisMedian
             << endl;
    }

    // Atstatomas tikslumas
    file << setprecision(prec);
    file.close();
}

// Filtruojami studentai į du tipus: vargsiukus ir studentus (negavusius skolos) visais konteineriais pagal antrąją strategiją
void filterStudents(list<student>& students, list<student>& vargsiukai) {
    for (list<student>::iterator it = students.begin(); it != students.end(); ++it) {
        if ((*it).vargsiukas) {
            vargsiukai.push_back((*it));
            students.erase(it);
        }
    }
}

void filterStudents (deque<student>& students, deque<student>& vargsiukai) {
    auto bound = std::stable_partition(students.begin(), students.end(),
                                       [&](const auto& x) { return !(x.vargsiukas); });

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

void filterStudents (vector<student>& students, vector<student>& vargsiukai) {
    auto bound = std::stable_partition(students.begin(), students.end(),
                                   [&](const auto& x) { return !(x.vargsiukas); });

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
void filterStudentsStrat1 (list<student>& students, list<student>& vargsiukai, list<student>& kietiakai) {
    for (list<student>::iterator it = students.begin(); it != students.end(); ++it) {
        if ((*it).vargsiukas) {
            vargsiukai.push_back((*it));
        } else {
            kietiakai.push_back((*it));
        }
    }
}

void filterStudentsStrat1 (deque<student>& students, deque<student>& vargsiukai, deque<student>& kietiakai) {
    int ind = 0;
    for (auto &stud : students) {
        if (stud.vargsiukas) {
            vargsiukai.push_back(stud);
        } else {
            kietiakai.push_back(stud);
        }
        ind++;
    }
}

void filterStudentsStrat1 (vector<student>& students, vector<student>& vargsiukai, vector<student>& kietiakai) {
    int ind = 0;
    for (auto &stud : students) {
        if (stud.vargsiukas) {
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

// Ar pažymių užtenka, nes paskutinis pažymys visada bus egzaminas
void checkGradesCount(vector<int>& grades, const string& fname, const string& lname) {
    int grade;

    if (grades.size() <= 1) {
        cout << "Studentui " << fname << " " << lname << " trūksta pažymių, įrašykite dar egzamino pažymį. \nJei vykdote spartos analizę, ši klaida gali sugadinti rezultatus. Kad to išvengtumėte, rekomenduojame dar kartą patikrinti, ar duomenų faile nėra klaidų ir paleisti programą iš naujo. ARBA \n";

        // Prašoma įvesti du pažymius
        for (int i = 1; i <= 2; i++) {
            cout << "Įrašykite pažymį: ";
            cin >> grade;
            wasStringGivenInsteadInt(grade);

            while (grade > 10) { // Ar atitinka dešimtbalę sistemą?
                cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
                cout << "Pažymys: ";
                cin >> grade;
                wasStringGivenInsteadInt(grade);
            }

            grades.push_back(grade);
        }
    }
}