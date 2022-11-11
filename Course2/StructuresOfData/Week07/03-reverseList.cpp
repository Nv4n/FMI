#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"

template<typename T>
struct box {
    T data;
    box *next;
};

/*Поставете тук реализация на функцията reverseList*/
template<class T>
box<T> *copyList(box<T> *first) {
    if (!first) {
        return nullptr;
    }
    box<T> *res = new box<T>{first->data, nullptr};
    box<T> *curr = res;
    box<T> *fcurr = first->next;

    while (fcurr) {
        curr->next = new box<T>{fcurr->data, nullptr};
        curr = curr->next;
        fcurr = fcurr->next;
    }

    return res;
}

template<class T>
box<T> *reverse(box<T> *&first, unsigned int n) {
    box<T> *curr = first;
    box<T> *next = nullptr;
    box<T> *prev = nullptr;
    int i = 0;
    while (i < n && curr) {
        i++;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    box<T> *tmp = prev;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = next;
    return prev;
}

template<class T>
void reverseList(box<T> *&first, unsigned int n) {
    if (!first) {
        return;
    }
    box<T> *hold = copyList(first);
    first = reverse(first, n);
}

TEST_CASE ("Reverse basic")
{
    box<int> *l1 = new box<int>{1,
                                new box<int>{2,
                                             new box<int>{3,
                                                          new box<int>{4,
                                                                       new box<int>{5,
                                                                                    new box<int>{6,
                                                                                                 new box<int>{7,
                                                                                                              new box<int>{
                                                                                                                      8,
                                                                                                                      nullptr}}}}}}}};
    reverseList(l1, 4);
    int expected[] = {4, 3, 2, 1, 5, 6, 7, 8};
    for (int x: expected) {
                CHECK(x == l1->data);
        l1 = l1->next;
    }

}

//TEST_CASE ("Reverse edges")
//{
//    box<int> *l1 = new box<int>{1, new box<int>{2, nullptr}};
//    reverseList(l1, 10);
//            CHECK(l1->data == 2);
//            CHECK(l1->next->data == 1);
//
//            CHECK_NOTHROW(reverseList(l1->next, 10));
//            CHECK_NOTHROW(reverseList<int>(nullptr, 10));
//}

int main() {

    doctest::Context().run();

    return 0;
}

