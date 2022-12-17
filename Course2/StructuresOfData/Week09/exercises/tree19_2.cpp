//
// Created by Sybatron on 11/30/2022.
//
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

struct Node {
    const char *data;
    Node *left;
    Node *right;
};

int length(int num) {
    if (num == 0)
        return 1;

    num = std::abs(num);

    int tmp = 1;
    int count = 0;
    for (; tmp <= num; ++count) {
        tmp *= 10;
    }
    return count;
}

void prettyPrintHelper(Node *root, int &row, int spaces = 0) {
    if (root == nullptr) {
        return;
    }

    int numSpaces = length(root->data);
    prettyPrintHelper(root->right, row, spaces + 1 + numSpaces);
    std::cout << row << ": ";
    for (int i = 0; i < spaces; ++i) {
        std::cout << " ";
    }
    std::cout << root->data << std::endl;
    row++;
    prettyPrintHelper(root->left, row, spaces + 1 + numSpaces);
}

void prettyPrint(Node *root) {
    int row = 1;
    prettyPrintHelper(root, row);
}


std::string serializeTree(Node *root) {
    if (root == nullptr) {
        return "()";
    }
    std::string result =
            "(" + std::to_string(root->data) +
            " " + serializeTree(root->right) +
            " " + serializeTree(root->left) + ")";
    return result;
}

std::string serializeTreeHaskell(Node *root, int row = 0) {
    if (root == nullptr) {
        return " Empty";
    }
    std::string spaces(row * 5, ' ');
    return "\n" + spaces + "Node " + std::to_string(root->data) + serializeTreeHaskell(root->left, row + 1) +
           serializeTreeHaskell(root->right, row + 1);
}

Node *parseHelper(std::istream &in) {
    assert(in.get() == '(');

    if (in.peek() == ')') {
        in.get();
        return nullptr;
    }

    int data;
    in >> data;
    assert(in.get() == ' ');
    Node *right = parseHelper(in);
    assert(in.get() == ' ');
    Node *left = parseHelper(in);
    assert(in.get() == ')');

    return new Node{data, left, right};
}

Node *parse(std::string &scheme) {
    std::stringstream input(scheme);
    return parseHelper(input);
}

int main() {
    Node *root = new Node{10,
                          new Node{5},
                          new Node{20,
                                   new Node{15},
                                   new Node{25}}};

    prettyPrint(root);
//    std::string scheme = serializeTree(root);
//    Node *root2 = parse(scheme);
//    prettyPrint(root2);

    std::cout << serializeTreeHaskell(root);
}