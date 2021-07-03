#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

#define HORIZ 0b01
#define VERT  0b10

template <class T> class node_l {
public:
    T data;
    node_l<T> *next;
    node_l<T> *prev;

    node_l() {
        next = nullptr;
        prev = nullptr;
    }
    explicit node_l(const T &init) {
        data = init;
        next = nullptr;
        prev = nullptr;
    }
    ~node_l() {
        next = nullptr;
        prev = nullptr;
    }
};

template <class T> class list {
private:
    node_l<T> *head;
    node_l<T> *tail;
    long long size;

    void printHorizontally(const node_l<T> *, ostream &) const;
    void printVertically(const node_l<T> *, ostream &) const;
    node_l<T> * search(node_l<T> *, const T &, bool &) const;
public:
    list();
    ~list();
    list(const list<T> &);

    long long getSize() const;

    void pushBack(const T &);
    void pushFront(const T &);
    bool pop();
    bool search(const T &) const;
    void insert(long long, const T &);
    bool remove(const T &);

    bool empty() const;
    void print(ostream &, unsigned short mode = HORIZ) const;

    list<T> & operator =  (const list<T> &);
    list<T> & operator += (const list<T> &);
    inline list<T> & operator += (const T &);
    inline list<T> & operator -= (const T &);
    T & operator [] (long long);
};

template <typename T>
list<T> operator + (const list<T> &, const list<T> &);

template <typename T>
ostream  & operator << (ostream &, const list<T> &);


#include "list.cpp"

#endif //LIST_H
