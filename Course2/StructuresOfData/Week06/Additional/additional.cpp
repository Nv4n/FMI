//
// Created by Sybatron on 11/7/2022.
//
#include <iostream>
#include <cmath>

template<class T>
struct Node {
    T data;
    Node *next;
};
#pragma  region Task01

void absoluteSort(Node<int> *&first) {
    if (first == nullptr) {
        return;
    }

    Node<int> *least = first;
    Node<int> *holder = first->next;
    while (holder != nullptr) {
        if (std::abs(least->data) > std::abs(holder->data)) {
            least = holder;
        }
        holder = holder->next;
    }

    int tmp = first->data;
    first->data = least->data;
    least->data = tmp;
    absoluteSort(first->next);
}

void sortAbsoluteSorted(Node<int> *&first) {
    if (first == nullptr) {
        return;
    }
    Node<int> *prev = first;
    while (prev->next != nullptr) {
        if (prev->next->data < 0) {
            Node<int> *tmp = prev->next;
            prev->next = tmp->next;
            tmp->next = first;
            first = tmp;
        } else {
            prev = prev->next;
        }
    }
}

#pragma endregion;

#pragma Task02

//void reverseList(Node<int>* first){
//    Node<int>* curr=first;
//    Node<int>
//    while(curr!= nullptr)
//}

#pragma endregion

template<class T>
void printList(Node<T> *first) {
    while (first) {
        std::cout << first->data << " -> ";
        first = first->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Node<int> *first = new Node<int>{-5, new Node<int>{12, new Node<int>{-10, new Node<int>{3, nullptr}}}};
    absoluteSort(first);
    sortAbsoluteSorted(first);
    printList(first);
}