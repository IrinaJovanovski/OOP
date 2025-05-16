
#ifndef UNTITLED19_TABELA_H
#define UNTITLED19_TABELA_H
#include "Lista.h"

class Tabela {
    string name;
    Lista<string>& columns;
public:
    Tabela(string n, Lista<string>& c) : name(n), columns(c){}
    const string &getName() const;
    Lista<string> &getColumns() const;
    bool containsColumn(string column) const;
    bool contatinsColumns(const Lista<string>& c) const;
};


#endif //UNTITLED19_TABELA_H
