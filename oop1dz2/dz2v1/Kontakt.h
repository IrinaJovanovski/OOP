#include <iostream>
#include <string>
#include "Broj.h"
using namespace std;

#ifndef UNTITLED14_KONTAKT_H
#define UNTITLED14_KONTAKT_H


class Kontakt {
    string ime;
    struct Elem {
        Broj *broj;
        Elem *sled;
        Elem (Broj &b) : broj(&b), sled(nullptr) {};
    };
    Elem* prvi = nullptr, *posl = nullptr;
    void kopiraj(const Kontakt& k);
    void premesti(Kontakt &k);
    void brisi();
public:
    Kontakt(string i, Broj &br) : ime(i) {prvi = new Elem(br); posl = prvi;}
    Kontakt(const Kontakt& k);
    Kontakt(Kontakt&& k);
    Kontakt& operator=(const Kontakt& k);
    Kontakt& operator=(Kontakt&& k);
    ~Kontakt();
    const string &getIme() const;
    Kontakt& operator+= (Broj &b);
    bool operator() (const Broj &b);
    friend ostream& operator<< (ostream &os, const Kontakt &k);
};


#endif //UNTITLED14_KONTAKT_H
