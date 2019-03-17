
void compareStrings(int& base, const string& string) {
    if (base < string.size()) {
        base = string.size();
    }
}

void checkIfBinary (int& input, const string& message) {
    while (input != 1 && input != 0) { // Ar įvestis tinkama
        cout << message;
        cin >> input;
        cout << endl;
    }
}

bool sortByName(const student & stud1, const student & stud2) {
    return (stud1.name < stud2.name) ||
           ((stud1.name == stud2.name) && (stud1.surname > stud2.surname));
}

void sortStudents(vector<student> & students) {
    sort(students.begin(), students.end(), sortByName);
}

void sortStudents(deque<student> & students) {
    sort(students.begin(), students.end(), sortByName);
}

void sortStudents(list<student> & students) {
    students.sort(sortByName);
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

    std::streamsize prec = cout.precision();

    for (auto &student : students) {
        cout << setw(maxString+20) << student.name
             << setw(maxString+20) << student.surname
             << setw(maxString+20) << setprecision(2) << fixed << student.galutinis
             << setw(maxString+20) << setprecision(2) << fixed << student.galutinisMedian
             << setprecision(prec) << endl;
    }
}

template < typename container >
void printToFile (container students, int maxString, string fileName) {
    std::ofstream file (fileName);

    file << left << setw(maxString+20) << "Vardas" << setw(maxString+20) << "Pavardė" << setw(maxString+20) << "Galutinis (Vid.)" << setw(maxString+20) << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 4*(maxString+20); i++) {
    file << "-";
    }
    file << endl;

    std::streamsize prec = file.precision();

    for (auto &student : students) {
        file << setw(maxString + 20) << student.name
             << setw(maxString + 20) << student.surname
             << setw(maxString + 20) << setprecision(2) << fixed << student.galutinis
             << setw(maxString + 20) << setprecision(2) << fixed << student.galutinisMedian
             << setprecision(prec) << endl;
    }
    file.close();
}

void filterStudents(list<student>& students, list<student>& vargsiukai) {
    for (list<student>::iterator it = students.begin(); it != students.end(); ++it) {
        if ((*it).vargsiukas) {
            vargsiukai.push_back((*it));
            students.erase(it);
        }
    }
}

void filterStudents (deque<student>& students, deque<student>& vargsiukai) {
    int ind = 0;
    for (auto &stud : students) {
        if (stud.vargsiukas) {
            vargsiukai.push_back(stud);
            students.erase(students.begin() + ind);
            ind++;
        }
    }
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

void generateFile(string fileName, int size) {
    const unsigned int seed = time(0);
    std::mt19937_64 rng(seed);
    std::uniform_real_distribution<double> random(1, 10);

    std::ofstream file (fileName);

    cout << "Generuojamas failas " << fileName;

    file << left << setw(30) << "Vardas" << setw(30) << "Pavardė" << setw(5) << "ND1" << setw(5) << "ND2" << setw(5) << "ND3" << setw(5) << "ND4" << setw(5) << "ND5" << setw(5) << "EGZ"<< endl;

    for (int i = 0; i<size; i++) {
        file << left << setw(30) << ("Vardas" + std::to_string(i+1)) << setw(30) << ("Pavardė" + std::to_string(i+1)) << setw(5) << (int)random(rng) << setw(5) << (int)random(rng) << setw(5) << (int)random(rng) << setw(5) << (int)random(rng) << setw(5) << (int)random(rng)  << setw(5) << (int)random(rng) << endl;
    }

    cout << "BAIGTA" << endl;

    file.close();
}

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

void checkGradesCount(vector<int>& grades, const string& fname, const string& lname) {
    int grade;
    if (grades.size() == 1) {
        cout << "Studentui " << fname << " " << lname << " trūksta pažymių, įrašykite dar egzamino pažymį. \nJei vykdote spartos analizę, ši klaida gali sugadinti rezultatus. Kad to išvengtumėte, rekomenduojame dar kartą patikrinti, ar duomenų faile nėra klaidų ir paleisti programą iš naujo. \n ARBA Įrašykite pažymį: ";
        cin >> grade;
        wasStringGivenInsteadInt(grade);
        while(grade > 10) { // Ar atitinka dešimtbalę sistemą?
            cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
            cout << "Pažymys: ";
            cin >> grade;
            wasStringGivenInsteadInt(grade);
        }
        grades.push_back(grade);
    }
}