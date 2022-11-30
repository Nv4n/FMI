#include <iostream>
#include <vector>

struct Node {
    int data;
    Node *left;
    Node *right;
};

void listLeavesHelper(Node *root, std::vector<int> &list) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        list.push_back(root->data);
        return;
    }

    listLeavesHelper(root->left, list);
    listLeavesHelper(root->right, list);
}

std::vector<int> listLeaves(Node *root) {
    std::vector<int> res;
    listLeavesHelper(root, res);
    return res;
}

std::string findTrace(Node *root, const int &x) {
    if (root == nullptr) {
        return "_";
    }

    if (root->data == x) {
        return "";
    }

    std::string L = "L" + findTrace(root->left, x);
    std::string R = "R" + findTrace(root->right, x);

    if (L.back() != '_') {
        return L;
    } else if (R.back() != '_') {
        return R;
    } else {
        return "_";
    }
}

int getAtHelper(Node *root, size_t &i) {
    if (root == nullptr) {
        return 0;
    }
    if (i == 0) {
        return root->data;
    }

    int res = getAtHelper(root->left, --i);
    res += getAtHelper(root->right, --i);
    return res;
}

int getAt(Node *root, size_t i) {
    return getAtHelper(root, i);
}

int main() {
    Node *root = new Node{15,
                          new Node{13,
                                   new Node{10},
                                   new Node{14,
                                            new Node{20,
                                                     new Node{0,
                                                              new Node{4}}}}},
                          new Node{25}};

    std::vector<int> test = listLeaves(root);
    for (int i: test) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << findTrace(root, 5) << std::endl;
    std::cout << getAt(root, 20) << std::endl;
}