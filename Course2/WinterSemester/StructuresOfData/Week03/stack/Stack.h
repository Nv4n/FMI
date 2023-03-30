//
// Created by Sybatron on 10/17/2022.
//

#ifndef WEEK03_STACK_STACK_H
#define WEEK03_STACK_STACK_H

#include <iostream>

#pragma once

template<class T>
class Stack {
private:
    size_t size{};
    size_t capacity{};
    T *data;
private:
    void resize() {
        T *temp = new T[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }

    void erase() {
        delete[] data;
    }

    void copy(const Stack<T> &other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
    }

public:
    Stack() {
        capacity = 8;
        size = 0;
        data = new T[capacity];
    }

    Stack(const Stack<T> &other) {
        copy(other);
    }

    Stack<T> &operator=(const Stack<T> &other) {
        if (this != &other) {
            erase();
            copy(other);
        }
        return *this;
    }

    ~Stack() {
        erase();
    }

    void push(const T &element) {
        if (size == capacity)
            resize();
        data[size++] = element;
    }

    T &peek() const {
        if (isEmpty())
            throw "Stack is empty";
        return data[size - 1];
    }

    T &pop() {
        if (isEmpty())
            throw "Stack is empty";
        return data[size-- - 1];
    }

    bool isEmpty() {
        return size == 0;
    }
};


#endif //WEEK03_STACK_STACK_H
