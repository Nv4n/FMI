//
// Created by Sybatron on 12/19/2022.
//
#include <iostream>
#include <queue>

struct Node {
    int data;
    Node *left;
    Node *right;
};

//void printViewL(Node *root, bool canBeSeen) {
//    std::queue<Node *> q;
//    q.push(root);
//    q.push(nullptr);
//    while (!q.empty()) {
//        Node *temp = q.front();
//        q.pop();
//
//        if (!temp) {
//            if (q.empty()) {
//                break;
//            }
//            q.push(nullptr);
//            std::cout << q.front()->data << " ";
//            continue;
//        }
//
//        if (temp->left) {
//            q.push(temp->left);
//        }
//        if (temp->right) {
//            q.push(temp->right);
//        }
//    }
//}


void getViewL(Node *root, int level, std::vector<int> &v) {
    if (!root) {
        return;
    }
    if (v.size() <= level) {
        v.push_back(root->data);
    }
    getViewL(root->left, level + 1, v);
    getViewL(root->right, level + 1, v);
}

void getViewR(Node *root, int level, std::vector<int> &v) {
    if (!root) {
        return;
    }
    if (v.size() <= level) {
        v.push_back(root->data);
    }
    getViewR(root->right, level + 1, v);
    getViewR(root->left, level + 1, v);
}


int main() {

}