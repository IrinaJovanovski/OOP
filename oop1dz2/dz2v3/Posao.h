#include "Radnik.h"

#ifndef DZ3_POSAO_H
#define DZ3_POSAO_H


class Posao {
    string naziv;
    int satiRada;
    int budzet;
public:
    Posao(string n, int s, int b) : naziv(n), satiRada(s), budzet(b){}
    int operator* () const;
    int operator+ () const;
    friend ostream& operator<< (ostream &os, Posao &p);
};


#endif //DZ3_POSAO_H
