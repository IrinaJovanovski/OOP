
#include "Funkcija.h"

int Funkcija::getNumOfParameters() const {
    return lista.getNumOfElements();
}

const Parametar &Funkcija::getParemeterFromPosition(int index) const {
    return *(lista[index]);
}

ostream &operator<<(ostream &os, const Funkcija &f) {
    os << f.name << "( ";
    for(int i = 0; i < f.getNumOfParameters(); i++){
        if(i){
            os << ", ";
        }
        os << f.getParemeterFromPosition(i);
    }
    os << " )" << endl;
    return os;
}

Lista<Parametar> &Funkcija::addToTheFunction(Parametar *p) {
    lista += p;
    return lista;
}
