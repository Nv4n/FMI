#include <vector>
#include <iostream>

//binary tree to balanced tree vector [mid element]
struct Node {
    int data;
    Node *left;
    Node *right;
};

void saveTree(Node *&root, std::vector<int> &v) {
    if (!root) {
        return;
    }
    saveTree(root->left, v);
    v.push_back(root->data);
    saveTree(root->right, v);
}

void balanceTree(Node *&root) {
    std::vector<int> v;
    saveTree(root, v);
    for (auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {

}