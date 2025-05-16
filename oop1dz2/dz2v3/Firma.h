#include "Posao.h"

#ifndef DZ3_FIRMA_H
#define DZ3_FIRMA_H


class Firma {
    string ime;
    int provizija;
    static int brRadnika;
    struct Elem {
        const Radnik *radnik;
        Elem *sled;
        Elem(const Radnik *rad) : radnik(rad), sled(nullptr){};
    };
    Elem *prvi = nullptr, *posl = nullptr;
public:
    Firma() = default;
    void postaviIme(string ime);
    void postaviProviziju(int provizija);
    Firma(const Firma&) = delete;
    Firma& operator= (const Firma&) = delete;
    Firma& operator+= (const Radnik *r);
    int operator* (const Posao &p);
    int operator+(const Posao &p);
    friend ostream& operator<< (ostream &os, const Firma &f);

};


#endif //DZ3_FIRMA_H
