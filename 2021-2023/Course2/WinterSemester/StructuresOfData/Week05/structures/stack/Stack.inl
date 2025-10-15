//
// Created by Sybatron on 11/3/2022.
//

#include "Stack.h"
#include <stdexcept>

template<class T>
void Stack<T>::erase() {
    if (isEmpty()) {
        return;
    }

    while (!isEmpty()) {
        Node *save = first->next;
        first->next = nullptr;
        delete first;
        first = save;
    }
}

template<class T>
void Stack<T>::copy(const Stack<T> &other) {
    if (other.first == nullptr) {
        first = nullptr;
        return;
    }
    first = new Node{other.first->data, nullptr};

    Node *otherHolder = other.first->next;
    Node *firstHolder = first;

    while (otherHolder != nullptr) {
        firstHolder->next = new Node{otherHolder->data, nullptr};
        firstHolder = firstHolder->next;
        otherHolder = otherHolder->next;
    }
}


template<class T>
Stack<T>::Stack() {
    first = nullptr;
}

template<class T>
Stack<T>::Stack(const Stack<T> &other) {
    copy(other);
}

template<class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

template<class T>
Stack<T>::~Stack() {
    erase();
}

template<class T>
void Stack<T>::push(const T &el) {
    first = new Node{el, first};
}

template<class T>
bool Stack<T>::pop() {
    if (isEmpty()) {
        return false;
    }

    Node *holder = first;
    T value = first->data;
    first = first->next;
    delete holder;

    return true;
}

template<class T>
const T &Stack<T>::peek() {
    if (isEmpty()) {
        throw std::range_error("Stack is empty");
    }
    return first->data;
}

template<class T>
bool Stack<T>::isEmpty() {
    return first == nullptr;
}

