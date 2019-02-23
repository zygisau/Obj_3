# Duomenų apdorojimas
![version][version-badge]
## Programos paskirtis
Programa simuliuoja studentų pažymių sistemą. 

Vartotojas gali pasirinkti, ar studentus su pažymiais nuskaitys iš failo, ar ranka. Failas, į kurį vartotojas gali surašyti studentus bei jų pažymius, pavadinimu – "kursiokai.txt".

Pasirinkus įrašymą ranka, prašoma suvesti studento duomenis (vardą, pavardę, pažymius, egzamino pažymį ir t. t.). Viską užpildžius,  gaunama lentelė su studentų rezultatais.
Rezultatai skaičiuojami pagal formulę: 

```shell 
galutinis = 0.4 * dauginamasis + 0.6 * egzaminas
```
"dauginamasis" gali būti pažymių vidurkis arba mediana. Atspausdinami abudu variantai.

Taip pat yra galimybė pasirinkti, jog pažymiai būtų sugeneruoti atsitiktinai.
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

### [v0.3](https://github.com/zygisau/Duomenu-apdorojimas/releases/tag/v0.3) - (2019-02-23)

   **Koreguota**

   - Perkurta programos struktūra.
   - Pakoreguotas "READ_ME.md" failas.

   **Pridėta**

   - Pridėti headers failai.

[version-badge]: https://img.shields.io/badge/version-0.3-blue.svg
