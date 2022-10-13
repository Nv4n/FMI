//
// Created by Sybatron on 10/13/2022.
//

#ifndef WEEK02_LINKEDLIST_LLIST_H
#define WEEK02_LINKEDLIST_LLIST_H
#pragma once

template<typename T>
class LList {
private:
    struct box {
        T data;
        box *next;
    };

    box *first;
public:
    LList();

    void pushFront(const T &element);

    void print();

    size_t size() const;

    const T &operator[](size_t i) const;
};

#include "LList.inl"

#endif //WEEK02_LINKEDLIST_LLIST_H
