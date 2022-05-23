//
// Created by Sybatron on 5/23/2022.
//
#include <iostream>
#include <cstring>
#include "vector.h"

template<typename Type>
Vector<Type> &Vector<Type>::operator=(const Vector<Type> &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }

    return *this;
}

template<typename Type>
Vector<Type>::Vector(const Vector<Type> &other) {
    copy(other);
}

template<typename Type>
Vector<Type>::~Vector() {
    destroy();
}

template<typename Type>
void Vector<Type>::copy(const Vector<Type> &other) {
    capacity = other.capacity;
    size = other.size;
}

template<typename Type>
void Vector<Type>::destroy() {
    if (storage != nullptr) {
        delete[] storage;
    }
}

template<typename Type>
void Vector<Type>::pushBack(Type item) {
    if (size + 1 >= capacity) {
        resize();
    }
    storage[size] = item;
    size++;
}

template<typename Type>
void Vector<Type>::resize() {
    capacity *= 2;
    Type *tempStorage = new Type[capacity];
    for (int i = 0; i < size; ++i) {
        tempStorage[i] = storage[i];
    }

    delete[] storage;
    storage = &tempStorage;
}

template<typename Type>
void Vector<Type>::popBack(Type item) {
    size--;
}
