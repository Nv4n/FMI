#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;
};

void reverse(Node *root) {
    if (!root) {
        return;
    }
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    reverse(root->left);
    reverse(root->right);
}

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

int main() {
    Node *root3 = new Node{10,
                           new Node{5,
                                    new Node{2}},
                           new Node{20,
                                    new Node{7},
                                    new Node{3,
                                             new Node{4}}}};
    prettyPrint(root3);
    std::cout << std::endl;
    reverse(root3);
    prettyPrint(root3);
}