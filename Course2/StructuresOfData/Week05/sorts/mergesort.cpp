//
// Created by Sybatron on 11/3/2022.
//
#include <iostream>

struct Node {
    int data;
    Node *next;
};

void split(Node *list, Node *&listA, Node *&listB) {
    if (list == nullptr) {
        return;
    }

    Node *slow = list;
    Node *fast = list->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    listA = list;
    listB = slow->next;
    slow->next = nullptr;
}

Node *sortedMerge(Node *listA, Node *listB) {
    if (listA == nullptr) {
        return listB;
    }
    if (listB == nullptr) {
        return listA;
    }

    Node *result;

    if (listA->data <= listB->data) {
        result = new Node{listA->data, nullptr};
        Node *save = listA->next;
        listA->next = nullptr;
        delete listA;
        result->next = sortedMerge(save, listB);
    } else {
        result = new Node{listB->data, nullptr};
        Node *save = listB->next;
        listB->next = nullptr;
        delete listB;
        result->next = sortedMerge(listA, save);
    }

    return result;
}

void mergeSort(Node *&list) {
    if (list == nullptr || list->next == nullptr) {
        return;
    }

    Node *listA;
    Node *listB;
    split(list, listA, listB);

    mergeSort(listA);
    mergeSort(listB);

    list = sortedMerge(listA, listB);
}

void printList(Node *list) {
    while (list != nullptr) {
        std::cout << list->data << " ";
        list = list->next;
    }
    std::cout << std::endl;
}

void eraseList(Node *list) {
    if (list == nullptr) {
        return;
    }
    while (list != nullptr) {
        Node *holder = list->next;
        list->next = nullptr;
        delete list;
        list = holder;
    }
}

int main() {
    Node *list = new Node{15,
                          new Node{0,
                                   new Node{23,
                                            new Node{-1,
                                                     new Node{23,
                                                              new Node{1, nullptr}}}}}};
    mergeSort(list);
    printList(list);
    eraseList(list);
}
