#ifndef LIST_CPP
#define LIST_CPP

#include "list.h"

// ------------------ PRIVATE ------------------


template <typename T>
void list<T>::printHorizontally(const node_l<T> *N, ostream &output) const {
    if (N == nullptr) {
        return;
    }
    output << N->data << (N->next != nullptr ? ", " : "");
    printHorizontally(N->next, output);
}

template <typename T>
void list<T>::printVertically(const node_l<T> *N, ostream &output) const {
    if (N == nullptr) {
        return;
    }
    output << N->data << "\n";
    printVertically(N->next, output);
}

template <typename T>
node_l<T> * list<T>::search(node_l<T> *N, T &arg, bool &found) const {
    if (N == nullptr) {
        return nullptr;
    }
    if (N->data == arg) {
        found = true;
        return N;
    }
    return search(N->next, arg, found);
}

// ------------------ PUBLIC ------------------

template <typename T>
list<T>::list() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
list<T>::~list() {
    if (empty()) {
        return;
    }
    auto *temp = head;
    while (temp != tail) {
        temp = temp->next;
        delete temp->prev;
    }
    delete temp;
    head = tail = nullptr;
    size = 0;
}

template <typename T>
list<T>::list(const list<T> &prototype) {
    size = prototype.size;
    if (prototype.empty()) {
        head = nullptr;
        tail = nullptr;
        return;
    }
    head = new node_l<T>;
    head->data = prototype.head->data;
    tail = head;

    auto *temp = prototype.head;
    while (temp->next != nullptr) {
        tail->next = new node_l<T>;
        tail->next->data = temp->next->data;
        tail->next->prev = tail;
        tail = tail->next;
        temp = temp->next;
    }
}

template <typename T>
long long list<T>::getSize() const {
    return size;
}

template <typename T>
void list<T>::push(T arg) {
    if (empty()) {
        head = new node_l<T>;
        head->data = arg;
        tail = head;
    } else {
        tail->next = new node_l<T>;
        tail->next->data = arg;
        tail->next->prev = tail;
        tail = tail->next;
    }
    ++size;
}

template <typename T>
bool list<T>::pop() {
    if (!empty()) {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        --size;
        return true;
    }
    return false;
}

template <typename T>
bool list<T>::search(T arg) const {
    bool found = false;
    search(head, arg, found);
    return found;
}

template <typename T>
void list<T>::insert(long long pos, T arg) {
    node_l<T> *scanner_node, *new_node;
    long long i;
    if (pos >= 0) {
        if (pos >= size) {
            throw (range_error("ERROR: Bad position"));
        }
        scanner_node = head;
        for (i = 0; i < pos; ++i) {
            scanner_node = scanner_node->next;
        }
        new_node = new node_l<T>;
        new_node->data = arg;

        new_node->prev = scanner_node->prev;
        scanner_node->prev = new_node;
        new_node->next = scanner_node;
        if (pos != 0) {
            new_node->prev->next = new_node;
        } else {
            head = new_node;
        }
    } else {
        if (abs(pos) > size) {
            throw (range_error("ERROR: Bad position"));
        }
        scanner_node = tail;
        for (i = size - 1; i > size - abs(pos); --i) {
            scanner_node = scanner_node->prev;
        }
        new_node = new node_l<T>;
        new_node->data = arg;

        scanner_node->next->prev = new_node;
        new_node->next = scanner_node->next;
        scanner_node->next = new_node;
        new_node->prev = scanner_node;
    }
    ++size;
}

template <typename T>
bool list<T>::remove(T arg) {
    if (empty()) {
        return false;
    }
    bool found = false;
    auto *p = search(head, arg, found);

    if (p != nullptr) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --size;
        return true;
    }
    return false;
}

template <typename T>
bool list<T>::empty() const {
    return size == 0;
}

template <typename T>
void list<T>::print(ostream &output, unsigned short mode) const {
    if (mode & HORIZ) {
        output << "[";
        if (head != nullptr) {
            printHorizontally(head, output);
        }
        output << "]";
    }
    if (mode & VERT) {
        output << "--------\n";
        if (head != nullptr) {
            printVertically(head, output);
        }
        output << "--------";
    }
}

template <typename T>
list<T> & list<T>::operator = (const list<T> &arg) {
    if (this != &arg) {
        size = arg.size;
        if (arg.empty()) {
            head = nullptr;
            tail = nullptr;
            return *this;
        }
        head = new node_l<T>;
        head->data = arg.head->data;
        tail = head;

        auto *temp = arg.head;
        while (temp->next != nullptr) {
            tail->next = new node_l<T>;
            tail->next->data = temp->next->data;
            tail->next->prev = tail;
            tail = tail->next;
            temp = temp->next;
        }
    }
    return *this;
}

template <typename T>
list<T> & list<T>::operator += (T arg) {
    push(arg);
    return *this;
}

template <typename T>
T & list<T>::operator [] (long long pos) {
    node_l<T> *scanner_node;
    int i;

    if (pos >= 0) {
        if (pos >= size) {
            throw (range_error("ERROR: Bad position"));
        }
        scanner_node = head;
        for (i = 0; i < pos; ++i) {
            scanner_node = scanner_node->next;
        }
    } else {
        if (abs(pos) > size) {
            throw (range_error("ERROR: Bad position"));
        }
        scanner_node = tail;
        for (i = size - 1; i > size - abs(pos); --i) {
            scanner_node = scanner_node->prev;
        }
    }
    return scanner_node->data;
}

template <typename T>
ostream & operator << (ostream &output, const list<T> &arg) {
    arg.print(output);
    return output;
}

#endif //LIST_CPP