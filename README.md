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
Galutinis balas = 0.4*ND vidurkis + 0.6*egzamino pazymys.

Kiekvienas failas isbandytas 3 kartus. Pries kiekviena bandyma duomenys is naujo nuskaitomi is to paties is anksto sugeneruoto failo. Failu generavimas i apdorojimo laika neitrauktas

Laikas matuojamas naudojant std::chrono::steady_clock.
Pateikti triju bandymu aritmetiniai vidurkiai sekundemis.

|Studentu skc|Nuskaitymas, s|Skirstymas, s|Abieju failu irasymas, s|Bendras laikas,s|

| 1 000 | 0.007466 | 0.000124 | 0.011845 | 0.019436 |

| 10 000 | 0.059809 | 0.000530 | 0.017770 | 0.078109 |

| 100 000 | 0.505640 | 0.004893 | 0.142124 | 0.652658 |

| 1 000 000 | 5.185562 | 0.064612 | 1.627595 | 6.877770 |

| 10 000 000 | 54.912419 | 1.266966 | 14.488489 | 70.667874 |

Visu bandymu duomenys pateikti matavimai.txt

#Failu generavimo trukmes 

| 1 000 | 0.002892 |

| 10 000 | 0.012358 |

| 100 000 | 0.111678 |

| 1 000 000 | 1.104431 |

| 10 000 000 | 11.234791 |


#Rezultatai

Dideliuose failuose daugiausiai laiko uzima nuskaitymas: mazdaug 75% procentus bendros trukmes. Skirstymas i grupes trunka greokai trumpiau nei nuskaitymas ar rezultatu irasymas.

Visuose bandymuose abieju grupiu studentu skaiciu suma sutapo su nuskaitytu studentu skaiciumi.

#Versija v0.3 vector ir list palyginimas

 Kiekvienam konteineriui naudotas tas pats atitinkamo dydzio duomenu failas. Studentai pagal galutini bala suskirstyti i vargsiukus (balas < 5) ir kietiakus (balas >= 5). Laikas matuotas su std::chrono::steady_clock; lenteleje pateikti triju bandymu vidurkiai sekundemis. Failu generavimas i si laika neitrauktas.

| Studentu | Konteineris | Skaitymas, s | Skirstymas, s | Abieju failu irasymas, s | Bendras laikas, s |
| 1000 | vector | 0.017465 | 0.000067 | 0.112854 | 0.130386 |
| 1000 | list | 0.007848 | 0.000082 | 0.007723 | 0.015652 |
| 10000 | vector | 0.068446 | 0.000507 | 0.015637 | 0.084590 |
| 10000 | list | 0.054927 | 0.000887 | 0.015326 | 0.071140 |
| 100000 | vector | 0.582813 | 0.004706 | 0.158819 | 0.746337 |
| 100000 | list | 0.578949 | 0.010772 | 0.160829 | 0.750549 |
| 1000000 | vector | 5.290023 | 0.056593 | 1.460275 | 6.806890 |
| 1000000 | list | 5.148942 | 0.094643 | 1.482446 | 6.726031 |
| 10000000 | vector | 50.905487 | 0.554148 | 14.136797 | 65.596432 |
| 10000000 | list | 50.148580 | 0.947090 | 15.498790 | 66.594459 |

Skirstant 10 mln studentu vector uztruko vidutiniskai 0.554148s, list - 0.947090s. Bendras apdorojimo laikas buvo 65.596432s ir 66.594459s. 