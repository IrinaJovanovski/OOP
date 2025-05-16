
#include "GumaZaSveSezone.h"

char GumaZaSveSezone::getLetter() const {
    return letter;
}

bool GumaZaSveSezone::CorrectDepthOfTread() const {
    if(getCurrDepthOfTread() >= min_depth_of_tread) return true;
    return false;
}
