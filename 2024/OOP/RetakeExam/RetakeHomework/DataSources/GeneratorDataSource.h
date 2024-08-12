//
// Created by Sybatron on 7/20/2024.
//

#ifndef OOPRETAKE_GENERATORDATASOURCE_H
#define OOPRETAKE_GENERATORDATASOURCE_H

#pragma once

#include "DataSource.h"
#include "../Generators/Generator.h"

template<typename T>
class GeneratorDataSource : public DataSource<T> {
private:
    Generator<T> *generator;
public:

    explicit GeneratorDataSource(Generator<T> *generator);

    ~GeneratorDataSource() override;

    GeneratorDataSource(const GeneratorDataSource<T> &other);

    GeneratorDataSource<T> &operator=(const GeneratorDataSource<T> &other);

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

    void copy(const GeneratorDataSource<T> &other);
};


#include "GeneratorDataSource.inl"


#endif //OOPRETAKE_GENERATORDATASOURCE_H
