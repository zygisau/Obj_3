#include <iostream>
#include <string>
#include <iomanip>
using std::cout; using std::cin; using std::endl; using std::string; using std::setw;

struct mokinys {
    string vardas;
    string pavarde;
    int *paz=nullptr;
    int egz=0;
    float vid=0;
    float galutinis=0;
    float mediana=0;
    int n=0;
    void paz_ived() {
        paz = new int [n];
        for (int i=0; i<n; i++) {
            cout << "Pazymys: ";
            cin >> paz[i];
        }
    }
    void galutinio_sk() {
        int suma = 0;
        for (int i=0; i<n; i++) {
            suma += paz[i];
        }
        vid = (double)suma/n;
        galutinis = 0.4 * vid + 0.6 * egz;
    }
    void mediana() {
        
    }
};
//
//
int main() {
    int sk;
    cout << "Kiek mokiniu ivedinesite: ";
    cin >> sk;
    mokinys *mok = new mokinys[sk];
    for (int i=0; i<sk; i++) {
        cout << "Iveskite mokinio varda: ";
        cin >> mok[i].vardas;
        cout << "Iveskite mokinio pavarde: ";
        cin >> mok[i].pavarde;
        cout << "Kiek pazymiu ivesite: ";
        cin >> mok[i].n;
        cout << "Iveskite pazymius" << endl;
        mok[i].paz_ived();
        mok[i].mediana();
        cout << "Koks mokinio egzamino pazymys: ";
        cin >> mok[i].egz;
        mok[i].galutinio_sk();
    }
    cout << std::left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis(Mod.)" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i=0; i<sk; i++) {
        cout  << setw(20) << mok[i].vardas << setw(20) << mok[i].pavarde << setw(20) << mok[i].galutinis << setw(20) << mok[i].mediana << endl;
    }
}