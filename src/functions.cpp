#include "./classes/Student/Student.h"
#include "./classes/Timer/Timer.h"

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
                                       [&](const auto& x) { return !(x.isVargsiukas()); });

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
                                   [&](const auto& x) { return !(x.isVargsiukas()); });

    vargsiukai.insert(vargsiukai.end(), bound,
                  students.end());

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

template < typename container >
void speedTest(container & students, container & vargsiukai, bool strat1) {
    cout.flush();
    Timer t;
    readFromFile(students, vargsiukai, "kursiokai10.txt", strat1);
    cout << "Darbas su \"kursiokai10.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai100.txt", strat1);
    cout << "Darbas su \"kursiokai100.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai1000.txt", strat1);
    cout << "Darbas su \"kursiokai1000.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai10000.txt", strat1);
    cout << "Darbas su \"kursiokai10000.txt\" užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    t.reset();
    readFromFile(students, vargsiukai, "kursiokai100000.txt", strat1);
    cout << "Darbas su \"kursiokai100000.txt\" užtruko: " << t.elapsed() << " s" << endl;
}

void containerTest() {
    cout << "Startegija 2" << endl << endl;

    cout << "Pradedamas darbas naudojant vector konteinerį..." << endl;
    Timer t;
    vector<Student> students;
    vector<Student> vargsiukai;
    students.reserve(100000);
    vargsiukai.reserve(100000);
    speedTest(students, vargsiukai, false);
    cout << "Darbas su STD::VECTOR konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    cout << "Pradedamas darbas naudojant deque konteinerį..." << endl;
    t.reset();
    deque<Student> studentsDeque;
    deque<Student> vargsiukaiDeque;
    speedTest(studentsDeque, vargsiukaiDeque, false);
    cout << "Darbas su STD::DEQUE konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    // FIXME: List is not pushing its values
//    cout << "Pradedamas darbas naudojant list konteinerį..." << endl;
//    t.reset();
//    list<Student> studentsList = {};
//    list<Student> vargsiukaiList = {};
//    speedTest(studentsList, vargsiukaiList, false);
//    cout << "Darbas su STD::LIST konteineriu užtruko: " << t.elapsed() << " s" << endl;
}

// Pirmoji strategija
void containerTestBadStrat() {
    cout << "Startegija 1" << endl << endl;

    cout << "Pradedamas darbas naudojant vector konteinerį..." << endl;
    Timer t;
    vector<Student> students;
    vector<Student> vargsiukai;
    students.reserve(100000);
    vargsiukai.reserve(100000);
    speedTest(students, vargsiukai, true);
    cout << "Darbas su STD::VECTOR konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    cout << "Pradedamas darbas naudojant list konteinerį..." << endl;
    t.reset();
    list<Student> studentsList;
    list<Student> vargsiukaiList;
    speedTest(studentsList, vargsiukaiList, true);
    cout << "Darbas su STD::LIST konteineriu užtruko: " << t.elapsed() << " s" << endl;

    cout << endl;

    cout << "Pradedamas darbas naudojant deque konteinerį..." << endl;
    t.reset();
    deque<Student> studentsDeque;
    deque<Student> vargsiukaiDeque;
    speedTest(studentsDeque, vargsiukaiDeque, true);
    cout << "Darbas su STD::DEQUE konteineriu užtruko: " << t.elapsed() << " s" << endl;
}

