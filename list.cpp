#ifndef LIST_CPP
#define LIST_CPP

#include "list.h"


// -------------------------- PRIVATE --------------------------

template <typename T>
node<T> * list<T>::destroyList(node<T> *N) {
    if (N != nullptr) {
        N->next = destroyList(N->next);
        delete N;
    }
    return nullptr;
}

template <typename T>
node<T> *  list<T>::pushBack(node<T> *N, T &arg) {
    if (N == nullptr) {
        N = new node<T>;
        N->data = arg;
        ++size;
    } else {
        N->next = pushBack(N->next, arg);
    }
    return N;
}

template <typename T>
node<T> * list<T>::add(node<T> *N, size_t current, size_t &to_be_added, T &arg) {
    if (current == to_be_added) {
        auto *added_node = new node<T>;
        added_node->data = arg;
        added_node->next = N;
        ++size;
        return added_node;
    }
    N->next = add(N->next, current + 1, to_be_added, arg);
    return N;
}

template <typename T>
node<T> * list<T>::remove(node<T> *N, T &arg, bool &deleted) {
    if (N == nullptr) {
        return N;
    }
    if (N->data == arg) {
        deleted = true;
        node<T> *temp = N->next;
        delete N;
        --size;
        return temp;
    }
    N->next = remove(N->next, arg, deleted);
    return N;
}

template <typename T>
void list<T>::print(node<T> *N, ostream &output) const {
    if (N == nullptr) {
        output << "\b\b";
        return;
    }
    output << N->data << ", ";
    print(N->next, output);
}

template <typename T>
node<T> * list<T>::returnElement(node <T> *N, size_t current, size_t &to_be_found) {
    if (to_be_found >= size) {
        throw (range_error("Access violation"));
    }
    if (current == to_be_found) {
        return N;
    }
    return returnElement(N->next, current + 1, to_be_found);
}


// -------------------------- PUBLIC --------------------------

template <typename T>
list<T>::list() {
    size = 0;
    first = nullptr;
}

template <typename T>
list<T>::~list() {
    first = destroyList(first);
}

template <typename T>
void list<T>::pushBack(T arg) {
    first = pushBack(first, arg);
}

template <typename T>
bool list<T>::remove(T arg) {
    bool deleted = false;
    first = remove(first, arg, deleted);
    return deleted;
}

template <typename T>
void list<T>::print(ostream &output) const {
    output << "[";
    if (first != nullptr) {
        print(first, output);
    }
    output << "]";
}

template <typename T>
size_t list<T>::getSize() const {
    return size;
}

template <typename T>
void list<T>::add(size_t i, T arg) {
    if (i >= size) {
        throw (range_error("Position out of list's range. "
                           "Try using [void]pushBack(node<T> *, T &) method instead"));
    }
    first = add(first, 0, i, arg);
}

template <typename T>
T& list<T>::operator [] (size_t i) {
    auto *temp = returnElement(first, (size_t)0, i);
    return temp->data;
}

template <typename T>
ostream & operator << (ostream &output, const list<T> &arg) {
    arg.print(output);
    return output;
}

#endif //LIST_CPP