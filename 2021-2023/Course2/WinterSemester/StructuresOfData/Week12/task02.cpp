#include "PrettyPrint.h"

void getSmallestSumOfKHelper(Node<int> *root, int &k, int &sum) {
    if (!root) {
        return;
    }
    getSmallestSumOfKHelper(root->left, k, sum);
    if (k > 0) {
        sum += root->data;
        k--;
    }
    if (k == 0) {
        return;
    }
    getSmallestSumOfKHelper(root->right, k, sum);
}

int getSmallestSumOfK(Node<int> *root, int k) {
    int sum = 0;
    getSmallestSumOfKHelper(root, k, sum);
    return sum;
}

int main() {
    Node<int> *root = new Node<int>{5,
                                    new Node<int>{3,
                                                  new Node<int>{1},
                                                  new Node<int>{4}},
                                    new Node<int>{10,
                                                  new Node<int>{8},
                                                  new Node<int>{20}}};
    std::cout << getSmallestSumOfK(root, 7) << std::endl;
}