//
// Created by Sybatron on 7/19/2024.
//

#ifndef OOPRETAKE_DEFAULTDATASOURCE_H
#define OOPRETAKE_DEFAULTDATASOURCE_H

#pragma once

#include "DataSource.h"

template<typename T>
class DefaultDataSource : public DataSource<T> {
public:
    T get() override;

    T *get(size_t count) override;

    bool hasNext() override;

    bool reset() override;

    T operator()() override;

    DataSource<T> &operator>>(T &output) override;

    explicit operator bool() override;

    DataSource<T> *clone() override;

};

#include "DefaultDataSource.inl"

#endif //OOPRETAKE_DEFAULTDATASOURCE_H
