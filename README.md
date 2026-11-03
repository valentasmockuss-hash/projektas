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

funckijos.h - Funkcijų deklaracijos.

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

