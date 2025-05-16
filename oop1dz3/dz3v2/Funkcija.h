
#ifndef UNTITLED16_FUNKCIJA_H
#define UNTITLED16_FUNKCIJA_H
#include <iostream>
#include <string>
#include "Lista.h"
#include "Parametar.h"
using namespace std;

class Funkcija {
    string name;
    Lista<Parametar> lista;
public:
    Funkcija(string n){
        name = n;
    }
    Lista<Parametar>& addToTheFunction(Parametar* p);
    int getNumOfParameters()const;
    const Parametar& getParemeterFromPosition(int index) const;
    friend ostream& operator<< (ostream& os, const Funkcija& f);
};


#endif //UNTITLED16_FUNKCIJA_H