template < typename container >
void readFromFile(container &students, container &vargsiukai, const string& fileName, bool strat1) {
    Timer timer;
    ifstream fd (fileName);

    if (fd.fail()) {
        cout << "Įvyko klaida atidarant duomenų failą. Prašome įsitikinti, ar failas tinkamoje direktorijoje." << endl;
        exit(EXIT_FAILURE);
    }

    string info;
    int gradeInt, maxString = 0;
    string gradeStr, message;
    Student stud = Student();

    std::getline(fd, info);

// Susižinome kiek pažymių gali būti daugiausiai faile
    std::istringstream reading(info);
    string testInfo;
    int gradesCount = -2;
    while(reading >> testInfo) { // einama, kol pasiekiamas eilutės galas
        gradesCount++;
    }
// Rezervuojame didžiausią galimą pažymių skaičių
    stud.reserveGrades(gradesCount);

    while (std::getline(fd, info)) { // Pagrindinis nuskaitymas
        std::istringstream reading(info);

        stud.Human::setName(reading);
        compareStrings(maxString, stud.getName());

        stud.Human::setSurname(reading);
        compareStrings(maxString, stud.getSurname());

        // Klaidos žinutė
        message = "Pažymys studentui " + stud.getName() + " " + stud.getSurname() + " neįrašytas. \nJei vykdote spartos analizę, ši klaida gali sugadinti rezultatus. Kad to išvengtumėte, rekomenduojame dar kartą patikrinti, ar duomenų faile nėra klaidų ir paleisti programą iš naujo. \n ARBA Įrašykite pažymį: ";

        while (!reading.eof()) { // kol nepasibaigs eilutė
            reading >> gradeStr;
            gradeInt = checkGrade(gradeStr, message);
            stud.pushBackGrades(gradeInt);
        }
        stud.checkGradesCount();

        stud.setExamFromGrades();

        students.push_back(stud); //emplace_back

//        students.push_back(stud); // ŠITIE VARIANTAI NEVEIKIA SU STD::LIST KONTEINERIU. NEĮRAŠO Į KONTEINERĮ NIEKO
//        students.insert(students.end(), 1, stud);
        stud = {};
    }
    fd.close();
    cout << "Nuskaitymas iš failo truko: " << timer.elapsed() << " s" << endl;

    timer.reset();

    sortStudents(students);

    if (strat1) {
        container kietiakai;
        filterStudentsStrat1(students, vargsiukai, kietiakai);
        cout << "Studentų filtravimas (skirstymas) truko: " << timer.elapsed() << " s" << endl;

        timer.reset();
        printToFile(kietiakai, maxString, "kietuoliai.txt");
        printToFile(vargsiukai, maxString, "vargsiukai.txt");
        cout << "Įrašymas į failą truko: " << timer.elapsed() << " s" << endl;

        students.clear();
        kietiakai.clear();
        vargsiukai.clear();
    } else {
        filterStudents(students, vargsiukai);
        cout << "Studentų filtravimas (skirstymas) truko: " << timer.elapsed() << " s" << endl;

        timer.reset();
        printToFile(students, maxString, "kietuoliai.txt");
        printToFile(vargsiukai, maxString, "vargsiukai.txt");
        cout << "Įrašymas į failą truko: " << timer.elapsed() << " s" << endl;

        students.clear();
        vargsiukai.clear();
    }
}

void readFromUser(const int numberOfStudents, vector<Student>& students) {
    int maxString = 0; // Ilgiausia simbolių eilutė rezultatų spausdinimui

    for (int i=0; i<numberOfStudents; i++) { // Įrašinėja visų studentų duomenis
        students.push_back(Student());

        cout << "Įveskite studento vardą: ";
        students[i].Human::setName(cin);
        compareStrings(maxString, students[i].getName()); // Tikrinama įvestis, ieškomas ilgiausias žodis

        cout << "Įveskite studento pavardę: ";
        students[i].Human::setSurname(cin);
        compareStrings(maxString, students[i].getSurname());

// Ar reikia generuoti studentui pažymius
        cout << "Ar norite, jog pažymiai būtų sugeneruoti už Jus? (1 - taip, 0 - ne) ";
        int isNeededToGenerate;
        cin >> isNeededToGenerate;
        wasStringGivenInsteadInt(isNeededToGenerate);
        checkIfBinary(isNeededToGenerate, "Įvestas skaičius neatitinka jokio pasirinkimo. Ar norite, jog pažymiai būtų sugeneruoti už Jus? (1 - taip, 0 - ne) ");

        if (isNeededToGenerate == 1) {
            students[i].generateGrades();
        } else {
            cout << "Įveskite pažymius. Įveskite ne skaičių, jog baigtumėte įrašymą." << endl;
            students[i].setGrades();

            cout << "Koks studento egzamino pažymys: ";
            students[i].setExam(cin);

        }

        students[i].setGalutinis();

        cout << endl;
    }

    cout << endl;
    printResult(students, maxString);
}
