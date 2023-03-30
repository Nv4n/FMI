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

template<class T>
Node<T> *copyList(Node<T> *first) {
    if (first == nullptr) {
        return nullptr;
    }

    Node<T> *holder = new Node<T>{first->data, nullptr};
    first = first->next;

    Node<T> *curr = holder;
    while (first != nullptr) {
        curr->next = new Node<T>{first->data, nullptr};
        curr = curr->next;
        first = first->next;
    }
    return holder;
}

template<class T>
void printList(Node<T> *first) {
    while (first != nullptr) {
        std::cout << first->data << " -> ";
        first = first->next;
    }
    std::cout << "nullptr" << std::endl;
}

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
    Node<T> *reversed = copyList(first);
    reverseList<T>(reversed);
    return areEqualLists(first, reversed);
}

#pragma endregion

#pragma region Task03

bool hasCycle(Node<int> *first) {
    if (!first) {
        return false;
    }

    Node<int> *slow = first;
    Node<int> *fast = first->next;

    while (fast && fast->next) {
        if (slow == fast) {
            return true;
        }

        fast = fast->next;
        if (fast == slow) {
            return true;
        }
        fast = fast->next;
        slow = slow->next;


        if (slow == nullptr) {
            return false;
        }
    }

    return fast == slow;
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

Node<int> *getFirstN(size_t n) {
    if (n <= 0) {
        return nullptr;
    }

    Node<int> *sequence = new Node<int>{1, nullptr};
    Node<int> *curr = sequence;
    for (int i = 1, count = 0, num = 2; i < n; ++i, ++count) {
        if (count == num) {
            count = 0;
            ++num;
        }
        curr->next = new Node<int>{num, nullptr};
        curr = curr->next;
    }

    return sequence;
}

#pragma endregion

#pragma region Task07

Node<int> *mergeSort(Node<int> *&a, Node<int> *&b) {
    if (!a) {
        return b;
    }
    if (!b) {
        return a;
    }

    Node<int> *res = nullptr;
    while (!res) {
        if (a->data < b->data) {
            res = new Node<int>{a->data, nullptr};
            res->next = mergeSort(a->next, b);
        } else {
            res = new Node<int>{b->data, nullptr};
            res->next = mergeSort(a, b->next);
        }
    }

    return res;
}

void split(Node<int> *first, Node<int> *&left, Node<int> *&right) {
    if (first == nullptr) {
        return;
    }

    Node<int> *curr = first;
    while (curr && curr->next) {
        if (curr->data > curr->next->data) {
            break;
        }
        curr = curr->next;
    }

    if (curr) {
        right = curr->next;
        curr->next = nullptr;
    }
    left = first;
}

void sortSorted(Node<int> *&first) {
    Node<int> *left = nullptr;
    Node<int> *right = nullptr;
    split(first, left, right);
    first = mergeSort(left, right);
}

#pragma endregion

void swap(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;
}

void bubbleSortList(Node<int> *first) {
    if (!first) {
        return;
    }

    Node<int> *fst = first;
    Node<int> *snd = first->next;
    Node<int> *end = nullptr;
    while (end != first) {
        while (snd != end && snd) {
            if (fst->data > snd->data) {
                swap(fst->data, snd->data);
            }

            snd = snd->next;
            fst = fst->next;
        }
        end = fst;
        fst = first;
        snd = first->next;
    }
}

int main() {
    Node<int> *first = new Node<int>{1, new Node<int>{2, nullptr}};
    Node<int> *repeat = new Node<int>{3, new Node<int>{4, nullptr}};
    first->next->next = repeat;
    repeat->next->next = new Node<int>{5, repeat};

    std::cout << (hasCycle(first) ? "YES" : "NO") << std::endl;
}