//
// Created by Sybatron on 11/4/2022.
//

#ifndef WEEK05_STACK_QUEUE_H
#define WEEK05_STACK_QUEUE_H

#pragma once

template<class T>
class Queue {
private:
    struct Node {
        T data;
        Node *next;
    };

    Node *front;
    Node *back;
private:
    void copy(const Queue &other);

    void erase();

public:
    Queue();

    Queue(const Queue &other);

    Queue<T> &operator=(const Queue &other);

    virtual ~Queue();

    void push(const T &el);

    void pop();

    const T &peek();

    bool isEmpty();
};

#include "Queue.inl"

#endif //WEEK05_STACK_QUEUE_H
