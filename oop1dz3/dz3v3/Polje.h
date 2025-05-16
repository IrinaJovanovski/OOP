
#ifndef UNTITLED18_POLJE_H
#define UNTITLED18_POLJE_H
#include "Greska.h"

class Polje {
public:
    enum Oznaka{A = 0, B, C, D, E, F, G, H, I, J = 9};
private:
    Oznaka column;
    int row;
public:
    Polje(Oznaka c, int r){
        if(c < A || c > J) throw GKolonaOpseg();
        if(r < 1 || r > 10) throw GRedOpseg();
        column = c;
        row = r;
    }
    Oznaka getColumn() const;
    int getRow() const;
    Polje getPolje(int c, int r) const; // +vrednost = desno/dole, -vrednost = levo/gore
    friend bool operator== (const Polje& p1, const Polje& p2);

};


#endif //UNTITLED18_POLJE_H
