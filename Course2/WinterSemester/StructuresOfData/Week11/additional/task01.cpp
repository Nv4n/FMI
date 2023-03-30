#include <vector>
#include <iostream>

//binary tree to balanced tree vector [mid element]
struct Node {
    int data;
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

void saveTree(Node *&root, std::vector<int> &v) {
    if (!root) {
        return;
    }
    saveTree(root->left, v);
    v.push_back(root->data);
    saveTree(root->right, v);
}

void convertToBBT(Node *&root, std::vector<int> &v, int start, int end) {
    if (start > end) {
        return;
    }
    int midElement = (start + end) / 2;
    std::cout << v[midElement] << " ";
    root = new Node{v[midElement]};
    convertToBBT(root->left, v, start, midElement - 1);
    convertToBBT(root->right, v, midElement + 1, end);
}

void delTree(Node *&root) {
    if (!root) {
        return;
    }
    delTree(root->left);
    delTree(root->right);
    delete root;
    root = nullptr;
}

void balanceTree(Node *&root) {
    std::vector<int> v;
    saveTree(root, v);
    for (auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    delTree(root);
    convertToBBT(root, v, 0, v.size() - 1);
    std::cout << std::endl;
}

int main() {
    Node *root3 = new Node{10,
                           new Node{5,
                                    new Node{2}},
                           new Node{20,
                                    new Node{11},
                                    new Node{22,
                                             new Node{21},
                                             new Node{5025}}}};

    balanceTree(root3);
    prettyPrint(root3);
}