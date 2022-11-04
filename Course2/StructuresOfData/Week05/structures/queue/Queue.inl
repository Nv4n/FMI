//
// Created by Sybatron on 11/4/2022.
//

#include "Queue.h"
#include <stdexcept>

template<class T>
void Queue<T>::copy(const Queue<T> &other) {
    front = new Node{other.front->data, nullptr};
    Node *holder = front;
    Node *otherHolder = other.front->next;
    while (otherHolder != nullptr) {
        holder->next = new Node{otherHolder->data, nullptr};
        holder = holder->next;
        otherHolder = otherHolder->next;
    }
    back = holder;
}

template<class T>
void Queue<T>::erase() {
    back = nullptr;
    Node *tmp = front;

    while (tmp != nullptr) {
        front = front->next;
        delete tmp;
        tmp = front;
    }
}

template<class T>
Queue<T>::Queue() {
    front = nullptr;
    back = nullptr;
}

template<class T>
Queue<T>::Queue(const Queue<T> &other) {
    copy(other);
}

template<class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

template<class T>
Queue<T>::~Queue() {
    erase();
}

template<class T>
bool Queue<T>::isEmpty() {
    return front == nullptr;
}

template<class T>
const T &Queue<T>::peek() {
    if (isEmpty()) {
        throw std::range_error("Queue is empty");
    }

    return front->data;
}

template<class T>
void Queue<T>::push(const T &el) {
    if (isEmpty()) {
        front = new Node{el, nullptr};
        back = front;
        return;
    }

    back->next = new Node{el, nullptr};
    back = back->next;
}

template<class T>
void Queue<T>::pop() {
    if (isEmpty()) {
        throw std::range_error("Queue is empty");
    }

    Node *tmp = front;
    front = front->next;
    tmp->next = nullptr;
    delete tmp;
}