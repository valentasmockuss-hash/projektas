#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas=0;
};
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
int main(){
   vector<Studentas> studentai;
   if(!ivestiStudenta(studentai)) return 0;
   const Studentas& s=studentai.back();

    double ndVidurkis=vidurkis(s.nd);
    double ndMediana=mediana(s.nd);

    cout<<fixed<<setprecision(2);
    cout<<s.vardas<<" "<<s.pavarde<<"\n";
    cout<<"Galutinis (vidurkis):"<<galutinis(ndVidurkis, s.egzaminas)<<"\n";
    cout<<"Galutinis (mediana):"<<galutinis(ndMediana, s.egzaminas)<<"\n";
    return 0;
}

