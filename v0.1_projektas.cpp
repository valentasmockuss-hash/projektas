#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <random>
#include <fstream>
#include "funkcijos.h"

using namespace std;



int main(){
  vector<Studentas> studentai;
  mt19937 generatorius(random_device{}());

  while(true) {
    cout<<"\n1 - Ivesti studenta\n"<<"2 - Parodyti rezultatus\n"<<"3 - Generuoti studento pazymius\n"
    <<"4 - Skaityti faila (pakeicia studentu sarasa)\n"<<"5 - Issaugoti rezultatus faile\n"
    <<"6 - Generuoti studentu faila\n"<<"7 - Suskirstyti studentus ir issaugoti grupes\n"
    <<"8 - Atlikti spartos tyrima\n"<<"0 - Baigti\n";


    int veiksmas=ivestiSkaiciu("Pasirinkimas: ", 0, 8);
    if (veiksmas==0||veiksmas==-1) break;
    if(veiksmas==1){
        if (!ivestiStudenta(studentai)) break;
    }else if (veiksmas==3){
        if (!generuotiStudenta(studentai, generatorius)) break;
    }else if (veiksmas==4){
        cout<<"Failo pavadinimas: ";
        string kelias;
        if(!getline(cin, kelias)) break;
        skaitytiFaila(kelias, studentai);
    } else if (veiksmas==6){
        cout<<"1 - 1000 studentu\n"<<"2 - 10000 studentu\n"<<"3 - 100000 studentu\n"
            <<"4 - 1000000 studentu\n"<<"5 - 10000000 studentu\n";
         
        int dydis= ivestiSkaiciu("Pasirinkite dydi: ", 1, 5);
        if (dydis==-1) break;

        const int kiekiai[]={
            1000, 10000, 100000, 1000000, 10000000
        };

        generuotiFaila(kiekiai[dydis - 1], generatorius);
    }else if(veiksmas==8){
        cout<< "Tiriamo failo pavadinimas: ";
        string kelias;
        if(!getline(cin, kelias)) break;
        int budas=ivestiSkaiciu("1 - vidurkis, 2 - mediana: ", 1, 2);
        if(budas==-1) break;
        tirtiSparta(kelias, budas);
    
    } else if (veiksmas==7){
        if (studentai.empty()){
            cout<<"Pirmiausia nuskaitykite arba iveskite studentus.\n";
            continue;
        }
        int budas=ivestiSkaiciu("Skirstyti pagal: 1 - vidurki, 2 - mediana: ", 1, 2);
        if (budas==-1) break;

        size_t riba=skirstytiStudentus(studentai, budas);

        bool pirmas=irasytiGrupe(
            studentai, 0, riba, "vargsiukai.txt", budas);
        
        bool antras=irasytiGrupe(
            studentai, riba, studentai.size(), "kietiakai.txt", budas);
        
        if (pirmas&&antras){
            cout<<"Vargsiuku: " <<riba<<'\n';
            cout<<"Kietiaku: "<<studentai.size() - riba<<'\n';
            cout<<"Grupes issaugotos i du failus.\n";
        } else{
            cout<<"Klaida irasant grupiu failus.\n";
        }
    }else {
        if (studentai.empty()){
            cout<<"Pirmiausia iveskite studentus.\n";
            continue;
        }
        int budas=ivestiSkaiciu("1 - vidurkis, 2 - mediana, 3 - abu: ", 1, 3);
        if (budas==-1) break;
        int tvarka=ivestiSkaiciu("Rikiuoti: 1 - pagal pavarde, 2 - pagal varda: ", 1, 2);
        if (tvarka==-1) break;
        if(tvarka==1){
            sort(studentai.begin(), studentai.end(), pagalPavarde);
        }else{
            sort(studentai.begin(), studentai.end(), pagalVarda);
        }
        if (veiksmas==5){
            ofstream rezultatai("rezultatai.txt");
            if(!rezultatai){
                cout<<"Nepavyko sukurti rezultatu failo.\n";
                continue;
            }
            spausdinti(studentai, rezultatai, budas);
            rezultatai.close();

            if(rezultatai){
                cout<<"Rezultatai issaugoti faile rezultatai.txt\n";
            }else {
                cout<<"Klaida irasant rezultatus.\n";
            }
        } else {
            spausdinti(studentai, cout, budas);
        }
    }
}
return 0;
}
        