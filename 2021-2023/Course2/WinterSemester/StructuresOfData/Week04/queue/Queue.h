//
// Created by Sybatron on 10/24/2022.
//

#ifndef WEEK03_STACK_QUEUE_H
#define WEEK03_STACK_QUEUE_H

#include <iostream>
#include "Week05/structures/queue/Queue.h"


#pragma once

template<class T>
class Queue {
private:
    T *data;
    size_t size{};
    size_t capacity{};

private:
    void copy(const Queue &other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];

        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    void erase() {
        delete[] data;
    }

    void resize() {
        capacity *= 2;
        T *temp = new T[capacity];

        for (size_t i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
    }

    bool isEmpty() {
        return size == 0;
    }

public:
    Queue() {
        size = 0;
        capacity = 8;
        data = new T[capacity];
    }

    Queue(const Queue &other) {
        copy(other);
    }

    Queue &operator=(const Queue &other) {
        if (this != &other) {
            erase();
            copy(other);
        }

        return *this;
    }

    ~Queue() {
        erase();
    }

    void push(T el) {
        if (size == capacity) {
            resize();
        }
        data[size++] = el;
    }

    const T &pop() {
        if (isEmpty()) throw "Cannot pop. Queue is empty";

        T save = data[0];
        for (int i = 1; i < size; ++i) {
            data[i - 1] = data[i];
        }

        return save;
    }

    const T &front() {
        if (isEmpty()) {
            return nullptr;
        }

        return data[0];
    }
};

#endif //WEEK03_STACK_QUEUE_H
