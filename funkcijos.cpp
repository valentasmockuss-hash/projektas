#include "funkcijos.h"

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>

using namespace std;

bool sveikasSkaicius(const string& tekstas, int& skaicius){
    istringstream srautas(tekstas);
    char papildomas;
    return (srautas>>skaicius) && !(srautas>>papildomas);
}

int ivestiSkaiciu(const string& klausimas, int nuo, int iki){
    string eilute;
    int skaicius;
    while (true){
        cout<<klausimas;
        if (!getline(cin, eilute)) return -1;
        if(sveikasSkaicius(eilute, skaicius) && skaicius>= nuo && skaicius <= iki){
            return skaicius;
            }
        cout<<"Iveskite sveikaji skaiciu nuo" << nuo << " iki "<< iki << ".\n";
    }
}

bool ivestiVarda(const string& klausimas, string& vardas){
    string eilute, papildomas;

    while (true){
        cout<<klausimas;
        if(!getline(cin, eilute)) return false;
        istringstream srautas(eilute);
        if((srautas>>vardas)&& !(srautas>>papildomas)){
            return true;
        }
        cout<<"Iveskite viena netuscia zodi.\n";
    }
}
double vidurkis (const vector<int>& nd){
    if (nd.empty()) return 0.0;
    double suma=0.0;
    for (int pazymys : nd){
        suma +=pazymys;
    }
    return suma/nd.size();
}

double mediana(vector<int> nd){
    if (nd.empty()) return 0.0;
    sort(nd.begin(), nd.end());
    size_t n=nd.size();

    if (n%2==1){
        return nd[n/2];
    }
    return (nd[n/2-1]+nd[n/2])/2.0;
}
double galutinis(double ndRezultatas, int egzaminas){
    return 0.4*ndRezultatas + 0.6*egzaminas;
}

bool ivestiStudenta(vector<Studentas>& studentai){
    Studentas studentas;
    if(!ivestiVarda("Vardas: ", studentas.vardas)) return false;
    if(!ivestiVarda("Pavarde: ", studentas.pavarde)) return false;
    cout<<"Veskite po viena ND pazymi (0-10). Tuscia eilute baigia ivedima.\n";

    string eilute;
    while (true) {
        cout<<"ND"<<studentas.nd.size() + 1<<": ";
        if (!getline(cin, eilute)) return false;
        if(eilute.find_first_not_of(" \t\r")==string::npos){
            if(!studentas.nd.empty()) break;
            cout<< "Reikia bent vieno namu darbo pazymio.\n";
            continue;
        }
        int pazymys;
        if(sveikasSkaicius(eilute, pazymys) && pazymys>=0 && pazymys<=10){
            studentas.nd.push_back(pazymys);
        }else{
            cout<<"Netinkamas pazymys. Iveskite sveikaji skaiciu nuo 0 iki 10.\n";
        }
    }
    studentas.egzaminas=ivestiSkaiciu("Egzamino pazymys (0-10): ", 0, 10);
    if(studentas.egzaminas==-1) return false;

    studentai.push_back(studentas);
    return true;
    
}

