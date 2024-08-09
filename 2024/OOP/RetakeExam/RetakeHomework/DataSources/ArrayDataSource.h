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
    size_t index;
    size_t length;
    size_t size;
    T *elements;
public:
    T get() override;

    T *get(size_t count) override;

    bool hasNext() override;

    bool reset() override;

    T operator()() override;

    DataSource<T> &operator>>(T &output) override;

    explicit operator bool() const override;

    DataSource<T> *clone() override;
};


#include "ArrayDataSource.inl"

#endif //OOPRETAKE_ARRAYDATASOURCE_H
