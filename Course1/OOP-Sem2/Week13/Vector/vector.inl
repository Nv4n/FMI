//
// Created by Sybatron on 5/23/2022.
//
#include <iostream>
#include <cstring>
#include "vector.h"

template<typename Type>
IStack<Type> &IStack<Type>::operator=(const IStack<Type> &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }

    return *this;
}

template<typename Type>
IStack<Type>::IStack(const IStack<Type> &other) {
    copy(other);
}

template<typename Type>
IStack<Type>::~IStack() {
    destroy();
}

template<typename Type>
void IStack<Type>::copy(const IStack<Type> &other) {
    capacity = other.capacity;
    size = other.size;
}

template<typename Type>
void IStack<Type>::destroy() {
    if (storage != nullptr) {
        delete[] storage;
    }
}

template<typename Type>
void IStack<Type>::pushBack(Type item) {
    if (size + 1 >= capacity) {
        resize();
    }
    storage[size] = item;
    size++;
}

template<typename Type>
void IStack<Type>::resize() {
    capacity *= 2;
    Type *tempStorage = new Type[capacity];
    for (int i = 0; i < size; ++i) {
        tempStorage[i] = storage[i];
    }

    delete[] storage;
    storage = &tempStorage;
}

template<typename Type>
void IStack<Type>::popBack(Type item) {
    size--;
}
