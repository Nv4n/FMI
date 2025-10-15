//
// Created by Sybatron on 8/11/2024.
//

#ifndef OOPRETAKE_ALTERNATEDATASOURCE_H
#define OOPRETAKE_ALTERNATEDATASOURCE_H
#pragma once

#include "DataSource.h"

template<typename T>
class AlternateDataSource : public DataSource<T> {
private:
    DataSource<T> **data;
    size_t size{};
    size_t currentIndex{};
public:
    AlternateDataSource(DataSource<T> **sources, size_t length);

    ~AlternateDataSource() override;

    AlternateDataSource(const AlternateDataSource<T> &other);

    AlternateDataSource<T> &operator=(const AlternateDataSource<T> &other);

    T get() override;

    T *get(size_t count) override;

    bool hasNext() override;

    bool reset() override;

    T operator()() override;

    DataSource<T> &operator>>(T &output) override;

    explicit operator bool() override;

    DataSource<T> *clone() override;

private:
    void destroy();

    void copy(const AlternateDataSource<T> &other);
};


#include "AlternateDataSource.inl"

#endif //OOPRETAKE_ALTERNATEDATASOURCE_H
