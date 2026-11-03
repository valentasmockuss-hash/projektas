STUDENTŲ GALUTINIO BALO SKAIČIAVIMAS

C++17 programa studentų pažymiams apdoroti, studentams suskirstyti į grupes ir skirtingų skirstymo strategijų spartai palyginti.

Galutinis balas= 0.4 * namų darbų rezultatas + 0.6 * egzamino pažymys.

ND rezultatas skaičiuojamas pagal vidurkį arba medianą.
Galtuinis balas <5.0: vargšiukai
Galutinis balas >=5.0: kietiakai




VERSIJOS

Pradinė: rankinis studentų įvedimas, atsitiktiniai pažymiai, vidurkis, mediana.

v0.1: Duomenų skaitymas iš failo, rikiavimas pagal vardą arba pavardę, rezultatų išsaugojimas.

v0.2: Kodas išskaidytas į failus, pridėtas failų generavimas, grupių skirstymas, spartos tyrimas.

v0.3: Pridėtas list konteineris, sulyginta sparta tarp vector ir list, studento adresas atminty.

v1.0: Trys skirstymo strategijos abiem konteineriams, pridėtas cmake.




PROJEKTO FAILAI

v0.1_projektas.cpp - pagrindinė funkcija ir programos meniu.

studentas.h - Studentas truktūra.

funkcijos.h - Funkcijų deklaracijos.

funkcijos.cpp - įvedimas, skaičiavimai, failai, strategijos, spartos tyrimas.

CMakeLists.txt - kompiliavimas ir įdiegimas

strategiju_testas.txt - skirstymo teisingumui patikrinti kodo rašymo metu.

matavimai.txt - ankstesnių versijų matavimų rezultatai.

matavimai_v10.txt - v1.0 bandymai ir trijų bandymų vidurkiai.



KOMPILIAVIMAS IR DIEGIMAS WINDOWS APPLINKOJE

CMake 3.16 arba naujesnis, C++17 palaikantis g++ ir mingw32-make.

Projekto aplanke vykdyti:

cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build
cmake --install build --prefix "$PWD/diegimas"
.\diegimas\bin\studentai.exe



NAUDOJIMAS(meniu punktai)

1 - Įvesti studentą į vector arba list.
2 -  Parodyti vector studentų rezultatus, pasirinkti skaičiavimo ir rikiavimo būdą.
3 - Sugeneruoti vieno studento pažymius ir pridėti jį į vector.
4 - Nuskaityti failą į pasirinktą konteinerį, pakeičiant ankstesnį jo turinį.
5 - Išsaugoti vector rezultatus faile rezultatai.txt.
6 - Sugeneruoti pasirinkto dydžio studentų failą.
7 - Pasirinkti konteinerį ir strategiją, suskirstyti studentus ir išsaugoti grupes.
8 - Atlikti pasirinkto failo, konteinerio ir strategijos spartos tyrimą.'
0 -  Baigti programą.

Rankiniu būdu vedami pažymiai nuo 0 iki 10. Namų darbų įvedimą baigia tuščia eilutė, būtinas bent vienas pažymys.

Grupės rašomos į vargsiukai.txt ir kietiakai.txt. Ankstesnis rezultatų failų turinys perrašomas.



SKIRSTYMO STRATEGIJOS

0 - v0.3 būdas su partition, abi grupės laikomos pradiniame konteinery.
1 - studentai kopijuojami į du naujus to paties tipo konteinerius, pradinis konteineris išsaugomas.
2 - sukuriamas vargsiuku konteineris, pradiniame lieka kietiakai. Vector naudoja pakeitimą paskutiniu elementu ir pop_back, list naudoja erase.
3 - optimizuota antra strategija. Vector naudoja partition ir perkėlimą su make_move_iterator, list naudoja splice.

Po antros ar trečios strategijos pradiniame konteineryje lieka tik kietiakai. Norint pakartoti palyginimą su visais studentais, failą reikia nuskaityti iš naujo.

Spartos tyrime duomenys prieš kiekvieną bandymą automatiškai nuskaitomi iš naujo. Atliekami trys bandymai ir apskaičiuojami aritmetiniai vidurkiai.



v1.0 SPARTOS TYRIMAS

Galutinis balas skaičiuotas pagal namų darbų vidurkį.

Kiekvienam studentui sugeneruota 10 pažymių ir egzamino pažymys.

Abu konteineriai ir visos strategijos naudojo to paties dydžio failus.

Prieš kiekvieną bandymą failas nuskaityttas iš naujo.

Kiekvienas variantas išbandytas 3 kartus. Iš viso atlikta 120 bandymų su 5 failais.

Laikas matuotas su std::chrono::steady_clock. Generavimo laikas neįtrauktas.

Lentelėse pateikti trijų bandymū aritmetiniai vidkurkiai sekundėmis.



GRUPIŲ SKAIČIŲ PATIKRA

| Studentų | Vargšiukų | Kietiakų |
| ---: | ---: | ---: |
| 1000 | 430 | 570 |
| 10000 | 4102 | 5898 |
| 100000 | 41400 | 58600 |
| 1000000 | 413349 | 586651 |
| 10000000 | 4131970 | 5868030 |

