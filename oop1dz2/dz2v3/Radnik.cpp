
#include "Radnik.h"


int Radnik::operator*() const {
    return sati;
}

int Radnik::operator+() const {
    return (plata * sati);
}
