
#include "Tabela.h"

const string &Tabela::getName() const {
    return name;
}

Lista<string> &Tabela::getColumns() const {
    return columns;
}

bool Tabela::containsColumn(string column) const {
    return columns.isInList(column);
}

bool Tabela::contatinsColumns(const Lista<string> &c) const {
    int found = 0;
    int all = 0;
    c.setCurrentAsFirst();
    while (c.existsCurrent()){
        if(columns.isInList(c.getCurrentData())) found++;
        all++;
        c.moveCurrentToNext();
    }
    if(found == all && all){
        return true;
    }
    return false;
}
