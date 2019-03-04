#ifndef HEADER_H

#define HEADER_H
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>
#include <chrono>
#include <numeric>
using std::cout; using std::cin; using std::endl; using std::string; using std::setw; using std::left; using std::setprecision; using std::fixed;
using std::sort; using std::stoi; using std::vector; using std::ifstream;

void wasStringGivenInsteadInt(int &param) {
    while (cin.fail()) { // ciklas, kol bus įvestas skaičius
        cout << "Parametras neįrašytas. Prašome pateikti teisingą parametrą: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> param;
    }
}

struct student {
    string name = "Vardenis";
    string surname = "Pavardenis";
    vector<int> grades;
    int exam=0;
    double galutinis=0; // Galutinis studento pažymys
    double galutinisMedian = 0;
    int numberOfGrades=0;
    bool vargsiukas=false;

    void getGrades() {
        grades.reserve(5);
        int input;

        while (numberOfGrades <= 0) { // kol neirasytas nei vienas pazymys
            cout << "Pažymys: ";
            while (cin >> input) { // kol raso pazymius, kad nustotu, turi parasyti ne skaiciu, kas reikstu false
                if (input <= 10) {
                    numberOfGrades++;
                    grades.push_back(input);
                } else {
                    cout << "Parametras per didelis dešimtbalei sistemai. Prašome pateikti teisingą parametrą. " << endl;
                }
            }
            cin.clear();
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        numberOfGrades++; // Šis kintamasis toliau naudojamas kaip masyvo elementų skaičius, kuris turi būti didesnis nei auksčiausias masyvo elementų indeksas
    }

    float getAverage() {
        int sum = 0;
        float average;
        sum = std::accumulate(grades.begin(), grades.end(), 0);
        average = (float)sum/grades.size();
        return average;
    }
    float getMedian() {
        sort(grades.begin(), grades.end());
        float median;
        int middleIndex = grades.size()/2;

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

        if (galutinis < 5.0) { // rūšiavimas į kategorijas
            vargsiukas = true;
        }

        multiplier = getMedian();
        galutinisMedian = 0.4 * multiplier + 0.6 * exam;
    }
    void generateGrades() {
        cout << "Kiek pažymių generuoti? (daugiausiai galima " << grades.max_size() << ") ";
        cin >> numberOfGrades;
        wasStringGivenInsteadInt(numberOfGrades);
        try {
            grades.reserve((unsigned)numberOfGrades);
        } catch (const std::length_error& error) {
            cout << "Parinktas per didelis dydis. Rezervuojama 30 pažymių vietų..." << endl;
            grades.reserve(30);
            numberOfGrades = 30;
        }
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

class Timer { // paimta iš https://github.com/objprog/paskaitos2019/wiki/Laiko-matavimas
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return std::chrono::duration<double>
                (std::chrono::high_resolution_clock::now() - start).count();
    }
};

#endif