//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_VECTOR_H
#define HW02_LIBRARY_VECTOR_H

#include <iostream>
#include <stdexcept>

template<typename T>
class Vector {
private:
    T *data;
    size_t size;
    size_t capacity;

public:
    // Default constructor
    Vector() : data(nullptr), size(0), capacity(0) {}

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Copy constructor
    Vector(const Vector &other) : data(nullptr), size(other.size), capacity(other.size) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Assignment operator
    Vector &operator=(const Vector &other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.size;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Accessor functions
    size_t Size() const {
        return size;
    }

    bool Empty() const {
        return size == 0;
    }

    T &operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T &operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Modifier functions
    void PushBack(const T &element) {
        if (size >= capacity) {
            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T *newData = new T[newCapacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size++] = element;
    }

    void PopBack() {
        if (size > 0) {
            --size;
        }
    }

};

#include "Vector.inl"

#endif //HW02_LIBRARY_VECTOR_H
