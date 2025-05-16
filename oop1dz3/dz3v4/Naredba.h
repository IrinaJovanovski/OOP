
#ifndef UNTITLED19_NAREDBA_H
#define UNTITLED19_NAREDBA_H
#include "Tabela.h"
#include "SelektorKolona.h"

class Naredba {
protected:
    Tabela& table;
public:
    Naredba(Tabela& t) : table(t){}
    Naredba(const Naredba& n) = delete;
    Naredba& operator= (const Naredba& n) = delete;
    virtual Selektor& getSelektorNaredbe() const = 0;
    virtual string getTextDescription() const = 0;
    operator std::string() const;
};


#endif //UNTITLED19_NAREDBA_H
