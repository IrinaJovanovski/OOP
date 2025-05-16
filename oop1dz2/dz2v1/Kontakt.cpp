
#include "Kontakt.h"

const string &Kontakt::getIme() const {
    return ime;
}

Kontakt &Kontakt::operator+=(Broj &b) {
    posl = ((!prvi) ? prvi : posl->sled) = new Elem(b);
    return *this;
}

bool Kontakt::operator()(const Broj &b) {
    Elem *tek = prvi;
    while(tek){
        if(*(tek->broj) == b){
            return true;
        }
        tek = tek->sled;
    }
    return false;
}

ostream &operator<<(ostream &os, const Kontakt &k) {
    os << k.getIme() << " (";
    Kontakt::Elem *tek = k.prvi;
    while(tek){
        os << *(tek->broj);
        tek = tek->sled;
        if(tek){
            os << ", ";
        }
    }
    os << ")";
    return os;
}

void Kontakt::brisi() {
    while(prvi){
        Elem *stari = prvi;
        prvi = prvi->sled;
        delete stari;
    }
    prvi = posl = nullptr;
}

void Kontakt::kopiraj(const Kontakt &k) {
    ime = k.ime;
    Elem *tek = k.prvi;
    this->brisi();
    while(tek){
        *this += *(tek->broj);
        tek = tek->sled;
    }
}

void Kontakt::premesti(Kontakt &k) {
    ime = k.ime;
    prvi = k.prvi;
    posl = k.posl;
    k.prvi = k.posl = nullptr;
}

Kontakt::~Kontakt() {
    brisi();
}

Kontakt::Kontakt(const Kontakt &k) {
    kopiraj(k);
}

Kontakt::Kontakt(Kontakt &&k) {
    premesti(k);
}

Kontakt &Kontakt::operator=(const Kontakt &k) {
    if(this != &k){
        kopiraj(k);
    }
    return *this;
}

Kontakt &Kontakt::operator=(Kontakt &&k) {
    if(this != &k){
        premesti(k);
    }
    return *this;
}



