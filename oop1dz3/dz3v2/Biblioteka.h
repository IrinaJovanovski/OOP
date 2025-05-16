
#ifndef UNTITLED16_BIBLIOTEKA_H
#define UNTITLED16_BIBLIOTEKA_H
#include "Funkcija.h"

class Biblioteka {
    Lista<Funkcija> funkcije;
public:
    Lista<Funkcija>& addToTheLibrary(Funkcija* f);
    const Funkcija& getParemeterFromPosition(int index) const;
    friend ostream& operator<< (ostream& os, const Biblioteka& b);
};


#endif //UNTITLED16_BIBLIOTEKA_H
