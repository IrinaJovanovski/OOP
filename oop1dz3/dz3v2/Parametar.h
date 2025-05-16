
#ifndef UNTITLED16_PARAMETAR_H
#define UNTITLED16_PARAMETAR_H
#include <iostream>
using namespace std;

class Parametar {
public:
    enum Type{INT, FLOAT, STRING};
    Parametar(string n, Type t) : name(n), type(t){}
    friend bool operator== (const Parametar& p1, const Parametar& p2);
protected:
    string name;
    Type type;
    virtual void write(ostream& os)const;
    friend ostream& operator<< (ostream& os, const Parametar& p);
};


#endif //UNTITLED16_PARAMETAR_H
