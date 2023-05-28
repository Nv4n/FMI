//
// Created by Sybatron on 5/26/2023.
//

#ifndef HW02_LIBRARY_MINVECTOR_H
#define HW02_LIBRARY_MINVECTOR_H

#include <iostream>
#include <stdexcept>

#pragma once

template<typename T>
class MinVector {
private:
    T *data;
    size_t size{};
    size_t capacity{};

public:
    MinVector();

    ~MinVector();

    MinVector(const MinVector<T> &other);

    MinVector(MinVector<T> &&other) noexcept;

    MinVector<T> &operator=(const MinVector<T> &other);

    MinVector<T> &operator=(MinVector<T> &&other) noexcept;

    size_t getSize() const;

    bool isEmpty() const;

    T &operator[](size_t index);

    const T &operator[](size_t index) const;

    void pushBack(const T &element);

    void popBack();

    void remove(size_t index);

    friend std::ostream &operator<<(std::ostream &os, const MinVector<T> &vec);

    friend std::istream &operator>>(std::istream &is, MinVector<T> &vec);

    void sort(int (*comparator)(T &, T &));

    void erase();

private:
    void exchange(T &lvs, T &rvs);

    void copy(const MinVector<T> &other);

    void move(MinVector<T> &other) noexcept;

    void scaleUp();

    void destroy();
};


#include "MinVector.inl"

#endif //HW02_LIBRARY_MINVECTOR_H
