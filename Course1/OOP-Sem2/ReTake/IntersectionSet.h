//
// Created by Sybatron on 8/6/2022.
//

#ifndef RETAKEHW_INTERSECTIONSET_H
#define RETAKEHW_INTERSECTIONSET_H

#include "Set.h"
#include "CriteriaSet.h"
#include "FiniteSet.h"
#include "UnionSet.h"

#pragma once

template<typename T>
class IntersectionSet : public Set<T> {
private:
    T *data;
    size_t size;
    size_t capacity;
    bool (*predicate) = nullptr;
public:
    IntersectionSet(const Set<T> *left, const Set<T> *right);

    IntersectionSet(const IntersectionSet<T> &other);

    IntersectionSet<T> &operator=(const IntersectionSet<T> &other);

    ~IntersectionSet();

    bool doesContains(const T &element) override;

private:
    void copy(const IntersectionSet<T> &other);

    void destroy();
};

#include "IntersectionSet.inl"

#endif //RETAKEHW_INTERSECTIONSET_H
