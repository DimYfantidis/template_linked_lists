/*****************************************************************
 *                  TEMPLATE DOUBLY LINKED LISTS
 *
 *    DESCRIPTION:
 *    This is the header file for the declaration template class of
 *    doubly linked lists. The aforementioned data structure is a
 *    set of bidirectionally linked, template nodes that store the
 *    data. The implementation of the nodes' class is included in
 *    this header file.
 *
 *    SUPPORTED TYPES:
 *    The lists support all of the language's data types including
 *    STL types, as well as any object that has the operator '='
 *    overloaded.
 *
 *    EXCEPTIONS:
 *    A range_error exception is thrown in case of access violation
 *    when using the overloaded operator '[]' or the insert() method.
 *
 ******************************************************************/

#ifndef LIST_H
#define LIST_H

#include <iostream>

// TEMPLATE NODES: Auxiliary class; the nodes that the list consists of.
template <class T> class node_l {
public:
    T data;             // Data of an arbitrary data type.
    node_l<T> *next;    // Pointer to the list's next node.
    node_l<T> *prev;    // Pointer to the list's previous node.

    // ... <----> (prev node) <----> (node) <----> (next node) <----> ...

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

//The following macros define how a list is printed in an output stream.
#define HORIZ 0b01  //Prints list horizontally. [DEFAULT]
#define VERT  0b10  //Prints list vertically.

template <class T> class list {
private:
    node_l<T> *head;    // First node of the list.
    node_l<T> *tail;    // Last node of the list.
    long long size;     // Number of total elements.

    void printHorizontally(const node_l<T> *, std::ostream &) const;    // Horizontal printing of list.
    void printVertically(const node_l<T> *, std::ostream &) const;      // Vertical printing of list.
    node_l<T> * search(node_l<T> *, const T &, bool &) const;
public:
    list();
    ~list();
    list(const list<T> &);

    long long getSize() const;          // Getter for 'size' member.

    void pushBack(const T &);           // Adds element at the end of the list.
    void pushFront(const T &);          // Adds element at the beginning of the list.
    bool pop();                         // Deletes last element.
    bool search(const T &) const;       // Searches the element passed as parameter.
    void insert(long long, const T &);  // Inserts a new node with the data passed as second parameter
                                        // right before the node indexed by the first parameter.
    bool remove(const T &);             // Removes element from list.

    bool empty() const;     //Returns true if no elements are stored in the list, false otherwise.
    void print(std::ostream &, unsigned short mode = HORIZ) const;  // Prints list to output stream.

    // OVERLOADED OPERATORS.
    list<T> & operator =  (const list<T> &);    // Obvious.
    list<T> & operator += (const list<T> &);    // Appends a list at the end of *this. (Merge)
    inline list<T> & operator += (const T &);   // Appends a new node at the end of *this. (pushBack(), basically)
    inline list<T> & operator -= (const T &);   // Removes element from list. (remove(), basically)
    T & operator [] (long long);                // Obvious.
};

// Merges two lists.
template <typename T>
list<T> operator + (const list<T> &, const list<T> &);

// Prints list to output stream using print() at default mode (horizontally).
template <typename T>
std::ostream  & operator << (std::ostream &, const list<T> &);


#include "list.cpp"

#endif //LIST_H
