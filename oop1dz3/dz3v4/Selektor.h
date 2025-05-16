
#ifndef UNTITLED19_SELEKTOR_H
#define UNTITLED19_SELEKTOR_H
#include "Lista.h"

class Selektor {
protected:
    static int id;
    int idS = id;
    Lista<string>& columns;
public:
    Selektor(Lista<string>& c) : columns(c){
        id++;
    }
    const Lista<string> &getColumns() const;
    virtual string getTextDescription() const = 0;
    friend bool operator== (const Selektor& s1, const Selektor& s2);
};


#endif //UNTITLED19_SELEKTOR_H
