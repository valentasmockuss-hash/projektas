#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas=0;
};

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

int main(){
    Studentas s;
    s.vardas="Jonas";
    s.pavarde="Jonaitis";
    s.nd={10, 4, 9, 8};
    s.egzaminas=8;

    double ndVidurkis=vidurkis(s.nd);
    double ndMediana=mediana(s.nd);

    cout<<fixed<<setprecision(2);
    cout<<s.vardas<<" "<<s.pavarde<<"\n";
    cout<<"Galutinis (vidurkis):"<<galutinis(ndVidurkis, s.egzaminas)<<"\n";
    cout<<"Galutinis (mediana):"<<galutinis(ndMediana, s.egzaminas)<<"\n";
    return 0;
}

