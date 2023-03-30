//
// Created by Sybatron on 11/4/2022.
//
#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> queue;
    queue.push(12);
    queue.push(0);
    queue.push(4);
    queue.push(8);
    queue.push(3);
    Queue<int> queue2 = queue;

    std::cout << queue.peek() << std::endl;
    while (!queue.isEmpty()) {
        std::cout << queue.peek() << " ";
        queue.pop();
    }

    std::cout << std::endl << queue2.peek() << std::endl;
    std::cout << queue.peek() << std::endl;
}