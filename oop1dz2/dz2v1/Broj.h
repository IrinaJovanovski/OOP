#include <iostream>
#include <string>
using namespace std;

#ifndef UNTITLED14_BROJ_H
#define UNTITLED14_BROJ_H


class Broj {
    string kod_drzave;
    string pozivni;
    string korisnik;
public:
    Broj(string kd, string poz, string k) : kod_drzave(kd), pozivni(poz), korisnik(k){
        if(poz.length() != 2 || (k.length() < 5 || k.length() > 7)) exit(1);
    }
    friend bool operator== (const Broj &b1, const Broj &b2);
    friend ostream& operator<< (ostream &os, const Broj &b);
};


#endif //UNTITLED14_BROJ_H
