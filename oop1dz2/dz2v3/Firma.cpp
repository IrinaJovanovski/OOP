
#include "Firma.h"
#include <cmath>

int Firma::brRadnika = 0;

Firma &Firma::operator+=(const Radnik *r) {
    posl = (!prvi ? prvi : posl->sled) = new Elem(r);
    brRadnika += 1;
    return *this;
}

int Firma::operator*(const Posao &p) {
    double sumaRadnihSati = 0;
    Firma::Elem *tek = prvi;
    while(tek){
        sumaRadnihSati += tek->radnik->operator*();
        tek = tek->sled;
    }
    return ceil(double(*p)/sumaRadnihSati);
}

int Firma::operator+(const Posao& p) {
    double sumaDnevnica = 0;
    Firma::Elem* tek = prvi;
    while (tek) {
        sumaDnevnica += tek->radnik->operator+();
        tek = tek->sled;
    }
    return ceil(sumaDnevnica * double((*this) * p) + sumaDnevnica * double((*this) * p) * (provizija / 100.));
}

ostream &operator<<(ostream &os, const Firma &f) {
    int sumaDnevnica = 0, sumaRadnihSati = 0;
    Firma::Elem *tek = f.prvi;
    while(tek){
        sumaDnevnica += tek->radnik->operator+();
        sumaRadnihSati += tek->radnik->operator*();
        tek = tek->sled;
    }
    os << f.ime << " (" << Firma::brRadnika << ", " << sumaDnevnica << ":" << sumaRadnihSati << "h)";
    return os;
}

void Firma::postaviIme(const string ime) {
    Firma::ime = ime;
}

void Firma::postaviProviziju(const int prov) {
    Firma::provizija = prov;
}
