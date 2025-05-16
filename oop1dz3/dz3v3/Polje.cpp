
#include "Polje.h"

Polje::Oznaka Polje::getColumn() const {
    return column;
}

int Polje::getRow() const {
    return row;
}

Polje Polje::getPolje(int c, int r) const {
    if((column + c) < A || (column + c) > J) throw GKolonaOpseg();
    if((row + r) < 1 || (row + r) > 10) throw GRedOpseg();
    Polje polje(Oznaka(column + c), (row + r));
    return polje;
}

bool operator==(const Polje &p1, const Polje &p2) {
    if(p1.column == p2.column && p1.row == p2.row) return true;
    return false;
}


