//
// Created by Sybatron on 12/19/2022.
//
#include <iostream>

template<class T>
struct Node {
    T data;
    Node *left;
    Node *right;
};

template<class T>
bool hasSameData(Node<T> *root, T &data) {
    if (!root) {
        return true;
    }
    return root->data == data && hasSameData(root->left, data) && hasSameData(root->right, data);
}

template<class T>
int findUniversalTree(Node<T> *root) {
    if (!root) {
        return true;
    }

    return (hasSameData(root, root->data) ? 1 : 0)
           + findUniversalTree(root->left)
           + findUniversalTree(root->right);
}

int main() {

}