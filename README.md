
# Duomenų apdorojimas  
![version][version-badge]  
## Programos paskirtis  
Programa simuliuoja studentų pažymių sistemą.   
  
Vartotojas gali pasirinkti, ar studentus su pažymiais nuskaitys iš failo, ar ranka.  
  
### Įrašymas ranka  
Pasirinkus įrašymą ranka, prašoma suvesti studento duomenis (vardą, pavardę, pažymius, egzamino pažymį ir t. t.). Viską užpildžius, į failą gaunama lentelė su studentų rezultatais.  
  
### Pažymių generavimas  
Galima pasirinkti pažymius sugeneruoti. Tokiu atveju prašoma įvesti, kiek pažymių generuoti.  
  
### Įrašymas iš failo  
Failas, į kurį vartotojas gali surašyti studentus bei jų pažymius, pavadinimu – "kursiokai.txt".  
Iš jo nuskaitomi studentai.  
  
### Rezultatai  
Rezultatai skaičiuojami pagal formulę:   
  
```shell   
galutinis = 0.4 * dauginamasis + 0.6 * egzaminas  
```  
"dauginamasis" gali būti pažymių vidurkis arba mediana. Atspausdinami abudu variantai.  
  
Taip pat yra galimybė pasirinkti, jog pažymiai būtų sugeneruoti atsitiktinai.  
  
### Greičio matavimas  
Taip pat galima pasirinkti sugeneruoti failus:  
- kursiokai10.txt – turintis 10 studentų  
  
- kursiokai100.txt – turintis 100 studentų  
  
- kursiokai1000.txt – turintis 1000 studentų  
  
- kursiokai10000.txt – turintis 10000 studentų  
  
