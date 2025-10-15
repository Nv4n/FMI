//
// Created by Sybatron on 5/11/2023.
//

#include "Set.h"

template<typename T>
Set<T>::Set() : root(nullptr), size(0) {}

template<typename T>
Set<T>::~Set() {
    Node *curr = root;
    while (curr) {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
}


template<typename T>
bool Set<T>::contains(const T &elem) const {
    Node *curr = root;
    while (curr) {
        if (curr->data == elem) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template<typename T>
bool Set<T>::insert(const T &elem) {
    if (contains(elem)) {
        return false;
    }
    Node *newNode = new Node(elem);
    newNode->next = root;
    root = newNode;
    size++;
    return true;
}

template<typename T>
void Set<T>::remove(const T &elem) {
    Node *prev = nullptr;
    Node *curr = root;
    while (curr) {
        if (curr->data == elem) {
            if (prev) {
                prev->next = curr->next;
            } else {
                root = curr->next;
            }
            delete curr;
            size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

template<typename T>
int Set<T>::getSize() const {
    return size;
}
