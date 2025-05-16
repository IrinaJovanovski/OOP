
#ifndef UNTITLED19_SELEKTORKOLONA_H
#define UNTITLED19_SELEKTORKOLONA_H
#include "Selektor.h"

class SelektorKolona : public Selektor {
public:
    SelektorKolona(Lista<string>& c) : Selektor(c){}
    string getTextDescription() const override;
};


#endif //UNTITLED19_SELEKTORKOLONA_H
