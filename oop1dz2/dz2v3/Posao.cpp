
#include "Posao.h"

int Posao::operator*() const {
    return satiRada;
}

int Posao::operator+() const {
    return budzet;
}

ostream &operator<<(ostream &os, Posao &p) {
    os << p.naziv << " " << p.budzet << ":" << p.satiRada << "h";
    return os;
}
