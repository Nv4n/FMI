//
// Created by Sybatron on 5/26/2023.
//


#include "MinVector.h"

template<typename T>
MinVector<T>::MinVector() {
    size = 0;
    capacity = 8;
    data = new T[capacity];
}

template<typename T>
MinVector<T>::~MinVector() {
    destroy();
}

// Copy
template<typename T>
MinVector<T>::MinVector(const MinVector &other) {
    copy(other);
}

template<typename T>
MinVector<T> &MinVector<T>::operator=(const MinVector<T> &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }
    return *this;
}

// Move
template<typename T>
MinVector<T>::MinVector(MinVector<T> &&other) noexcept {
    move(other);
}

template<typename T>
MinVector<T> &MinVector<T>::operator=(MinVector<T> &&other) noexcept {

    if (this != &other) {
        destroy();
        move(other);
    }
    return *this;

}

// Getters and Setters
template<typename T>
size_t MinVector<T>::getSize() const {
    return size;
}

template<typename T>
bool MinVector<T>::isEmpty() const {
    return size == 0;
}

/**
 *
 * @tparam T
 * @param index
 * @return T element
 * @throw out_of_range("Index out of range")
 */
template<typename T>
T &MinVector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

/**
 *
 * @tparam T
 * @param index
 * @return T element
 * @throw out_of_range("Index out of range")
 */
template<typename T>
const T &MinVector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
void MinVector<T>::erase() {
    delete[] data;
    size = 0;
    capacity = 8;
    data = new T[capacity];
}

// Adds and Removes
template<typename T>
void MinVector<T>::pushBack(const T &element) {
    if (size >= capacity) {
        scaleUp();
    }
    data[size++] = element;
}

template<typename T>
void MinVector<T>::popBack() {
    if (size > 0) {
        --size;
    }
}

template<typename T>
void MinVector<T>::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; ++i) {
        std::swap(data[i], data[i + 1]);
    }
    --size;
}

// Sort
template<typename T>
void MinVector<T>::sort(int (*comparator)(T &, T &)) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - 1 - i; ++j) {
            if (comparator(data[j], data[j + 1]) > 0) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

// Comparators
template<typename T>
bool MinVector<T>::includes(const T &el) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == el) {
            return true;
        }
    }
    return false;
}

// Read and Write
template<typename T>
std::ostream &operator<<(std::ostream &os, const MinVector<T> &vec) {
    for (size_t i = 0; i < vec.size; ++i) {
        os << vec.data[i];
    }
    return os;
}

template<typename T>
std::istream &operator>>(std::istream &is, MinVector<T> &vec) {
    T element;
    while (is >> element) {
        vec.pushBack(element);
    }
    return is;
}


// Private
template<typename T>
void MinVector<T>::move(MinVector<T> &other) noexcept {
    size = other.size;
    capacity = other.capacity;
    data = other.data;

    other.size = 0;
    other.capacity = 8;
    other.data = new T[other.capacity];
}

template<typename T>
void MinVector<T>::copy(const MinVector<T> &other) {
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
void MinVector<T>::scaleUp() {
    capacity = (capacity == 0) ? 8 : capacity * 2;
    T *tmp = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        tmp[i] = data[i];
    }
    delete[] data;
    data = tmp;
}

template<typename T>
void MinVector<T>::destroy() {
    delete[] data;
}