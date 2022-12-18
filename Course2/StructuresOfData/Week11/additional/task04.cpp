#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;
};

int sumOfTree(Node *root) {
    if (!root) {
        return 0;
    }
    return root->data + sumOfTree(root->left) + sumOfTree(root->right);
}

int countSumEqualSubtree(Node *root, int sum) {
    if (!root) {
        return 0;
    }
    return sumOfTree(root) == sum ? 1 : 0
                                        + countSumEqualSubtree(root->left, sum)
                                        + countSumEqualSubtree(root->right, sum);
}


int main() {
    Node *root3 = new Node{10,
                           new Node{5,
                                    new Node{2}},
                           new Node{20,
                                    new Node{7},
                                    new Node{3,
                                             new Node{4}}}};
    std::cout << countSumEqualSubtree(root3, 7) << std::endl;
}
