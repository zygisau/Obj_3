# Duomenų apdorojimas
![version][version-badge]
## Programos paskirtis
Programa simuliuoja studentų pažymių sistemą. Suvedus visus prašomus duomenis (vardą, pavardę, pažymius, egzamino pažymį ir t. t.) arba juos nuskaičius iš failo, gaunama lentelė su studentų rezultatais.
Rezultatai skaičiuojami pagal formulę: 
```shell 
galutinis = 0.4 * dauginamasis + 0.6 * egzaminas
```
"dauginamasis" gali būti pažymių vidurkis arba mediana. Vartotojui leidžiama pasirinkti prieš rezultatų išvedimą. Nuskaitant duomenis iš failo, bus pateikti abudu atsakymai.

Taip pat yra galimybė pasirinkti, jog pažymiai būtų sugeneruoti atsitiktinai.
### Pavyzdys
```shell
Vardas              Pavardė            Galutinis (Vid.)    
------------------------------------------------------------
Jonas               Jonaitis            7.31                
Petras              Petrauskas          6.33
```

## Programos paleidimas
Paleisti programą galima keliais būdais.
- `git clone git@github.com:zygisau/Duomenu-apdorojimas.git` <-- jei naudojate SSH key
- `git clone https://github.com/zygisau/Duomenu-apdorojimas.git` <-- kitu atveju
- `cd Duomenu-apdorojimas`
- `make` <-- jei norite, jog programa veiktų, naudodama VEKTORIUS
- `make masyvas` <-- jei norite, jog programa veiktų, naudodama MASYVUS

## Versijų istorija (changelog)
   
   ### [v0.1](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.1) - (2019-02-17)
   
   **Koreguota**
   
   - Sutvarkytas README.md failas.
   - Papildytas .gitignore failas.
    
   **Pridėta**
   
   - Sukurtos dvi programos. Viena veikia, remiantis C masyvais, kita - vector.
   - Sukurtas makefile.
   
   ### [v0.2](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.2) - (2019-02-17)
   
   **Koreguota**
   
   - README.md faile pridėtas versijos aprašymas.
    
   **Pridėta**
   
   - Pakeista source_vektoriai.cpp programa taip, jog galima būtų duomenis kelti iš failo bei pakeistas vaizdavimo būdas.
   - Sukurtas duomenų apie studentus failas "kursiokai.txt".

[version-badge]: https://img.shields.io/badge/version-0.2-blue.svg
