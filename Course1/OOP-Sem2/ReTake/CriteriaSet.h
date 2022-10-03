//
// Created by Sybatron on 8/5/2022.
//

#ifndef RETAKEHW_CRITERIASET_H
#define RETAKEHW_CRITERIASET_H

#include "Set.h"

#pragma once

template<typename T>
class CriteriaSet : public Set<T> {
private:
    bool (*predicate);
public:
    CriteriaSet(bool (*predicate)(const T &element));

    CriteriaSet(const CriteriaSet<T> &other);

    CriteriaSet<T> &operator=(const CriteriaSet<T> &other);

    virtual ~CriteriaSet();

    bool doesContains(const T &element) override;

private:

    void copy(const CriteriaSet<T> other);

    void destroy();
};

#include "CriteriaSet.inl"

#endif //RETAKEHW_CRITERIASET_H
