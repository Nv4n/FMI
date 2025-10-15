//
// Created by Sybatron on 11/30/2022.
//
#include <iostream>
#include <cmath>

struct Node {
    const char *data;
    Node *left;
    Node *right;
};

int count(const Node *root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + count(root->left) + count(root->right);
}

int countEvens(const Node *root) {
    if (root == nullptr) {
        return 0;
    }

    return (root->data % 2 == 0 ? 1 : 0)
           + countEvens(root->left)
           + countEvens(root->right);
}

int searchCount(Node *root, bool(*pred)(const int &)) {
    if (root == nullptr || pred == nullptr) {
        return 0;
    }

    return (pred(root->data) ? 1 : 0)
           + searchCount(root->left, pred)
           + searchCount(root->right, pred);
}

int height(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + std::max(height(root->left), height(root->right));
}

int countLeaves(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return 0 + countLeaves(root->left) + countLeaves(root->right);
}

int maxLeaf(Node *root) {
    if (root == nullptr) {
        return -1;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    return std::max(maxLeaf(root->left), maxLeaf(root->right));
}

int getElement(Node *root, const char *s) {
    if (root == nullptr) {
        return -1;
    }
    if (*s == '\0') {
        return root->data;
    }

    if (*s == 'L') {
        getElement(root->left, s + 1);
    } else {
        getElement(root->right, s + 1);
    }
}

int main() {
    Node *root = new Node{5,
                          new Node{3,
                                   new Node{2,
                                            new Node{1},
                                            new Node{5}}},
                          new Node{7,
                                   new Node{6, nullptr, nullptr},
                                   nullptr}};

    std::cout << "count: " << count(root) << std::endl;
    std::cout << "countEvens: " << countEvens(root) << std::endl;
    std::cout << "searchCount: " << searchCount(root, [](const int &a) -> bool { return a >= 5; }) << std::endl;
    std::cout << "height: " << height(root) << std::endl;
    std::cout << "countLeaves: " << countLeaves(root) << std::endl;
    std::cout << "maxLeaf: " << maxLeaf(root) << std::endl;
    std::cout << "getElement: " << getElement(root, "LLR") << std::endl;
}