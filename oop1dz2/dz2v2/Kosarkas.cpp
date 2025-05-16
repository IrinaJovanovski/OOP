
#include "Kosarkas.h"

const string &Kosarkas::getIme() const {
    return ime;
}

int Kosarkas::getGod() const {
    return god;
}

Kosarkas::pozicija Kosarkas::getPoz() const {
    return poz;
}

void Kosarkas::changePoz(Kosarkas::pozicija poz) {
    Kosarkas::poz = poz;
}

ostream &operator<<(ostream &os, const Kosarkas &k) {
    string pozicije[] = {"PG", "SG", "SF", "PF", "C"};
    os << k.getIme() << "(" << k.getGod() << ")" << ":" << pozicije[k.getPoz()];
    return os;
}
