
#include "Jedrilica.h"

Jedrilica &Jedrilica::figuraCopy() const {
    Jedrilica* j = new Jedrilica(*this);
    return (*j);
}

char Jedrilica::getType() const {
    return letter;
}
