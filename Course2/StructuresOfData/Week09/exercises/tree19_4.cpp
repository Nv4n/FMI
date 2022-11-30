#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>

struct Node {
    char data;
    Node *left;
    Node *right;
};

bool digit(char c) {
    return c >= '1' && c <= '9';
}

void parserHelper(Node *&root, std::stringstream &in) {
    if (!in || in.eof()) {
        return;
    }


    if (in.peek() != '(') {
        // <digit>)
        char next = in.get();
        root = new Node{next};
        in.get();
        return;
    }

    // (<digit>...
    in.get();
    char next = in.get();
    assert(digit(next));

    // (<digit>)
    if (in.peek() == ')') {
        in.get();
        root = new Node{next};
        return;
    }

    // (<exp><op><exp>)
    char op = in.get();
    root = new Node{op};
    root->left = new Node{next};

    parserHelper(root->right, in);
}

Node *parseExpression(const std::string &s) {
    Node *root = nullptr;
    std::stringstream in(s);
    parserHelper(root, in);
    return root;
}

void prettyPrintHelper(Node *root, int &row, int spaces = 0) {
    if (root == nullptr) {
        return;
    }

    prettyPrintHelper(root->right, row, spaces + 2);
    std::cout << row << ": ";
    for (int i = 0; i < spaces; ++i) {
        std::cout << " ";
    }
    std::cout << root->data << std::endl;
    row++;
    prettyPrintHelper(root->left, row, spaces + 2);
}

void prettyPrint(Node *root) {
    int row = 1;
    prettyPrintHelper(root, row);
}

double calculateExpresisonTree(Node *root) {
    if (!root->left && !root->right) {
        return root->data - '0';
    }
    switch (root->data) {
        case '+':
            return calculateExpresisonTree(root->left) + calculateExpresisonTree(root->right);
        case '-':
            return calculateExpresisonTree(root->left) - calculateExpresisonTree(root->right);
        case '*':
            return calculateExpresisonTree(root->left) * calculateExpresisonTree(root->right);
        case '/':
            return calculateExpresisonTree(root->left) / calculateExpresisonTree(root->right);

    }
}

int main() {
    Node *root = parseExpression("(1*(2+3)");
    prettyPrint(root);
    std::cout << calculateExpresisonTree(root) << std::endl;
}