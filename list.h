#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <class TYPE> class node {
public:
    TYPE data;
    node<TYPE> *next;

    node() {
        next = nullptr;
    }
    ~node() {
        next = nullptr;
    }
};

template <class T> class list {
private:
    node<T> *first;
    size_t size;

    node<T> * destroyList(node <T> *);
    node<T> * pushBack(node <T> *, T &);
    node<T> * add(node<T> *, size_t, size_t &, T &);
    node<T> * remove(node <T> *, T &, bool &);
    node<T> * returnElement(node <T> *,size_t, size_t &);

    void print(node<T> *N, ostream &) const;
public:
    list();
    ~list();

    size_t getSize() const;

    void pushBack(T arg);
    void add(size_t, T);
    bool remove(T arg);
    void print(ostream &) const;

    T & operator [] (size_t);
};

template <typename T>
ostream & operator << (ostream &, const list<T> &);

#include "list.cpp"

#endif //LIST_H
