#Studentu galutinio balo skaiciavimas

programa parasyta c++ kalba. 
Studento duomenys: vardas, pavarde, namu darbu pazymiai ir egzamino pazymys.

#Pradines versijos galimybes

-ivesti keliu studentu duomenis
-ivesti is anksto nezinoma namu darbu pazymiu skaiciu
-generuoti atsitiktinius namu darbu ir egzamino pazymius
-skaiciuoti galutini bala pagal vidurki ir mediana
-rodyti abu rezultatus lenteleje dvieju skaitmenu po kablelio tikslumu
-tikrinti ivedamus pazymius ir meniu pasirinkimus

galutinis balas = 0,4 x namu darbu rezultatas + 0,6 x egzaminas

#paleidimas

g++ -std=c++17 -Wall -Wextra -Wpedantic "v0.1_projektas.cpp" -o studentai.exe
.\studentai.exe


#naudojimas

1 - ivesti studenta ir jo pazymius rankiniu budu
2 - pasirinkti skaiciavimo buda ir parodyti rezultatus
3 - ivesti studento varda, pavarde ir generuoti pazymius
0 - baigti programa

Vedant namu darbu pazymius rankiniu budu, tuscia eilute uzbaigia ivedima. Reikalingas bent vienas namu darbo pazymys. Rankiniu budu priimami pazymiai nuo 0 iki 10, atsitiktinai pazymiai generuojami nuo 1 iki 10.

Studentu duomenys saugomi programos veikimo metu, uzdarius programa, ivesti duomenys neissaugomi.