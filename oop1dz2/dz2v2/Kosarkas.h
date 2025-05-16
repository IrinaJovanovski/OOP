#include <iostream>
#include <string>
using namespace std;

#ifndef DZ2_KOSARKAS_H
#define DZ2_KOSARKAS_H


class Kosarkas {
public:
    enum pozicija {PG, SG, SF, PF, C};
    Kosarkas(string i, int g, pozicija p) : ime(i), god(g), poz(p){}
    Kosarkas(const Kosarkas&) = delete;
    Kosarkas& operator= (const Kosarkas&) = delete;
    const string &getIme() const;
    int getGod() const;
    pozicija getPoz() const;
    void changePoz(pozicija poz);
    friend ostream& operator<< (ostream& os, const Kosarkas &k);
private:
    string ime;
    int god;
    pozicija poz;

};


#endif //DZ2_KOSARKAS_H