size_t simboliuKiekis(const string& tekstas){
    size_t kiek=0;
    for(unsigned char simbolis:tekstas){
        if ((simbolis & 0xC0)!=0x80) ++kiek;
    }
    return kiek;
}
void tekstoStulpelis(ostream& isvestis, const string& tekstas, size_t plotis) {
    isvestis<<tekstas<<string(plotis-simboliuKiekis(tekstas), ' ');
}
void spausdinti(const vector<Studentas>& studentai, ostream& isvestis, int budas){
    size_t pavardesPlotis=16, vardoPlotis=16;

    for(const Studentas& s:studentai){
        pavardesPlotis=max(pavardesPlotis, simboliuKiekis(s.pavarde)+2);
        vardoPlotis=max(vardoPlotis, simboliuKiekis(s.vardas)+2);
    }
    tekstoStulpelis(isvestis, "Pavarde", pavardesPlotis);
    tekstoStulpelis(isvestis, "Vardas", vardoPlotis);
    isvestis<<left;
    if(budas!=2) isvestis<<setw(20)<<"Galutinis (Vid.)";
    if(budas!=1) isvestis<<setw(20)<<"Galutinis (Med.)";
    size_t plotis=pavardesPlotis + vardoPlotis +(budas==3?40:20);
    isvestis<< '\n'<<string(plotis, '-')<<'\n';
    isvestis<<fixed<<setprecision(2);

    for(const Studentas& s:studentai){
        tekstoStulpelis(isvestis, s.pavarde, pavardesPlotis);
        tekstoStulpelis(isvestis, s.vardas, vardoPlotis);

        if(budas!=2){
            isvestis<<setw(20)<<galutinis(vidurkis(s.nd), s.egzaminas);
        }
        if(budas !=1){
            isvestis<<setw(20)<<galutinis(mediana(s.nd), s.egzaminas);
        }
        isvestis<<'\n';
    }
}
bool generuotiStudenta(vector<Studentas>& studentai, mt19937& generatorius){
    Studentas studentas;
    if (!ivestiVarda("Vardas: ", studentas.vardas)) return false;
    if (!ivestiVarda("Pavarde: ", studentas.pavarde)) return false;

    int kiek=ivestiSkaiciu("Kiek ND pazymiu generuoti (1-1000)? ", 1, 1000);
    if (kiek==-1) return false;
    uniform_int_distribution<int> pazymys(1, 10);
    for (int i=0; i<kiek; ++i){
        studentas.nd.push_back(pazymys(generatorius));
    }
    studentas.egzaminas=pazymys(generatorius);
    cout<<"Sugeneruoti ND: ";
    for (int nd:studentas.nd) cout<<nd<< ' ';
    cout<<"\nEgzaminas: "<<studentas.egzaminas<<'\n';

    studentai.push_back(studentas);
    return true;
}
bool skaitytiFaila(const string& kelias, vector<Studentas>& studentai){
    ifstream failas(kelias);
    if(!failas){
        cout<<"Nepavyko atidaryti failo.\n";
        return false;
    }
    string eilute, zodis;
    getline(failas, eilute);
    if (eilute.compare(0, 3, "\xEF\xBB\xBF")==0) eilute.erase(0, 3);

    istringstream antrasteSrautas(eilute);
    vector<string> antraste;
    while (antrasteSrautas>>zodis) antraste.push_back(zodis);
    if(antraste.size()<4){
        cout<<"Netinkama failo antraste.\n";
        return false;
    }
    bool vardasPirmas=antraste[0]=="Vardas" && (antraste[1]=="Pavarde"||antraste[1]=="Pavardė");
    bool pavardePirma=(antraste[0]=="Pavarde"||antraste[0]=="Pavardė")&&antraste[1]=="Vardas";
    if(!vardasPirmas && !pavardePirma){
        cout<<"Antrasteje turi buti Vardas Pavarde arba Pavarde Vardas.\n";
        return false;
    }
    vector<Studentas> nuskaityti;
    size_t numeris=1;
    while (getline(failas, eilute)) {
        ++numeris;
        if (eilute.find_first_not_of(" \t\r")==string::npos) continue;
        istringstream srautas(eilute);
        Studentas s;
        bool tinkama=static_cast<bool>(srautas>>s.vardas>>s.pavarde);
        if(pavardePirma) swap(s.vardas, s.pavarde);

        while(srautas>>zodis){
            int pazymys;
            if(!sveikasSkaicius(zodis, pazymys)||pazymys<0||pazymys>10){
                tinkama=false;
                break;
            }
            s.nd.push_back(pazymys);
        }
        if (!tinkama||s.nd.size() != antraste.size() - 2){
            cout<<"Netinkami duomenys eiluteje"<<numeris<<".\n";
            return false;
        }
        s.egzaminas=s.nd.back();
        s.nd.pop_back();
        nuskaityti.push_back(s);
    }
    if (!failas.eof() || nuskaityti.empty()){
        cout<<"Failas tuscias arba jo nuskaityti nepavyko.\n";
        return false;
    }
    studentai.swap(nuskaityti);
    cout<<"Nuskaityta studentu:"<<studentai.size() << '\n';
    return true;
}
bool pagalPavarde(const Studentas& a, const Studentas& b){
    if (a.pavarde==b.pavarde) return a.vardas<b.vardas;
    return a.pavarde<b.pavarde;
}
bool pagalVarda(const Studentas& a, const Studentas& b){
    if (a.vardas==b.vardas) return a.pavarde<b.pavarde;
    return a.vardas<b.vardas;
}

