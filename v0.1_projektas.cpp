#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas=0;
};
int main(){
    vector<Studentas> studentai;
    cout<<"Studentu pazymiu programa\n";
    cout<<"Studentu skaicius:"<<studentai.size()<<"\n";
    return 0;
}