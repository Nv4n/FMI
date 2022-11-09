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

template<class T>
bool areEqualLists(Node<T> *a, Node<T> *b);

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

#pragma region Task02

template<class T = int>
void reverseList(Node<T> *&first) {
    //FIXME
    //  - reverse breaks the lists
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node<T> *curr = first;
    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    first = prev;
}

template<class T>
bool areEqualLists(Node<T> *a, Node<T> *b) {
    Node<T> *currA = a;
    Node<T> *currB = b;

    while (currA != nullptr) {
        if (currB == nullptr) {
            return false;
        }

        if (currA->data != currB->data) {
            return false;
        }
        currA = currA->next;
        currB = currB->next;
    }

    return currB == nullptr;
}

template<class T = int>
bool isPalindrom(Node<T> *first) {
    Node<T> *reversed = first;
    reverseList<T>(reversed);
    return areEqualLists(first, reversed);
}

#pragma endregion

#pragma region Task04

template<class T>
bool isSorted(Node<T> *first) {
    if (!first || !first->next) {
        return true;
    }

    while (first->next) {
        if (first->data > first->next->data) {
            return false;
        }

        first = first->next;
    }

    return true;
}

template<class T>
void getMiddle(Node<T> *first, Node<T> *&begin, Node<T> *&middle) {
    if (!first) {
        return;
    }
    Node<T> *slow = first;
    Node<T> *fast = first->next;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    middle = slow->next;
    slow->next = nullptr;
    begin = first;
}

template<class T>
bool binarySearch(Node<T> *first, T key) {
    if (first == nullptr) {
        return false;
    }

    Node<T> *begin = nullptr;
    Node<T> *middle = nullptr;
    getMiddle(first, begin, middle);

    if (middle != nullptr) {
        if (middle->data == key) {
            return true;
        }
        if (middle->data > key) {
            return binarySearch(begin, key);
        } else {
            return binarySearch(middle, key);
        }
    }

}

#pragma endregion

#pragma region Task05

template<class T>
void sortOddEvenIndex(Node<T> *&first) {
    if (!first) {
        return;
    }
    Node<T> *odds = first;
    Node<T> *evens = first->next;
    odds->next = nullptr;

    Node<T> *prev = evens;
    Node<T> *oddCurr = odds;
    while (prev && prev->next) {
        oddCurr->next = prev->next;
        prev->next = prev->next->next;
        prev = prev->next;
        oddCurr = oddCurr->next;
        oddCurr->next = nullptr;
    }
    oddCurr->next = evens;
    first = odds;
}

#pragma endregion

#pragma region Task06


#pragma endregion

template<class T>
void printList(Node<T> *first) {
    while (first != nullptr) {
        std::cout << first->data << " -> ";
        first = first->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
//    Node<int> *first = new Node<int>{-5, new Node<int>{12, new Node<int>{-10, new Node<int>{3, nullptr}}}};
//    absoluteSort(first);
//    sortAbsoluteSorted(first);

    Node<int> *first = new Node<int>{1,
                                     new Node<int>{2,
                                                   new Node<int>{3,
                                                                 new Node<int>{4,
                                                                               new Node<int>{5, nullptr}}}}};

//    std::cout << (isPalindrom(first) ? "YES" : "NO") << std::endl;

    sortOddEvenIndex(first);
    printList(first);

}