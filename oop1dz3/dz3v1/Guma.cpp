
#include "Guma.h"

double Guma::getWidth() const {
    return width;
}

double Guma::getHeight() const {
    return height;
}

double Guma::getRadiusOfRim() const {
    return radius_of_rim;
}

double Guma::getCurrDepthOfTread() const {
    return curr_depth_of_tread;
}

double Guma::getPrice() const {
    return price;
}

Vreme& Guma::getProductionTime() const {
    return production_time;
}

void Guma::operator--(int) {
    curr_depth_of_tread -= 0.1;
}

bool operator==(const Guma &g1, const Guma &g2) {
    if(g1.width == g2.width && g1.height == g2.height
    && g1.radius_of_rim == g2.radius_of_rim
    && g1.getLetter() == g2.getLetter()) return true;
    return false;
}

ostream &operator<<(ostream &os, const Guma &g) {
    os << g.width << "/" << (g.height/100)*g.width << "R/"
    << g.radius_of_rim << "-" << g.getLetter() << "@" << g.production_time
    << "==" << g.price << endl;
    return os;
}