bool generuotiFaila(int kiek, mt19937&generatorius) {
    string kelias="gen_studentai" + to_string(kiek)+".txt";

    ifstream esamas(kelias);
    if (esamas) {
        cout<<"Failas jau yra: "<< kelias<< '\n';
        return false;
    }
    auto pradzia = chrono::steady_clock::now();

    ofstream failas(kelias);
    if (!failas){
        cout<<"Nepavyko sukurti failo.\n";
        return false;
    }
    const int ndKiekis=10;
    uniform_int_distribution<int> pazymys(1, 10);

    failas<<"Vardas Pavarde";
    for (int j=1; j<=ndKiekis; ++j){
        failas<<" ND"<<j;
    }
    failas<<" Egzaminas\n";

    for(int i=1; i<=kiek; ++i){
        failas<<"Vardas"<<i<<" Pavarde" << i;

        for(int j=0; j<ndKiekis; ++j){
            failas<< ' '<< pazymys(generatorius);
        }
        failas<< ' ' <<pazymys(generatorius)<<'\n';
    }
    failas.close();
    auto pabaiga=chrono::steady_clock::now();

    if(!failas) {
        cout<<"Klaida irasant faila.\n";
        return false;
    }
    double sekundes=chrono::duration<double>(pabaiga-pradzia).count();

    cout<<"Sukurtas failas: "<<kelias<<'\n';
    cout<<"Studentu skaicius: "<<kiek<< '\n';
    cout<<fixed<<setprecision(6)<<"Generavimo laikas: "<<sekundes<<" s\n";

    return true;
}

double studentoBalas(const Studentas& s, int budas){
    double ndBalas=(budas==1) ? vidurkis(s.nd) : mediana(s.nd);
    return galutinis(ndBalas, s.egzaminas);
}

size_t skirstytiStudentus(vector<Studentas>& studentai, int budas) {
    auto riba = partition(studentai.begin(), studentai.end(),
    [budas](const Studentas& s){
        return studentoBalas(s, budas)<5.0;
    });
    return static_cast<size_t>(riba-studentai.begin());
}

bool irasytiGrupe(const vector<Studentas>& studentai, size_t nuo,
                    size_t iki, const string& kelias, int budas){
    ofstream failas(kelias);
    if (!failas) return false;
    failas <<"Pavarde Vardas Galutinis\n";
    failas<<fixed<<setprecision(2);

    for(size_t i=nuo; i<iki; ++i){
        const Studentas& s=studentai[i];

        failas<<s.pavarde<<' '<<s.vardas<<' '<<studentoBalas(s, budas)<<'\n';
    }
    failas.close();
    return static_cast<bool>(failas);
 }

 void tirtiSparta (const string& kelias, int budas){
    ofstream zurnalas("matavimai.txt", ios::app);
    if (!zurnalas){
        cout<<"Nepavyko atidaryti matavimo failo.\n";
        return;
    }

    for(int bandymas=1; bandymas<=3; ++bandymas){
        vector<Studentas> duomenys;
        cout<<"\nBandymas "<<bandymas<<" is 3\n";

        auto t0=chrono::steady_clock::now();
        if(!skaitytiFaila(kelias, duomenys)) return;
        auto t1=chrono::steady_clock::now();

        size_t riba=skirstytiStudentus(duomenys, budas);
        auto t2=chrono::steady_clock::now();

        bool pirmas=irasytiGrupe(
            duomenys, 0, riba, "vargsiukai.txt", budas);
        auto t3=chrono::steady_clock::now();

        bool antras=irasytiGrupe(
            duomenys, riba, duomenys.size(), "kietiakai.txt", budas);
        auto t4=chrono::steady_clock::now();

        if(!pirmas||!antras) {
            cout<<"Klaida irasant grupes. Bandymas neissaugotas.\n";
            return;
        }
        double skaitymas=chrono::duration<double>(t1-t0).count();
        double skirstymas=chrono::duration<double>(t2-t1).count();
        double pirmoIrasymas=chrono::duration<double>(t3-t2).count();
        double antroIrasymas=chrono::duration<double>(t4-t3).count();
        double visas=chrono::duration<double>(t4-t0).count();

        ostringstream ataskaita;
        ataskaita<<fixed<<setprecision(6)
        <<"\nFailas: "<<kelias<<'\n'
        <<"Budas: "<<(budas==1?"vidurkis" : "mediana")<<'\n'
        <<"Bandymas: "<<bandymas<<'\n'
        <<"Studentu: "<<duomenys.size()<<'\n'
        <<"Vargsiuku: "<<riba<<'\n'
        <<"Kietiaku: "<<duomenys.size() - riba<<'\n'
        <<"Skaitymas: "<<skaitymas<<" s\n"
        <<"Skirstymas: "<<skirstymas<<" s\n"
        <<"Vargsiuku irasymas: "<<pirmoIrasymas<<" s\n"
        <<"Kietiaku irasymas: "<<antroIrasymas<<" s\n"
        <<"Bendras laikas: "<<visas<<" s\n";

        cout<<ataskaita.str();
        zurnalas<<ataskaita.str();
        zurnalas.flush();

        if(!zurnalas){
            cout<<"Klaida issaugant matavimus.\n";
            return;
        }
    }
    cout<<"Matavimai prideti i matavimai.txt\n";
 }