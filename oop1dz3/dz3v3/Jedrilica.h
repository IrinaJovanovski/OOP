
#ifndef UNTITLED18_JEDRILICA_H
#define UNTITLED18_JEDRILICA_H
#include "Figura.h"

class Jedrilica : public Figura {
public:
    Jedrilica(Polje &p) : Figura(p){
        fields += p.getPolje(-1,0);
        hits += false;
        fields += p.getPolje(1, 0);
        hits += false;
        fields += p.getPolje(-1,1);
        hits += false;
        fields += p.getPolje(1, 1);
        hits += false;
        fields += p.getPolje(-1,-1);
        hits += false;
        fields += p.getPolje(1, -1);
        hits += false;
        letter = 'H';
    }
    Jedrilica& figuraCopy() const override;
    char getType() const override;
};


#endif //UNTITLED18_JEDRILICA_H
