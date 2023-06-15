//
// Created by Sybatron on 5/11/2023.
//

#ifndef PROJECT_SOCIALMEDIA_SET_H
#define PROJECT_SOCIALMEDIA_SET_H
#pragma once

template<typename T>
class Set {
private:
    struct Node {
        T data;
        Node *next;

        Node(T data) : data(data), next(nullptr) {};
    };

    Node *root;
    int size;
public:
    Set() : root(nullptr), size(0) {}

    ~Set();

    bool contains(const T &elem) const;

    bool insert(const T &elem);

    void remove(const T &elem);

    int getSize() const;
};


#include "Set.inl"

#endif //PROJECT_SOCIALMEDIA_SET_H
