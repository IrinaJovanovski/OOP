

#include "Statistika.h"

Kosarkas &Statistika::getKosarkas() const {
    return kosarkas;
}

void Statistika::addTryI(int points) {
    tryI += points;
    return;
}

void Statistika::addTryII(int points) {
    tryII += points;
    return;
}

void Statistika::addTryIII(int points) {
    tryIII += points;
    return;
}

void Statistika::addScoreI(int points) {
    scoreI += points;
    tryI += points;
    return;
}

void Statistika::addScoreII(int points) {
    scoreII += points;
    tryII += points;
    return;
}

void Statistika::addScoreIII(int points) {
    scoreIII += points;
    tryIII += points;
    return;
}

void Statistika::addnumAttack(int jumps) {
    numAttack += jumps;
    return;
}

void Statistika::addnumDefense(int jumps) {
    numDefense += jumps;
    return;
}

void Statistika::addnumAssistance(int assistances) {
    numAssistance += assistances;
    return;
}

int Statistika::totalPoints() const {
    return (scoreI + 2*scoreII + 3*scoreIII);
}

int Statistika::totalJumps() const {
    return (numDefense + numAttack);
}

ostream &operator<<(ostream &os, const Statistika &s) {
    os << s.getKosarkas() << " #RTS: " << s.totalPoints() << " #RB: " << s.totalJumps() << " #AS: " << s.numAssistance;
    return os;
}



