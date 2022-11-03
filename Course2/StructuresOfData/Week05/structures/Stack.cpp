//
// Created by Sybatron on 11/3/2022.
//

#include "Stack.h"

template<class T>
inline Stack<T>::Stack() {
    first = nullptr;
}

template<class T>
inline Stack<T>::Stack(const Stack<T> &other) {
    copy(other);
}


template<class T>
inline Stack<T> &Stack<T>::operator=(const Stack<T> &other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

template<class T>
inline Stack<T>::~Stack() {
    erase();
}

template<class T>
inline void Stack<T>::copy(const Stack<T> &other) {
    if (other.first == nullptr) {
        return;
    }
    Node *holder = other.first;

    while (holder != nullptr) {
        first = new Node{holder->data, first};
        holder = holder->next;
    }
}

template<class T>
inline void Stack<T>::erase() {
    if (first == nullptr) {
        return;
    }

    while (first != nullptr) {
        Node *save = first->next;
        first->next = nullptr;
        delete first;
        first = save;
    }
}

template<class T>
inline const T &Stack<T>::pop() {
    T save = first->data;
    Node *holder = first->next;
    first->next = nullptr;
    delete first;
    first = holder;
    return save;
}

template<class T>
inline void Stack<T>::push(const T &el) {
    first = new Node{el, first};
}

template<class T>
const T &Stack<T>::peek() {
    return first->data;
}
