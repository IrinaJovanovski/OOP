

#ifndef DZ3V1_VREME_H
#define DZ3V1_VREME_H
#include <iostream>
using namespace std;

class Vreme {
    int hour;
    int min;
    int day;
    int month;
    int year;
public:
    Vreme(int h, int m, int d, int mth, int y){
        hour = h;
        min = m;
        day = d;
        month = mth;
        year = y;
    }
    int getHour() const;
    int getMin() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    friend bool operator== (const Vreme& v1, const Vreme& v2);
    bool operator< (const Vreme& v2) const;
    Vreme& operator+= (int minutes);
    friend ostream& operator<< (ostream& os, const Vreme& v);
};


#endif //DZ3V1_VREME_H
