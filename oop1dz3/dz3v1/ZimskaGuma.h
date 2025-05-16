
#ifndef UNTITLED14_ZIMSKAGUMA_H
#define UNTITLED14_ZIMSKAGUMA_H
#include "Guma.h"

class ZimskaGuma: public Guma {
    double min_depth_of_tread = 4; //mm
    char letter = 'Z';
public:
    ZimskaGuma(double w,double h, double r, double c, double p, Vreme& t): Guma(w, h, r, c, p, t){}
    char getLetter() const override;
    bool CorrectDepthOfTread() const override;
};


#endif //UNTITLED14_ZIMSKAGUMA_H
