
#include "NaredbaSelekcije.h"

Selektor &NaredbaSelekcije::getSelektorNaredbe() const {
    return selector;
}

string NaredbaSelekcije::getTextDescription() const {
    string s = "SELECT " + selector.getTextDescription() + "\nFROM " + table.getName() + "\n";
    return s;
}
