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

