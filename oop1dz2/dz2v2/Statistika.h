#include "Kosarkas.h"

#ifndef DZ2_STATISTIKA_H
#define DZ2_STATISTIKA_H


class Statistika {
    Kosarkas& kosarkas;
    int tryI = 0;
    int tryII = 0;
    int tryIII = 0;
    int scoreI = 0;
    int scoreII = 0;
    int scoreIII = 0;
    int numAttack = 0;
    int numDefense = 0;
    int numAssistance = 0;
public:
    Statistika(Kosarkas &k) : kosarkas(k){}
    Kosarkas &getKosarkas() const;
    void addTryI(int points = 1);
    void addTryII(int points = 1);
    void addTryIII(int points = 1);
    void addScoreI(int points = 1);
    void addScoreII(int points = 1);
    void addScoreIII(int points = 1);
    void addnumAttack(int jumps = 1);
    void addnumDefense(int jumps = 1);
    void addnumAssistance(int assistances = 1);
    int totalPoints() const;
    int totalJumps() const;
    friend ostream& operator<< (ostream &os, const Statistika &s);
};


#endif //DZ2_STATISTIKA_H
