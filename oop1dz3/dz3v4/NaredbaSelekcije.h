
#ifndef UNTITLED19_NAREDBASELEKCIJE_H
#define UNTITLED19_NAREDBASELEKCIJE_H
#include "Naredba.h"
#include "Selektor.h"

class GNemaKolone : public exception{
public:
    GNemaKolone() : exception(){
        cout << "Kolona ne postoji u  tabeli!";
    }
    /* ili alternativno
    friend ostream& operator<< (ostream& os, const GNemaKolone&){
        return (os << "Kolona ne postoji u  tabeli" << endl);
    }*/

};

class NaredbaSelekcije : public Naredba{
    Selektor& selector;
public:
    NaredbaSelekcije(Tabela& t,Selektor& s2) : selector(s2), Naredba(t){
        (selector.getColumns()).setCurrentAsFirst();
        while ((selector.getColumns()).existsCurrent()){
            if(!((t.getColumns()).isInList((selector.getColumns()).getCurrentData()))) throw GNemaKolone();
            (selector.getColumns()).moveCurrentToNext();
        }
    }
    Selektor& getSelektorNaredbe() const override;
    virtual string getTextDescription() const override;
};


#endif //UNTITLED19_NAREDBASELEKCIJE_H
