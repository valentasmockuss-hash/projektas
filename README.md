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

g++ -std=c++17 -O2 -Wall -Wextra -Wpedantic "v0.1_projektas.cpp" "funkcijos.cpp" -o studentai.exe


#naudojimas

1 - ivesti studenta ir jo pazymius rankiniu budu
2 - pasirinkti skaiciavimo buda ir parodyti rezultatus
3 - ivesti studento varda, pavarde ir generuoti pazymius
4 - nuskaityti studentus is failo, pakeiciant dabartini sarasa
6 - issaugoti surusiuotus rezultatus faile rezultatai.txt
0 - baigti programa

Vedant namu darbu pazymius rankiniu budu, tuscia eilute uzbaigia ivedima. Reikalingas bent vienas namu darbo pazymys. Rankiniu budu priimami pazymiai nuo 0 iki 10, atsitiktinai pazymiai generuojami nuo 1 iki 10.

Ivesti duomenys automatiskai neissaugomi. Pasirinkus meniu punkta 5, galutiniai rezultatao irasomi i rezultatai.txt. Ankstesnis sio failo turinys perrasomas.


#Versija v0.1

Pridetas studentu skaitymas is failo, rusiavimas pagal varda arba pavarde ir rezultatu issaugojimas faile rezultatai.txt.

Duomenu failo pirmoje eiluteje pateikiamos stulpeliu antrastes: Vardas Pavarde ND1 ND2...Egzaminas.
Pirmuju dvieju stulpeliu tvarka galima ir atvirkstine. Paskutinis pazymys yra egzamino rezultatas, o namu darbu skaicius nustatomas pagal antraste.

#patikrinimai

Pradzioje atlikti patikrinimai su kursiokai.txt: galutiniai balai pagal vidurki ir mediana, rusiavimai pagal pavardes arba vardus.

Su destytojo failais patikrintas nuskaitytu studentu skaicius.


#Versija v0.2

*Failas isskaidytas i du .cpp ir du .h failus

*Generuojami oenkiu dydziu studentu failai: 1000, 10000, 100000, 1000000, 10000000

*Kiekvienam studentui generuojama 10 namu darbu pazymiu ir egzamino pazymys 1-10

*Studentai skirstomi pagal galutini bala:
maziau nei 5 - vargsiukai.txt,
5 arba daugiau - kietiakai.txt

*Skirstymui naudojama std::partition. Abi grupes laikomos viename vektoriuje, nekuriant papildomu studentu kopiju.

*Galima pasirinkti skaiciavima pagal vidurki arba medina


#Spartos tyrimis

Tyrimas atliktas pagal namu darbu vidurki.
Galutinis balas = 0.4*ND vidurkis + egzamino pazymys.

Kiekvienas failas isbandytas 3 kartus. Pries kiekviena bandyma duomenys is naujo nuskaitomi is to paties is anksto sugeneruoto failo. Failu generavimas i apdorojimo laika neitrauktas

Laikas matuojamas naudojant std::chrono::steady_clock.
Pateikti triju bandymu aritmetiniai vidurkiai sekundemis.

Studentu skc|Nuskaitymas, s|Skirstymas, s|Abieju failu irasymas, s|Bendras laikas,s|

| 1 000 | 0.007466 | 0.000124 | 0.011845 | 0.019436 |
| 10 000 | 0.059809 | 0.000530 | 0.017770 | 0.078109 |
| 100 000 | 0.505640 | 0.004893 | 0.142124 | 0.652658 |
| 1 000 000 | 5.185562 | 0.064612 | 1.627595 | 6.877770 |
| 10 000 000 | 54.912419 | 1.266966 | 14.488489 | 70.667874 |

Visu bandymu duomenys pateikti matavimai.txt

#Rezultatai

Dideliuose failuose daugiausiai laiko uzima nuskaitymas: mazdaug 75% procentus bendros trukmes. Skirstymas i grupes trunka greokai trumpiau nei nuskaitymas ar rezultatu irasymas.

Visuose bandymuose abieju grupiu studentu skaiciu suma sutapo su nuskaitytu studentu skaiciumi.
