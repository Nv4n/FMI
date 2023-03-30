#include <iostream>
#include <cmath>

template<class T>
struct Node {
    T data;
    Node<T> *left;
    Node<T> *right;
};

Node<int> *createPBT(int h, int level = 1) {
    if (level > h) {
        return nullptr;
    }

    Node<int> *root = new Node<int>{level};
    root->left = createPBT(h, level + 1);
    root->right = createPBT(h, level + 1);

    return root;
}

template<class T>
std::string serializeTreeHaskell(Node<char> *root, int row = 0) {
    if (root == nullptr) {
        return " Empty";
    }
    std::string spaces(row * 5, ' ');
    return "\n" + spaces + "Node " + root->data + serializeTreeHaskell<char>(root->left, row + 1) +
           serializeTreeHaskell<char>(root->right, row + 1);
}

template<class T>
std::string serializeTreeHaskell(Node<T> *root, int row = 0) {
    if (root == nullptr) {
        return " Empty";
    }
    std::string spaces(row * 5, ' ');
    return "\n" + spaces + "Node " + std::to_string(root->data) + serializeTreeHaskell<T>(root->left, row + 1) +
           serializeTreeHaskell<T>(root->right, row + 1);
}


Node<char> *wordToTree(int h, char *&s, int level = 0) {
    if (*s == '\0') {
        return new Node<char>{' '};
    }

    if (level == h) {
        Node<char> *root = new Node<char>{*s};
        ++s;
        return root;
    }

    Node<char> *root = new Node<char>{' '};
    root->left = wordToTree(h, s, level + 1);
    root->right = wordToTree(h, s, level + 1);

    return root;
}

int count(Node<int> *root) {
    if (!root) {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

Node<int> *subtreeCountTree(Node<int> *root) {
    if (!root) {
        return nullptr;
    }
    return new Node<int>{count(root),
                         subtreeCountTree(root->left),
                         subtreeCountTree(root->right)};
}

int main() {
    Node<int> *root = createPBT(4);
    std::cout << serializeTreeHaskell<int>(root) << std::endl;
    char *str = new char[6]{'H', 'e', 'l', 'l', 'o'};
//    int n = 5;
    int h = 0;
    for (int n = 5; n >= std::pow(2, h); ++h);

    Node<char> *root2 = wordToTree(h, str);
    std::cout << serializeTreeHaskell<char>(root2) << std::endl;

    Node<int> *root3 = new Node<int>{10,
                                     new Node<int>{5,
                                                   new Node<int>{2}},
                                     new Node<int>{20,
                                                   new Node<int>{15},
                                                   new Node<int>{25,
                                                                 new Node<int>{22}}}};
    std::cout << serializeTreeHaskell<int>(subtreeCountTree(root3)) << std::endl;
}