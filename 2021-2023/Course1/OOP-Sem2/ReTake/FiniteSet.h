//
// Created by Sybatron on 8/4/2022.
//

#ifndef RETAKEHW_FINITESET_H
#define RETAKEHW_FINITESET_H

#include <iostream>
#include <stdexcept>
#include "Set.h"

#pragma once

template<typename T>
class FiniteSet : public Set<T> {
private:
    T *data;
    size_t size;
    size_t capacity;
public:
    FiniteSet(const T *data, size_t length);

    FiniteSet(const FiniteSet<T> &other);

    FiniteSet<T> &operator=(const FiniteSet<T> &other);

    virtual ~FiniteSet();

    bool doesContains(const T &element) override;

    size_t getSize() const;

    size_t getCapacity() const;

    const T *getData() const;

private:
    bool hasDuplicated(const T *data, size_t length);

    void copy(const FiniteSet<T> other);

    void destroy();
};

#include "FiniteSet.inl"

#endif //RETAKEHW_FINITESET_H
