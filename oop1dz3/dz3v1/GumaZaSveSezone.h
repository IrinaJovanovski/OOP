
#ifndef UNTITLED14_GUMAZASVESEZONE_H
#define UNTITLED14_GUMAZASVESEZONE_H
#include "Guma.h"

class GumaZaSveSezone: public Guma {
    double min_depth_of_tread = 4; //mm
    char letter = 'A';
public:
    GumaZaSveSezone(double w,double h, double r, double c, double p, Vreme& t): Guma(w, h, r, c, p, t){}
    char getLetter() const override;
    bool CorrectDepthOfTread() const override;
};


#endif //UNTITLED14_GUMAZASVESEZONE_H
