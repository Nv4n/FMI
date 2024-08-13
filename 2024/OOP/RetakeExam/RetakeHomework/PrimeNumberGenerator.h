//
// Created by Sybatron on 8/12/2024.
//

#ifndef OOPRETAKE_PRIMENUMBERGENERATOR_H
#define OOPRETAKE_PRIMENUMBERGENERATOR_H
#pragma once

#include <iostream>
#include "Generator.h"

template<typename L, typename R>
struct is_same {
    static const bool value = false;
};

template<typename L>
struct is_same<L, L> {
    static const bool value = true;
};

template<typename T>
class PrimeNumberGenerator : public Generator<T> {
private:
    T currentNumber;
    size_t size{};
    size_t length{};
    T *prevPrimeNums;
public:
    PrimeNumberGenerator();

    virtual ~PrimeNumberGenerator();

    PrimeNumberGenerator(const PrimeNumberGenerator<T> &other);

    PrimeNumberGenerator<T> &operator=(const PrimeNumberGenerator<T> &other);

    T get() override;

    bool hasNext() override;

    Generator<T> *clone() override;

    bool reset() override;

private:
    void copy(const PrimeNumberGenerator<T> &other);

    void destroy();

    void resize();

    bool isNumber();
};


#include "PrimeNumberGenerator.inl"

#endif //OOPRETAKE_PRIMENUMBERGENERATOR_H
