//
// Created by Sybatron on 11/17/2022.
//
#include <iostream>

struct Node {
    int data;
    Node *next;
};

bool empty(Node *stack) {
    return stack == nullptr;
}

void pop(Node *&stack) {
    if (!stack) {
        return;
    }

    Node *tmp = stack;
    stack = stack->next;
    delete tmp;
}

int peek(Node *stack) {
    return stack->data;
}

int printRStack(Node *stack) {
    if (empty(stack)) {
        return 0;
    }
    int tmp = (*stack).data;
    std::cout << printRStack(stack->next) << " " << tmp << "-";
}

int main() {
    Node *stack = new Node{5, new Node{3, new Node{2, new Node{1, nullptr}}}};
    printRStack(stack);
}