- kursiokai100000.txt – turintis 100000 studentų  
  
  Su šiais tekstiniais failais atliekama greičio analizė, naudojant [std::chrono](https://en.cppreference.com/w/cpp/chrono) biblioteką. Programai baigus darbą, į konsolę atspausdinama lentelė su laikais:  
  
```shell  
Ar norite atlikti programos veikimo greičio (spartos) analizę? (1 - taip, 0 - ne) 1  

Darbas su "kursiokai10.txt" užtruko: 0.015957 s
Darbas su "kursiokai100.txt" užtruko: 0.016956 s
Darbas su "kursiokai1000.txt" užtruko: 0.059678 s
Darbas su "kursiokai10000.txt" užtruko: 0.320595 s
Darbas su "kursiokai100000.txt" užtruko: 3.16505 s
```  
  
### Konteinerių testavimas  
  
Testuojami šie konteineriai  
  
- std::vector  
- std::list  
- std::deque  
  
#### Rezultatas  
  
```shell  
...  
Ar norite atlikti konteinerių testavimą? (1 - taip, 0 - ne)  
1  
  
Pradedamas darbas naudojant vector konteinerį...  
Nuskaitymas iš failo truko: 0 s  
Studentų filtravimas (skirstymas) truko: 0 s  
įrašymas į failą truko: 0.0072953 s  
Darbas su "kursiokai10.txt" užtruko: 0.0072953 s  
  
Nuskaitymas iš failo truko: 0 s  
Studentų filtravimas (skirstymas) truko: 0 s  
įrašymas į failą truko: 0.0136461 s  
Darbas su "kursiokai100.txt" užtruko: 0.0136461 s  
  
Nuskaitymas iš failo truko: 0.0081595 s  
Studentų filtravimas (skirstymas) truko: 0.0578434 s  
įrašymas į failą truko: 0.0290793 s  
Darbas su "kursiokai1000.txt" užtruko: 0.107586 s  
  
Nuskaitymas iš failo truko: 0.123461 s  
Studentų filtravimas (skirstymas) truko: 5.53951 s  
įrašymas į failą truko: 0.0935523 s  
Darbas su "kursiokai10000.txt" užtruko: 5.75755 s  
  
Nuskaitymas iš failo truko: 0.774174 s  
Studentų filtravimas (skirstymas) truko: 809.702 s  
įrašymas į failą truko: 1.16679 s  
Darbas su "kursiokai100000.txt" užtruko: 811.673 s  
Darbas su STD::VECTOR konteineriu užtruko: 817.563 s  
  
Pradedamas darbas naudojant list konteinerį...  
Nuskaitymas iš failo truko: 0.0010365 s  
Studentų filtravimas (skirstymas) truko: 0.0010644 s  
įrašymas į failą truko: 0.0197029 s  
Darbas su "kursiokai10.txt" užtruko: 0.0246866 s  
  
Nuskaitymas iš failo truko: 0.0019967 s  
Studentų filtravimas (skirstymas) truko: 0.0006381 s  
įrašymas į failą truko: 0.0019932 s  
Darbas su "kursiokai100.txt" užtruko: 0.016478 s  
  
Nuskaitymas iš failo truko: 0.0019952 s  
Studentų filtravimas (skirstymas) truko: 0.0173109 s  
įrašymas į failą truko: 0.048476 s  
Darbas su "kursiokai1000.txt" užtruko: 0.0727771 s  
  
Nuskaitymas iš failo truko: 0.101094 s  
Studentų filtravimas (skirstymas) truko: 0.0310594 s  
įrašymas į failą truko: 0.15154 s  
Darbas su "kursiokai10000.txt" užtruko: 0.28776 s  
  
Nuskaitymas iš failo truko: 1.11357 s  
Studentų filtravimas (skirstymas) truko: 0.27484 s  
įrašymas į failą truko: 1.18493 s  
Darbas su "kursiokai100000.txt" užtruko: 2.62884 s  
Darbas su STD::LIST konteineriu užtruko: 3.03572 s  
  
Pradedamas darbas naudojant deque konteinerį...  
Nuskaitymas iš failo truko: 0.0009961 s  
Studentų filtravimas (skirstymas) truko: 0 s  
įrašymas į failą truko: 0.0180864 s  
Darbas su "kursiokai10.txt" užtruko: 0.0203142 s  
  
Nuskaitymas iš failo truko: 0.001098 s  
Studentų filtravimas (skirstymas) truko: 0 s  
įrašymas į failą truko: 0.0113803 s  
Darbas su "kursiokai100.txt" užtruko: 0.0166128 s  
  
Nuskaitymas iš failo truko: 0.0081304 s  
Studentų filtravimas (skirstymas) truko: 0.0610808 s  
įrašymas į failą truko: 0.041581 s  
Darbas su "kursiokai1000.txt" užtruko: 0.120541 s  
  
Nuskaitymas iš failo truko: 0.102246 s  
Studentų filtravimas (skirstymas) truko: 4.25611 s  
įrašymas į failą truko: 0.161089 s  
Darbas su "kursiokai10000.txt" užtruko: 4.52806 s  
  
Nuskaitymas iš failo truko: 1.15949 s  
Studentų filtravimas (skirstymas) truko: 423.546 s  
įrašymas į failą truko: 1.28583 s  
Darbas su "kursiokai100000.txt" užtruko: 426.042 s  
Darbas su STD::DEQUE konteineriu užtruko: 430.734 s  
```  
  
### Atspausdintas pavyzdys  
```shell  
Vardas       Pavardė      Galutinis (Vid.)       Galutinis (Med.)         
------------------------------------------------------------------------  
Aleksandras  Pavardė13    3.47                   3.80  
Austėja      Pavardė16    5.20                   4.80  
Emilija      Pavardė6     5.73                   5.60  
Emilis       Pavardė9     2.20                   2.00  
Gabija       Pavardė15    5.80                   5.80  
Giedrius     Pavardė17    7.93                   8.40  
Giedrė       Pavardė18    3.40                   3.20     
```  
  
## Programos paleidimas  
Paleisti programą galima keliais būdais.  
- `git clone git@github.com:zygisau/Duomenu-apdorojimas.git` <-- jei naudojate SSH key  
- `git clone https://github.com/zygisau/Duomenu-apdorojimas.git` <-- kitu atveju  
- `cd Duomenu-apdorojimas`  
- Jei naudojate CMAKE, naudoti reikia CMakeLists.txt failą.
Yra du *executables*:
--Duomenu_apdorojimas <-- pasirinkite, jei norite paleisti programą, kuri naudoja konteinerius
--Duomenu_apdorojimas_masyvai <-- pasirinkite, jei norite paleisti programą, kuri naudoja dinaminį masyvą
  
  
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
  
### [v0.3](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.3) - (2019-02-23)  
  
  **Koreguota**  
  
 - Perkurta programos struktūra.  
 - Pakoreguotas "READ_ME.md" failas.  
  
   **Pridėta**  
  
 - Pridėti headers failai.  
  
### [v0.4](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.4) - (2019-03-03)  
  
  **Koreguota**  
  
 - Pridėta galimybė atlikti spartos analizę bei generuoti tekstinius failus.  
 - Pakoreguotas "READ_ME.md" failas.  
  
   **Pridėta**  
  
 - Pridėtas CMakeLists.txt failas.  
  
### [v0.4.1](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.4.1) - (2019-03-04)  
  
  **Koreguota**  
  
 - Pridėta biblioteka "numeric", naudojama funkcijoje. Programa veiks naudojant visus kompiliatorius.  
  
### [v0.5](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.5) - (2019-03-11)  
  
  **Koreguota**  
  
- Pakoreguotas "READ_ME.md" failas.  
  
   **Pridėta**  
  
- Pridėtas konteinerių testavimas.  
  
### [v0.5.1](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.5.1) - (2019-03-13)  
  
  **Koreguota**  
- Pridėta apsauga, jei duomenų faile būtų pateiktas ne skaičius arba per mažai pažymių.  
  
### [v1.0](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v1.0) - (2019-03-17)  
  
  **Koreguota**  
  
- Pakoreguotas "READ_ME.md" failas.  
- Pakeistas studentų filtravimas, kai naudojamas std::vector konteineris. Dabar veikia greičiau.
- Pridėta galimybė paleisti iš CMake failo abidvi programos realizacijas
- Ištrintas makefile (CMake universalesnis).
  
[version-badge]: https://img.shields.io/badge/version-1.0-yellow.svg