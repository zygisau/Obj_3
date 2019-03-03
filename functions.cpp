
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

    std::streamsize prec = cout.precision();

    for (auto &student : students) {
        cout << setw(maxString+20) << student.name
             << setw(maxString+20) << student.surname
             << setw(maxString+20) << setprecision(2) << fixed << student.galutinis
             << setw(maxString+20) << setprecision(2) << fixed << student.galutinisMedian
             << setprecision(prec) << endl;
    }
}

void printToFile (vector<student>students, int maxString, string fileName) {
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

void filterStudents (vector<student>& students, vector<student>& vargsiukai) {
    try {
        vargsiukai.reserve(50);
    } catch (const std::exception& error) {
        vargsiukai.reserve(10);
    }
    for (int i=0; i<students.size(); i++) {
        if (students[i].vargsiukas) {
            vargsiukai.push_back(students[i]);
            students.erase(students.begin() + i);
            i--;
        }
    }
    students.shrink_to_fit();
    vargsiukai.shrink_to_fit();
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
