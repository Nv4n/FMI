//
// Created by Sybatron on 7/20/2024.
//

#ifndef OOPRETAKE_STATELESSGENERATOR_H
#define OOPRETAKE_STATELESSGENERATOR_H

#include "Generator.h"

template<typename T>
class StatelessGenerator : public Generator<T> {
public:
    using LambdaGenerator = T(*)();

    explicit StatelessGenerator(LambdaGenerator lambda);

    StatelessGenerator(const StatelessGenerator<T> &statelessGen);

    Generator<T> *clone() override;

    T operator()() override;

    bool hasNext() override;

private:
    LambdaGenerator generator;
};

#include "StatelessGenerator.inl"

#endif //OOPRETAKE_STATELESSGENERATOR_H
