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
bool equals(Node<T> *t1, Node<T> *t2) {
    if (!t1 && !t2) {
        return true;
    }
    if (!t1 || !t2) {
        return false;
    }
    return t1->data == t2->data && equals(t1->left, t2->left) && equals(t1->right, t2->right);
}

template<class T>
bool isSubTree(Node<T> *t1, Node<T> *t2) {
    if (!t2) {
        return true;
    }
    if (!t1) {
        return false;
    }
    return equals(t1, t2) || isSubTree(t1->left, t2) || isSubTree(t1->right, t2);
}
