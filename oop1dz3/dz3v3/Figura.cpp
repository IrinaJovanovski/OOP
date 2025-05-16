
#include "Figura.h"

const Lista<Polje> &Figura::getFields() const {
    return fields;
}

bool Figura::hitField(Polje p) {
    for(int i = 0; i < fields.getNumOfElements(); i++){
        if(fields[i] == p && !(hits[i])){
            (hits[i]) = true;
            return true;
        }
    }
    return false;
}

bool operator&(const Figura &f1, const Figura &f2) {
    if(f1.fields.getNumOfElements() > f2.fields.getNumOfElements()){
        for(int i = 0; i < f1.fields.getNumOfElements(); i++){
            if(f2.fields(f1.fields[i])) return true;
        }
    }else{
        for(int i = 0; i < f2.fields.getNumOfElements(); i++){
            if(f1.fields(f2.fields[i])) return true;
        }
    }
    return false;
}

bool operator==(const Figura &f1, const Figura &f2) {
    return f1.getType() == f2.getType();
}

bool Figura::hitFigure() const {
    for(int i = 0; i < hits.getNumOfElements(); i++){
        if(!(hits[i])) return false;
    }
    return true;
}

