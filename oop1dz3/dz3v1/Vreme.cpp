

#include "Vreme.h"

int Vreme::getHour() const {
    return hour;
}

int Vreme::getMin() const {
    return min;
}

int Vreme::getDay() const {
    return day;
}

int Vreme::getMonth() const {
    return month;
}

int Vreme::getYear() const {
    return year;
}

bool operator==(const Vreme &v1, const Vreme &v2) {
    if(v1.getDay() == v2.getDay()
    && v1.getHour() == v2.getHour()
    && v1.getMin() == v2.getMin()
    && v1.getYear() == v2.getYear()
    && v1.getMonth() == v2.getMonth()) return true;
    return false;
}

bool Vreme::operator<(const Vreme &v2) const {
    if(getYear() < v2.getYear()){
        return true;
    }else if(getYear() > v2.getYear()){
        return false;
    }
    if(getMonth() < v2.getMonth()){
        return true;
    }else if(getMonth() > v2.getMonth()){
        return false;
    }
    if(getDay() < v2.getDay()){
        return true;
    }else if(getDay() > v2.getDay()){
        return false;
    }
    if(getHour() < v2.getHour()){
        return true;
    }else if(getHour() > v2.getHour()){
        return false;
    }
    if(getMin() < v2.getMin()){
        return true;
    }
    return false;
}

Vreme &Vreme::operator+=(int minutes) {
    min = min + minutes;
    while(min > 59){
        hour++;
        min -= 60;
        if(hour == 24){
            hour = 0;
            day++;
            switch (month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if(day == 32){
                    month++;
                    day = 1;
                }
                if(month == 13){
                    year++;
                    month = 1;
                }
                break;
            case 4: case 6: case 9: case 11:
                if(day == 31){
                    month++;
                    day = 1;
                }
                break;
            case 2:
                if((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)){
                    if(day == 30){
                        month++;
                        day = 1;
                    }
                }else{
                    if(day == 29){
                        month++;
                        day = 1;
                    }
                }
                break;
            }
        }
    }
    return *this;
}

ostream &operator<<(ostream &os, const Vreme &v) {
    if(v.getHour() % 10 == v.getHour()){
        os << "0" << v.getHour() << ":";
    }else{ os << v.getHour() << ":"; }

    if(v.getMin() % 10 == v.getMin()){
        os << "0" << v.getMin() << "-";
    }else{ os << v.getMin() << "-"; }

    if(v.getDay() % 10 == v.getDay()){
        os << "0" << v.getDay() << ".";
    }else{ os << v.getDay() << "."; }

    if(v.getMonth() % 10 == v.getMonth()){
        os << "0" << v.getMonth() << ".";
    }else{ os << v.getMonth() << "."; }

    os << v.getYear();
    return os;
}
