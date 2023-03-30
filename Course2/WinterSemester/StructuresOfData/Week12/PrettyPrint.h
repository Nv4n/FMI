//
// Created by Sybatron on 12/21/2022.
//

#pragma once

#include <iostream>
#include <string>

template<class T>
struct Node {
    T data;
    Node *left;
    Node *right;
};

int length(int num) {
    int count = num <= 0 ? 1 : 0;
    for (; num > 0; ++count) {
        num /= 10;
    }
    return count;
}

template<class T>
void prettyPrintHelper(Node<T> *root, int &row, int spaces = 0) {
    if (!root) {
        return;
    }

    int numSpaces = length(root->data);
    prettyPrintHelper(root->right, row, spaces + 1 + numSpaces);
    std::cout << row << ": "
              << std::string(spaces, ' ')
              << root->data << std::endl;
    prettyPrintHelper(root->left, ++row, spaces + 1 + numSpaces);
}

template<class T>
void prettyPrint(Node<T> *root) {
    int row = 1;
    prettyPrintHelper(root, row);
}