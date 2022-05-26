//
// Created by Sybatron on 5/26/2022.
//

#ifndef RESTAURANT_QUEUE_H
#define RESTAURANT_QUEUE_H

#include <cstring>

template<typename T>
class Queue {
private:
    size_t size = 0;
    size_t capacity = 16;
    T *storage = new T[capacity];
    size_t first = 0;

public:
    Queue() = default;

    Queue(const Queue<T> &other) = delete;

    Queue<T> &operator=(const Queue<T> &other) = delete;

    ~Queue();

    bool empty() const;

    void push(T element);

    void pop();

    T &front();

    T &back();
};
#include "Queue.inl"
#endif //RESTAURANT_QUEUE_H
