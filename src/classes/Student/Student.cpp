//
// Created by zygisau on 01/04/2019.
//
#include "Student.h"

void wasStringGivenInsteadInt(int &param) {
    while (std::cin.fail()) { // ciklas, kol bus įvestas skaičius
        std::cout << std::endl << "Parametras neįrašytas. Prašome pateikti teisingą parametrą: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> param;
    }
}

// Per konsolę įrašomi pažymiai
void Student::setGrades() {
    grades.reserve(5);
    int input;
    bool stop = false;

    do { // Kol nenustoja rašyti skaičių
        cout << "Pažymys: ";
        cin >> input;
        if (!cin.fail()) { // kol rašo pažymius, kad nustotų, turi parašyti ne skaičių
            if (input > 0 && input <= 10) {
                numberOfGrades++;
                grades.push_back(input);
            } else {
                cout << "Parametras netinkamas dešimtbalei sistemai. Prašome pateikti teisingą parametrą. "
                     << std::endl;
            }
        } else {
            stop = true;
            if ( numberOfGrades <= 0 ) { // Ar yra bent vienas pažymys?
                cout << "Privalo būti įrašytas bent vienas pažymys";
                stop = false;
            }
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while ( !stop );

    cin.clear();
    numberOfGrades++; // Šis kintamasis toliau naudojamas kaip masyvo elementų skaičius, kuris turi būti didesnis nei auksčiausias masyvo elementų indeksas
}

// Apskaičiuoja vidurkį
float Student::setAverage() {
    int sum = 0;
    float average;

    sum = std::accumulate(grades.begin(), grades.end(), 0,
                     [] (const int acc, const int grade) { return acc + grade; });
    average = (float)sum/grades.size();

    return average;
}

// Apskaičiuoja medianą
float Student::setMedian() {
    sort(grades.begin(), grades.end());
    float median;
    int size = grades.size();
    int middleIndex = size/2;

    if (size == 1) {
        median = grades[0];
    } else if (size % 2 == 0) {
        median = (float)(grades[middleIndex] + grades[--middleIndex])/2;
    } else {
        median = grades[middleIndex];
    }

    return median;
}

// Apskaičiuoja abu galutinius pažymius
void Student::setGalutinis() {
    float multiplier;
    multiplier = setAverage();
    galutinis = 0.4 * multiplier + 0.6 * exam;

    if (galutinis < 5.0) { // rūšiavimas į kategorijas
        vargsiukas = true;
    }

    multiplier = setMedian();
    galutinisMedian = 0.4 * multiplier + 0.6 * exam;
}

// Pažymių generavimas studentui
void Student::generateGrades() {
    cout << "Kiek pažymių generuoti? "/*(daugiausiai galima " << grades.max_size() << ") "*/;
    cin >> numberOfGrades;
    wasStringGivenInsteadInt(numberOfGrades);
    while (numberOfGrades == 0) {
        cout << "Turi būti įrašytas bent vienas pažymys. Kiek pažymių generuoti? "/*(daugiausiai galima " << grades.max_size() << ") "*/;
        cin >> numberOfGrades;
        wasStringGivenInsteadInt(numberOfGrades);
    }

    try {
        grades.reserve((unsigned)numberOfGrades);
    } catch (const std::length_error& error) {
        cout << "Parinktas per didelis dydis. Rezervuojama 30 pažymių vietų..." << std::endl;
        grades.reserve(30);
        numberOfGrades = 30;
    }

    const unsigned int seed = time(0);
    std::mt19937_64 rng(seed);
    std::uniform_int_distribution<> random(1, 10);

    for (int i=0; i<numberOfGrades; i++) { // pereina per kiekvieną pažymį
        grades.push_back(random(rng));
    }

    exam = random(rng);
}

void Student::setExam( istream & stream ) {
    stream >> exam;
    wasStringGivenInsteadInt(exam);

    while(exam > 10) { // Ar pažymys tinkamas dešimtbalei sistemai
        cout << "Pažymys per didelis dešimtbalei sistemai." << endl;
        cout << "Pažymys: ";
        cin >> exam;
        wasStringGivenInsteadInt(exam);
    }
}

void Student::checkGradesCount() {
    int grade;

    if (grades.size() <= 1) {
        cout << "Studentui " << getName() << " " << getSurname() << " trūksta pažymių, įrašykite dar egzamino pažymį. \nJei vykdote spartos analizę, ši klaida gali sugadinti rezultatus. Kad to išvengtumėte, rekomenduojame dar kartą patikrinti, ar duomenų faile nėra klaidų ir paleisti programą iš naujo. ARBA \n";

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

            pushBackGrades(grade);
        }
    }
}

void Student::setExamFromGrades() {
    exam = grades.back();
    grades.pop_back();
    setGalutinis();
    grades.clear();
}

Student& Student::operator=(const Student& stud) {
    // Savęs priskyrimo aptikimas
    if (&stud == this) return *this;

    // Atlaisviname seną atmintį (jei buvo)
    grades.clear();

    // Nukopijuojame naujus elementus
    grades = stud.getGrades();
    name = stud.getName();
    surname = stud.getSurname();
    exam = stud.getExam();
    galutinis = stud.getGalutinis();
    galutinisMedian = stud.getGalutinisMedian();
    numberOfGrades = stud.getNumberOfGrades();
    vargsiukas = stud.isVargsiukas();
    return *this;
}

Student& Student::operator=(Student&& stud) noexcept{
    // Savęs priskyrimo aptikimas
    if(&stud == this )
        return *this;

    grades.clear(); // Atlaisviname atmintį
    name = stud.name; // Atnaujiname atmintį
    surname = stud.surname;
    exam = stud.exam;
    galutinis = stud.galutinis;
    galutinisMedian = stud.galutinisMedian;
    numberOfGrades = stud.numberOfGrades;
    vargsiukas = stud.vargsiukas;
    grades = std::move(stud.grades);

    return *this;
}

bool Student::operator>(const Student& stud) {
    return galutinis > stud.getGalutinis();
}

bool Student::operator<(const Student& stud) {
    return galutinis < stud.getGalutinis();
}

bool Student::operator==(const Student& stud) {
    return galutinis == stud.getGalutinis();
}

bool Student::operator!=(const Student& stud) {
    return galutinis != stud.getGalutinis();
}

bool Student::operator>=(const Student& stud) {
    return galutinis >= stud.getGalutinis();
}

bool Student::operator<=(const Student& stud) {
    return galutinis <= stud.getGalutinis();
}