(Lentelei spausti ctrl+shift+v)



VECTOR REZULTATAI

| Studentų | Strategija | Skaitymas, s | Skirstymas, s | Įrašymas, s | Bendras laikas, s |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 1000 | 0 | 0.013994 | 0.000082 | 0.008066 | 0.022141 |
| 1000 | 1 | 0.008180 | 0.000344 | 0.007178 | 0.015702 |
| 1000 | 2 | 0.008287 | 0.000229 | 0.008583 | 0.017099 |
| 1000 | 3 | 0.008727 | 0.000126 | 0.007335 | 0.016188 |
| 10000 | 0 | 0.063154 | 0.000715 | 0.018725 | 0.082595 |
| 10000 | 1 | 0.063967 | 0.003041 | 0.018893 | 0.085901 |
| 10000 | 2 | 0.065642 | 0.002561 | 0.018639 | 0.086841 |
| 10000 | 3 | 0.062539 | 0.000718 | 0.017253 | 0.080510 |
| 100000 | 0 | 0.552135 | 0.005446 | 0.157043 | 0.714625 |
| 100000 | 1 | 0.547481 | 0.025098 | 0.154933 | 0.727511 |
| 100000 | 2 | 0.551783 | 0.016920 | 0.156047 | 0.724749 |
| 100000 | 3 | 0.567604 | 0.007251 | 0.161185 | 0.736040 |
| 1000000 | 0 | 6.095827 | 0.062523 | 1.877454 | 8.035804 |
| 1000000 | 1 | 5.801925 | 0.313313 | 1.941759 | 8.056998 |
| 1000000 | 2 | 5.806269 | 0.157126 | 1.768512 | 7.731907 |
| 1000000 | 3 | 5.853694 | 0.122993 | 1.827192 | 7.803880 |
| 10000000 | 0 | 54.329688 | 0.787249 | 16.420619 | 71.537556 |
| 10000000 | 1 | 52.251440 | 4.248384 | 17.365183 | 73.865008 |
| 10000000 | 2 | 51.766811 | 1.373284 | 15.999755 | 69.139850 |
| 10000000 | 3 | 51.757495 | 0.824579 | 15.298396 | 67.880469 |

(Lentelei spausti ctrl+shift+v)




LIST REZULTATAI

| Studentų | Strategija | Skaitymas, s | Skirstymas, s | Įrašymas, s | Bendras laikas, s |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 1000 | 0 | 0.009281 | 0.000146 | 0.005958 | 0.015385 |
| 1000 | 1 | 0.007937 | 0.000381 | 0.004929 | 0.013247 |
| 1000 | 2 | 0.006639 | 0.000224 | 0.007401 | 0.014264 |
| 1000 | 3 | 0.007063 | 0.000071 | 0.005928 | 0.013062 |
| 10000 | 0 | 0.058720 | 0.001073 | 0.019642 | 0.079435 |
| 10000 | 1 | 0.059310 | 0.003496 | 0.018285 | 0.081091 |
| 10000 | 2 | 0.059104 | 0.001569 | 0.017405 | 0.078078 |
| 10000 | 3 | 0.066955 | 0.000922 | 0.021084 | 0.088961 |
| 100000 | 0 | 0.555127 | 0.009834 | 0.162863 | 0.727825 |
| 100000 | 1 | 0.551238 | 0.032683 | 0.159492 | 0.743414 |
| 100000 | 2 | 0.583628 | 0.021314 | 0.183024 | 0.787966 |
| 100000 | 3 | 0.794538 | 0.010188 | 0.218998 | 1.023725 |
| 1000000 | 0 | 6.279823 | 0.155884 | 2.053582 | 8.489289 |
| 1000000 | 1 | 5.832316 | 0.346133 | 1.861438 | 8.039886 |
| 1000000 | 2 | 5.826677 | 0.184329 | 1.875676 | 7.886682 |
| 1000000 | 3 | 5.802353 | 0.059867 | 1.857294 | 7.719514 |
| 10000000 | 0 | 52.045565 | 1.113439 | 15.523605 | 68.682609 |
| 10000000 | 1 | 52.206197 | 3.974090 | 17.066132 | 73.246420 |
| 10000000 | 2 | 52.220960 | 1.670229 | 15.641151 | 69.532340 |
| 10000000 | 3 | 52.642286 | 0.672492 | 17.550633 | 70.865410 |

(Lentelei spausti ctrl+shift+v)




IŠVADOS

Visuose dydžiuose antra strategija skirstė greičiau už pirmą abiem konteineriams. Trečia buvo greičiausia.

Su 10 mln. studentų vector skirstymas sutrumpėjo nuo 1.373284s antroje startegijoje iki 0.824579s trečioje. List sutrumpėjo nuo 1.670229s iki 0.672492s.

Ankstesnis vector būdas (0) skirstė per 0.787249s. Jis abi grupes palieka viename konteineryje, todėl jo atliekamas darbas skiriasi nuo trečios strategijos, kuri dar suformuoja atskirą vargsiuku konteinerį.



EKRANO NUOTRAUKOS

![Kompiliavimas ir paleidimas](vaizdai/paleidimas.png)

![Spartos tyrimo rezultatas](vaizdai/matavimai.png)
