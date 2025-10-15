#include <iostream>

template<class T>
struct Node {
    T data;
    Node *left;
    Node *right;
};

bool equals(Node<char> *t1, Node<char> *t2) {
    if (!t1 && !t2) {
        return true;
    }
    if (!t1 || !t2) {
        return false;
    }
    return t1->data == t2->data && equals(t1->left, t2->left) && equals(t1->right, t2->right);
}

bool isSubTree(Node<char> *t1, Node<char> *t2) {
    if (!t2) {
        return true;
    }
    if (!t1) {
        return false;
    }
    return equals(t1, t2) || isSubTree(t1->left, t2) || isSubTree(t1->right, t2);
}

int main() {
    Node<char> *root2 = new Node<char>{'a',
                                       new Node<char>{'b',
                                                      new Node<char>{'c'}},
                                       new Node<char>{'d',
                                                      new Node<char>{'e', nullptr,
                                                                     new Node<char>{'f'}},
                                                      new Node<char>{'g'}}};
    Node<char> *root3 = new Node<char>{'c',
                                       new Node<char>{'e', nullptr,
                                                      new Node<char>{'f'}},
                                       new Node<char>{'g'}};
    std::cout << std::boolalpha << isSubTree(root2, root3);
}