//
// Created by Sybatron on 7/20/2024.
//

#ifndef OOPRETAKE_STATELESSGENERATOR_H
#define OOPRETAKE_STATELESSGENERATOR_H

#pragma once

#include "Generator.h"

template<typename T>
class StatelessGenerator : public Generator<T> {
public:
    using LambdaGenerator = T(*)();
private:
    LambdaGenerator generator;
public:
    explicit StatelessGenerator(LambdaGenerator lambda);

    StatelessGenerator(const StatelessGenerator<T> &other);

    StatelessGenerator<T> &operator=(const StatelessGenerator<T> &other);

    Generator<T> *clone() override;

    T get() override;

    bool hasNext() override;

    bool reset() override;

private:
    void copy(const StatelessGenerator<T> &other);
};


#include "StatelessGenerator.inl"

#endif //OOPRETAKE_STATELESSGENERATOR_H
