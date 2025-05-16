
#ifndef UNTITLED14_LETNJAGUMA_H
#define UNTITLED14_LETNJAGUMA_H
#include "Guma.h"

class LetnjaGuma: public Guma {
    double min_depth_of_tread = 1.6; //mm
    char letter = 'L';
public:
    LetnjaGuma(double w,double h, double r, double c, double p, Vreme& t): Guma(w, h, r, c, p, t){}
    char getLetter() const override;
    bool CorrectDepthOfTread() const override;
};


#endif //UNTITLED14_LETNJAGUMA_H
