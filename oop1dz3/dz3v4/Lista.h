
#ifndef UNTITLED19_LISTA_H
#define UNTITLED19_LISTA_H
#include <iostream>
#include <string>
using namespace std;

class GNemaTekuceg : public exception{
public:
    GNemaTekuceg() : exception(){
        cout << "Tekuci element ne postoji!";
    }
    /* ili alternativno
    friend ostream& operator<< (ostream& os, const GNemaTekuceg&){
        return (os << "Tekuci element ne postoji!" << endl);
    }*/

};

template<typename T>
class Lista {
    struct Elem{
        T& data;
        struct Elem* next;
        Elem(T& d) : data(d) {
            next = nullptr;
        }
    };
    Elem *first,*last;
    mutable Elem* curr;
    void copy(const Lista& l);
    void move(Lista& l);
    void erase();
public:
    Lista(){
        first = nullptr;
        last = nullptr;
        curr = nullptr;
    }
    Lista(const Lista& l){copy(l);}
    Lista(Lista&& l){move(l);}
    ~Lista(){erase();}
    Lista& operator= (const Lista& l){
        if(this != &l){
            erase();
            copy(l);
        }
        return *this;
    }
    Lista& operator= (Lista&& l){
        if(this != &l){
            erase();
            move(l);
        }
        return *this;
    }
    Lista& operator+= (T& t){
        last = ((!first) ? first : last->next) = new Elem(t);
        return *this;
    }
    Lista& operator+= (Lista& l){
        ((!first) ? first : last->next) = l.first;
        last = l.last;
        return *this;
    }
    void setCurrentAsFirst() const{ curr = first;}
    void moveCurrentToNext() const {  if(curr) curr = curr->next; }
    bool existsCurrent() const { return curr != nullptr;}
    const T& getCurrentData() const;
    bool emptyList() const;
    bool isInList(const T& data) const;
    string textDescription(string separator) const;
};

template<typename T>
string Lista<T>::textDescription(string separator) const {
    string desc = "";
    int i = 0;
    for(Elem* current = first; current; current = current->next){
        if(i){
            desc += separator;
        }
        desc += current->data;
        i = 1;
    }
    return desc;
}

template<typename T>
bool Lista<T>::isInList(const T &data) const {
    for(Elem* current = first; current; current = current->next){
        if(current->data == data) return true;
    }
    return false;
}

template<typename T>
bool Lista<T>::emptyList() const {
    if(first == nullptr) return true;
    return false;
}

template<typename T>
const T &Lista<T>::getCurrentData() const {
    if(curr == nullptr) throw GNemaTekuceg();
    return const_cast<const T&>(curr->data);
}

template<typename T>
void Lista<T>::erase() {
    while(first){
        Elem* old = first;
        first = first->next;
        delete old;
    }
    last = nullptr;
    curr = nullptr;
}

template<typename T>
void Lista<T>::move(Lista &l) {
    first = l.first;
    last = l.last;
    curr = l.curr;
    l.first = l.last = nullptr;
}

template<typename T>
void Lista<T>::copy(const Lista &l) {
    first = last = nullptr;
    for(Elem* current = l.first; current; current = current->next){
        last = ((!first) ? first : last->next) = new Elem(current->data);
    }
    curr = l.curr;
}


#endif //UNTITLED19_LISTA_H
