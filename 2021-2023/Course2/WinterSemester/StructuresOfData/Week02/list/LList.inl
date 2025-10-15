//
// Created by Sybatron on 10/13/2022.
//
#include <iostream>
#include <stdexcept>
#include "LList.h"

template<typename T>
LList<T>::LList():first(nullptr) {}

template<typename T>
void LList<T>::print() {
    box *curr = first;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

}

template<typename T>
void LList<T>::pushFront(const T &element) {
    box *holder = new box{element, first};
    first = holder;
}

template<typename T>
size_t LList<T>::size() const {
    size_t count = 0;
    box *curr = first;
    while (curr != nullptr) {
        ++count;
        curr = curr->next;
    }

    return count;
}

template<typename T>
const T &LList<T>::operator[](size_t i) const {
    box *curr = first;
    for (int count = 0; count < i; ++count) {
        if (curr == nullptr) {
            throw std::out_of_range("Index out of range");
        }

        curr = curr->next;
    }
    return curr->data;
}

template<typename T>
void LList<T>::clear() {
    box *save = first;
    while (first != nullptr) {
        first = first->next;
        delete save;
        save = first;
    }
}

template<typename T>
LList<T>::LList(const LList<T> &other) {
    copy(other.first);
}

template<typename T>
LList<T> &LList<T>::operator=(const LList<T> &other) {
    if (this != *other) {
        clear();
        copy(other.first);
    }

    return *this;
}

template<typename T>
void LList<T>::copy(const LList<T>::box *other_first) {
    if (other_first == nullptr) {
        return;
    }
    LList<T>::box *lastCreated = nullptr;
    while (other_first != nullptr) {
        box *newBox = new box{other_first->data, nullptr};
        if (lastCreated != nullptr) {
            lastCreated->next = newBox;
        } else {
            first = newBox;
        }

        lastCreated = newBox;
        other_first = other_first->next;
    }
}

