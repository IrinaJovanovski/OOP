
#include "Broj.h"

bool operator==(const Broj &b1, const Broj &b2){
    if(b1.kod_drzave == b2.kod_drzave && b1.pozivni == b2.pozivni && b1.korisnik == b2.korisnik) return true;
    return false;
}

ostream &operator<<(ostream &os, const Broj &b) {
    os << "+" << b.kod_drzave << " " << b.pozivni << " " << b.korisnik;
    return os;
}
