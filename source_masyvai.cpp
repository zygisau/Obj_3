#include <iostream>
#include <string>
#include <iomanip>
using std::cout; using std::cin; using std::endl; using std::string; using std::setw; using std::left; using std::setprecision; using std::fixed;

struct mokinys {
    string vardas;
    string pavarde;
    int *paz=nullptr;
    int egz=0;
    float vid=0;
    double galutinis=0;
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
        vid = (float)suma/n;
        galutinis = 0.4 * vid + 0.6 * (double)egz;
        sort();
        int sk = n/2;
        if (n % 2 == 0) {
            mediana = (float)(paz[sk] + paz[--sk])/2;
        } else {
            mediana = paz[--sk];
        }
    }
    void sort() {
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                if (paz[i]>paz[j]) std::swap(paz[i], paz[j]);
            }
        }
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
        cout << "Koks mokinio egzamino pazymys: ";
        cin >> mok[i].egz;
        mok[i].galutinio_sk();
    }
    cout << "Norite matyti galutini pazymi kaip vidurki (vid) ar mediana (med)? ";
    string pateiktis;
    cin >> pateiktis;
    cout << endl;
    if (pateiktis == "v" || pateiktis == "vi" || pateiktis == "vid") {
        cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
        for (int i = 0; i < 60; i++) cout << "-";
        cout << endl;
        for (int i = 0; i < sk; i++) {
            cout << setw(20) << mok[i].vardas << setw(20) << mok[i].pavarde << setw(20) << setprecision(2) << fixed
                 << mok[i].galutinis << endl;
        }
    } else if (pateiktis == "m" || pateiktis == "me" || pateiktis == "med") {
        cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis(Mod.)" << endl;
        for (int i=0; i<80; i++) cout << "-";
        cout << endl;
        for (int i=0; i<sk; i++) {
            cout  << setw(20) << mok[i].vardas << setw(20) << mok[i].pavarde << setw(20) << setprecision(2) << fixed << mok[i].mediana << endl;
        }
    }
}