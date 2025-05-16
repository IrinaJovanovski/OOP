#include <iostream>
#include <string>
using namespace std;

#ifndef DZ3_RADNIK_H
#define DZ3_RADNIK_H


class Radnik {
    int plata;
    int sati;
public:
    Radnik(int p, int s) : plata(p), sati(s){}
    int operator* () const;
    int operator+ () const;
};


#endif //DZ3_RADNIK_H
