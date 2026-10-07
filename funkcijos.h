#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <ostream>
#include <random>

int ivestiSkaiciu (const std::string& klausimas, int nuo, int iki);

double vidurkis(const std::vector<int>& nd);
double mediana(std::vector<int> nd);
double galutinis(double ndRezultatas, int egzaminas);

bool ivestiStudenta(std::vector<Studentas>& studentai);
bool generuotiStudenta(std::vector<Studentas>&studentai,
    std::mt19937&generatorius);
bool skaitytiFaila( const std::string&kelias,
    std::vector<Studentas>&studentai);

void spausdinti(const std::vector<Studentas>& studentai,
    std::ostream&isvestis,
    int budas);

bool pagalPavarde(const Studentas& a, const Studentas& b);
bool pagalVarda(const Studentas& a, const Studentas& b);
bool generuotiFaila(int kiek, std::mt19937&generatorius);
#endif