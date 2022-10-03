//
// Created by Sybatron on 8/4/2022.
//

#ifndef RETAKEHW_SET_H
#define RETAKEHW_SET_H


enum SetType {
    UNKNOWN = -1,
    FINITE,
    CRITERIA,
    UNION,
    INTERSECTION,
    SETCOUNT
};

#pragma once

template<typename T>
class Set {
protected:
    SetType type;
public:
    virtual ~Set();

    virtual bool doesContains(const T &element) = 0;
};

#include "Set.inl"

#endif //RETAKEHW_SET_H