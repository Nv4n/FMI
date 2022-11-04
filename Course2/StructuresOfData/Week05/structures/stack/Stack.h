//
// Created by Sybatron on 11/3/2022.
//

#ifndef WEEK05_STACK_STACK_H
#define WEEK05_STACK_STACK_H

#pragma once

template<class T>
class Stack {
private:
    struct Node {
        T data;
        Node *next;
    };

    Node *first;

private:
    void erase();

    void copy(const Stack &other);

public:
    Stack();

    Stack(const Stack &other);

    Stack &operator=(const Stack &other);

    virtual ~Stack();

    bool pop();

    void push(const T &el);

    const T &peek();

    bool isEmpty();
};

#include "Stack.inl"

#endif //WEEK05_STACK_STACK_H
