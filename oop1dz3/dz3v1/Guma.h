
#ifndef UNTITLED14_GUMA_H
#define UNTITLED14_GUMA_H
#include <iostream>
#include "Vreme.h"
using namespace std;

class Guma {
    double width; //mm
    double height; //procenat sirine gume
    double radius_of_rim; //in
    double curr_depth_of_tread; //mm
    double price;
    Vreme& production_time;
public:
    Guma(double w,double h, double r, double c, double p, Vreme& t) : production_time(t){
        width = w;
        height = h;
        radius_of_rim = r;
        curr_depth_of_tread = c;
        price = p;
    }
    Guma(const Guma& g) = delete;
    Guma& operator= (const Guma& g) = delete;
    virtual ~Guma(){}
    double getWidth() const;
    double getHeight() const;
    double getRadiusOfRim() const;
    double getCurrDepthOfTread() const;
    double getPrice() const;
    Vreme& getProductionTime() const;
    void operator-- (int);
    virtual char getLetter() const = 0;
    virtual bool CorrectDepthOfTread() const = 0;
    friend bool operator== (const Guma& g1, const Guma& g2);
    friend ostream& operator<< (ostream& os, const Guma& g);
};


#endif //UNTITLED14_GUMA_H
