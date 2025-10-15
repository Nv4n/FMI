//
// Created by Sybatron on 11/28/2022.
//
#include <iostream>

struct Node {
    const char *data;
    Node *left;
    Node *right;
};

void printTree(Node *root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

void toBts(Node *&root, int *arr, int size) {
    if (arr == nullptr || size < 1) {
        return;
    }

    root = new Node{*(arr + size / 2), nullptr, nullptr};
    toBts(root->left, arr, size / 2);
    toBts(root->right, arr + size / 2 + 1, size - size / 2 - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node *root;
    toBts(root, arr, 5);
    printTree(root);
}