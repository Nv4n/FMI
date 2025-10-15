#include <iostream>
#include "Week12/PrettyPrint.h"

template<class T>
void reverse(Node<T> *root) {
    if (!root) {
        return;
    }
    Node<T> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    reverse(root->left);
    reverse(root->right);
}

int main() {
    Node<int> *root3 = new Node<int>{10,
                                     new Node<int>{5,
                                                   new Node<int>{2}},
                                     new Node<int>{20,
                                                   new Node<int>{7},
                                                   new Node<int>{3,
                                                                 new Node<int>{4}}}};
    prettyPrint(root3);
    std::cout << std::endl;
    reverse(root3);
    prettyPrint(root3);
}