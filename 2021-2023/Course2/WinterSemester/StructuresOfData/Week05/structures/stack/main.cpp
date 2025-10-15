//
// Created by Sybatron on 11/4/2022.
//
#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> stack;
    stack.push(12);
    stack.push(10);
    stack.push(-10);

    Stack<int> stack2 = stack;
    std::cout << stack2.peek() << std::endl;

    std::cout << stack.peek() << std::endl;
    while (!stack.isEmpty()) {
        std::cout << "HERE!!!!" << " ";
        std::cout << stack.peek() << std::endl;
        std::cout << stack.pop();
    }
    std::cout << std::endl;
    std::cout << stack2.peek() << std::endl;
    std::cout << stack.peek() << std::endl;

}