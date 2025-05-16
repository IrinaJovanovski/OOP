
#ifndef UNTITLED18_FIGURA_H
#define UNTITLED18_FIGURA_H
#include "Greska.h"
#include "Polje.h"
#include "Lista.h"
class Figura {
protected:
    Polje& center;
    Lista<Polje> fields;
    Lista<bool> hits;
    char letter;
public:
    Figura(Polje& p) : center(p) {
        fields += center;
        hits += false;
    }
    virtual Figura& figuraCopy() const = 0;
    virtual ~Figura(){}
    const Lista<Polje> &getFields() const;
    bool hitField(Polje p);
    bool hitFigure() const;
    virtual char getType() const = 0;
    friend bool operator& (const Figura& f1, const Figura& f2);
    friend bool operator== (const Figura& f1, const Figura& f2);
};


#endif //UNTITLED18_FIGURA_H
