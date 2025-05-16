
#include "ZimskaGuma.h"

char ZimskaGuma::getLetter() const {
    return letter;
}

bool ZimskaGuma::CorrectDepthOfTread() const {
    if(getCurrDepthOfTread() >= min_depth_of_tread) return true;
    return false;
}
