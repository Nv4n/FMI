//
// Created by Sybatron on 11/7/2022.
//
#include <iostream>

struct Node {
    int data;
    Node *next;
};

void addOne(Node *&first) {
    if (first == nullptr) {
        throw "Fun";
    }

    Node *nines = nullptr;
    Node *ind = first;
    while (ind->next != nullptr) {
        ind = ind->next;
        if (ind->data != 9) {
            nines = ind;
        }
    }

    if (ind->data == 9) {
        if (nines == nullptr) {
            nines = first;
            first = new Node{1, first};
        } else {
            nines->data++;
            nines = nines->next;
        }

        while (nines != nullptr) {
            nines->data = 0;
            nines = nines->next;
        }
    } else {
        ind->data++;
    }
}

void printList(Node *first) {
    while (first) {
        std::cout << first->data << " -> ";
        first = first->next;
    }
    std::cout << "nullptr" << std::endl;
}
//
//int main() {
//    Node *first = new Node{9,
//                           new Node{9,
//                                    new Node{9,
//                                             new Node{9,
//                                                      new Node{9,
//                                                               new Node{9, nullptr}}}}}};
//    addOne(first);
//    printList(first);
//}