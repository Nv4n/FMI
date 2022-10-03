//
// Created by Sybatron on 8/4/2022.
//

#include "FiniteSet.h"

template<typename T>
FiniteSet<T>::FiniteSet(const T *data, size_t length) {
    if (hasDuplicated(data)) {
        throw std::invalid_argument("There are duplicated elements");
    }

    this->type = SetType::FINITE;
    size = length;
    if (length % 8 == 0) {
        capacity = length * 2;
    } else {
        capacity = length + (length % 8);
    }

    this->data = new T[capacity];
    for (int i = 0; i < capacity; ++i) {
        this->data[i] = data[i];
    }
}

template<typename T>
FiniteSet<T>::FiniteSet(const FiniteSet<T> &other) {
    copy(other);
}

template<typename T>
FiniteSet<T> &FiniteSet<T>::operator=(const FiniteSet<T> &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }

    return *this;
}

template<typename T>
FiniteSet<T>::~FiniteSet() {
    destroy();
}

template<typename T>
bool FiniteSet<T>::doesContains(const T &element) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == element) {
            return true;
        }
    }

    return false;
}

template<typename T>
bool FiniteSet<T>::hasDuplicated(const T *data, size_t length) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (data[i] == data[j]) {
                return true;
            }
        }
    }

    return false;
}

template<typename T>
void FiniteSet<T>::copy(const FiniteSet<T> other) {
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];

    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }

    this->type = other.type;
}

template<typename T>
void FiniteSet<T>::destroy() {
    if (data != nullptr) {
        delete[] data;
    }
}

template<typename T>
size_t FiniteSet<T>::getSize() const {
    return size;
}

template<typename T>
size_t FiniteSet<T>::getCapacity() const {
    return capacity;
}

template<typename T>
const T *FiniteSet<T>::getData() const {
    return data;
}
