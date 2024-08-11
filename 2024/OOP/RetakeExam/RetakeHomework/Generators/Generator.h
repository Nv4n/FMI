//
// Created by Sybatron on 7/20/2024.
//

#ifndef OOPRETAKE_GENERATOR_H
#define OOPRETAKE_GENERATOR_H
#pragma once

template<typename T>
class Generator {
public:
    virtual T get() = 0;

    virtual bool hasNext() = 0;

    virtual Generator *clone() = 0;

    virtual bool reset() = 0;
};

#include "Generator.inl"


#endif //OOPRETAKE_GENERATOR_H
