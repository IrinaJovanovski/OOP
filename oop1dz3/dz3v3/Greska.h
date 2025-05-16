
#ifndef UNTITLED18_GRESKA_H
#define UNTITLED18_GRESKA_H
#include <exception>
#include <iostream>
#include <string>
using namespace std;

class GKolonaOpseg: public exception {
public:
    GKolonaOpseg() : exception(){
        cout << "Kolona je van opsega!";
    }
    /* ili alternativno
    friend ostream& operator<< (ostream& os, const GKolonaOpseg&){
        return (os << "Kolona je van opsega!" << endl);
    }*/
};

class GRedOpseg: public exception {
public:
    GRedOpseg() : exception(){
        cout << "Red je van opsega!";
    }
    /* ili alternativno
    friend ostream& operator<< (ostream& os, const GRedOpseg&){
        return (os << "Red je van opsega!" << endl);
    }*/
};
#endif //UNTITLED18_GRESKA_H
