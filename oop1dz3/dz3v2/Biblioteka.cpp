

#include "Biblioteka.h"

Lista<Funkcija> &Biblioteka::addToTheLibrary(Funkcija *f) {
    funkcije += f;
    return funkcije;
}

const Funkcija &Biblioteka::getParemeterFromPosition(int index) const {
    return *(funkcije[index]);
}

ostream &operator<<(ostream &os, const Biblioteka &b) {
    for(int i = 0; i < b.funkcije.getNumOfElements(); i++){
        os << b.getParemeterFromPosition(i);
    }
    return os;
}
