
#include "Selektor.h"
int Selektor::id = 0;

const Lista<string> &Selektor::getColumns() const {
    return columns;
}

bool operator==(const Selektor &s1, const Selektor &s2) {
    s1.columns.setCurrentAsFirst();
    s2.columns.setCurrentAsFirst();
    while(s1.columns.existsCurrent() && s2.columns.existsCurrent()){
        if(s1.columns.getCurrentData() != s2.columns.getCurrentData()) return false;
        s1.columns.moveCurrentToNext();
        s2.columns.moveCurrentToNext();
    }
    if(s1.columns.existsCurrent() || s2.columns.existsCurrent()) return false;
    return true;
}


