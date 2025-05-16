
#ifndef UNTITLED18_LISTA_H
#define UNTITLED18_LISTA_H
#include <exception>
#include <iostream>
using namespace std;

class GNeispravanIndeks : public exception{
        public:
        GNeispravanIndeks() : exception(){
            cout << "Podatak ne postoji na zadatoj poziciji u listi!";
        }
        /* ili alternativno
        friend ostream& operator<< (ostream& os, const GNeispravanIndeks&){
            return (os << "Podatak ne postoji na zadatoj poziciji u listi!" << endl);
        }*/

};

template<typename T>
class Lista {
    struct Elem{
        T data;
        struct Elem* next;
        Elem(T d) : data(d) {
            next = nullptr;
        }
    };
    Elem *first,*last;
    int num_of_elements;
    void copy(const Lista& l);
    void move(Lista& l);
    void erase();
public:
    Lista(){
        first = nullptr;
        last = nullptr;
        num_of_elements = 0;
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
    Lista& operator+= (T t){
        last = ((!first) ? first : last->next) = new Elem(t);
        num_of_elements++;
        return *this;
    }
    int getNumOfElements() const { return num_of_elements; }
    T& operator[] (int index);
    const T& operator[] (int index) const;
    bool operator() (const T& t) const;
    bool operator() (T& t);
};

template<typename T>
bool Lista<T>::operator()(T& t) {
    for(Elem* curr = first; curr; curr = curr->next){
        if(t == curr->data) return true;
    }
    return false;
}

template<typename T>
bool Lista<T>::operator()(const T& t) const {
    for(Elem* curr = first; curr; curr = curr->next){
        if(t == curr->data) return true;
    }
    return false;
}

template<typename T>
const T &Lista<T>::operator[](int index) const {
    if(index >= num_of_elements || index < 0) throw GNeispravanIndeks();
    int i = 0;
    for(Elem* curr = first; curr; curr = curr->next){
        if(i == index) return const_cast<const T&>(curr->data);
        i++;
    }
}

template<typename T>
void Lista<T>::erase() {
    while(first){
        Elem* old = first;
        first = first->next;
        delete old;
    }
    last = nullptr;
    num_of_elements = 0;
}

template<typename T>
void Lista<T>::move(Lista &l) {
    num_of_elements = l.num_of_elements;
    first = l.first;
    last = l.last;
    l.first = l.last = nullptr;
}

template<typename T>
void Lista<T>::copy(const Lista &l) {
    first = last = nullptr;
    for(Elem* curr = l.first; curr; curr = curr->next){
        last = ((!first) ? first : last->next) = new Elem(curr->data);
    }
    num_of_elements = l.num_of_elements;
}

template<typename T>
T &Lista<T>::operator[](int index) {
    if(index >= num_of_elements || index < 0) throw GNeispravanIndeks();
    int i = 0;
    for(Elem* curr = first; curr; curr = curr->next){
        if(i == index) return (curr->data);
        i++;
    }
}

#endif //UNTITLED18_LISTA_H
