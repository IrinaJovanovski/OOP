
#include "LetnjaGuma.h"

char LetnjaGuma::getLetter() const {
    return letter;
}

bool LetnjaGuma::CorrectDepthOfTread() const {
    if(getCurrDepthOfTread() >= min_depth_of_tread) return true;
    return false;
}
