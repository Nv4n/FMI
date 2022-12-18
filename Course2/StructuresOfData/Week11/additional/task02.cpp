#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;
};

void printNodesAtLevel(Node *root, int k) {
    if (!root) {
        return;
    }
    if (k == 0) {
        std::cout << root->data << " ";
        return;
    }
    printNodesAtLevel(root->left, k - 1);
    printNodesAtLevel(root->right, k - 1);
}

int main() {
//    Node root
}