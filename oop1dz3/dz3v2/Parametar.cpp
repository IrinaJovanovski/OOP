
#include "Parametar.h"

bool operator==(const Parametar &p1, const Parametar &p2) {
    if(p1.type == p2.type) return true;
    return false;
}

ostream &operator<<(ostream &os, const Parametar& p) {
    p.write(os);
    return os;
}

void Parametar::write(ostream &os) const {
    if(type == 0){
        os << "INT" << " " << name;
    }else if(type == 1){
        os << "FLOAT" << " " << name;
    }else{
        os << "STRING" << " " << name;
    }

}
