//
// Created by Sybatron on 7/21/2024.
//

#ifndef OOPRETAKE_ARRAYDATASOURCE_H
#define OOPRETAKE_ARRAYDATASOURCE_H
#pragma once

#include "DataSource.h"

template<typename T>
class ArrayDataSource : public DataSource<T> {
private:
    size_t currentIndex{};
    size_t length{};
    size_t size{};
    T *data;
public:
    ArrayDataSource(T *arr, size_t arrSize);

    ArrayDataSource(const ArrayDataSource<T> &other);

    ArrayDataSource<T> &operator=(const ArrayDataSource<T> &other);

    ~ArrayDataSource() override;

    T get() override;

    T *get(size_t count) override;

    bool hasNext() override;

    bool reset() override;

    T operator()() override;

    DataSource<T> &operator>>(T &output) override;

    explicit operator bool() override;

    DataSource<T> *clone() override;

    ArrayDataSource<T> &operator+=(T element);

    ArrayDataSource<T> operator+(T element);

    ArrayDataSource<T> operator--(int);

    ArrayDataSource<T> &operator--();


private:
    void destroy();

    void copy(const ArrayDataSource<T> &other);

    void resize();
};


#include "ArrayDataSource.inl"

#endif //OOPRETAKE_ARRAYDATASOURCE_H
