//
// Created by Sybatron on 11/3/2022.
//
#include <iostream>

#pragma region MergeSort
struct Node {
    int data;
    Node *next;
};

void split(Node *list, Node *&a, Node *&b) {
    if (list == nullptr) {
        return;
    }
    Node *fast = list->next;
    Node *slow = list;
    if (fast == nullptr) {
        return;
    }

    fast = fast->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    a = list;
    b = slow->next;
    slow->next = nullptr;
}

Node *sortedMerge(Node *a, Node *b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }

}

void mergeSort(Node *&list) {
    Node *a = nullptr;
    Node *b = nullptr;

    while (list != nullptr) {
        split(list, a, b);

        mergeSort(a);
        mergeSort(b);
    }

    list = sortedMerge(a, b);
}

#pragma endregion

int main() {
    Node *list =
            new Node{10,
                     new Node{-10,
                              new Node{5,
                                       new Node{23,
                                                new Node{10,
                                                         new Node{15,
                                                                  new Node{0, nullptr}}}}}}};
}