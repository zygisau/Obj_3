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
Darbas su "kursiokai10.txt" užtruko: 0.0071854 s
Darbas su "kursiokai100.txt" užtruko: 0.0069441 s
Darbas su "kursiokai1000.txt" užtruko: 0.105918 s
Darbas su "kursiokai10000.txt" užtruko: 7.94196 s
Darbas su "kursiokai100000.txt" užtruko: 2484.67 s
```
(2484.67 sekundės yra ~41 minutės 😂)

### Pavyzdys
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
- Jei leidžiate UNIX aplinkoje
  - `make` <-- jei norite, jog programa veiktų, naudodama VEKTORIUS
  - `make masyvas` <-- jei norite, jog programa veiktų, naudodama MASYVUS
  - `make clean` <--jei reikia ištrinti **.o**, **.exe** failus
  - `make cleanAll` <--jei reikia ištrinti **.o**, **.exe** BEI klasiokai\* failus išskyrus klasiokai.txt
- Jei naudojate CMAKE, naudoti reikia CMakeLists.txt failą
> Naudojant CMAKE, naudoti masyvus kol kas neįmanoma.

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


[version-badge]: https://img.shields.io/badge/version-0.4.1-blue.svg
