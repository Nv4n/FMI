#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"

template<typename T>
struct box {
    T data;
    box *next;
};

/*Поставете тук реализация на функцията makeFib*/
template<class T>
void makeFib(box<T> *first) {
    if (!first || !first->next || !first->next->next) {
        return;
    }
    box<T> *prev = first;
    box<T> *next = first->next;
    box<T> *toCheck = first->next->next;

    while (prev->next->next) {
        if (toCheck->data != prev->data + next->data) {
            toCheck = toCheck->next;
            next->next = toCheck;
        } else {
            prev = prev->next;
            next = next->next;
        }
    }
}

TEST_CASE ("makeFib basic")
{
    box<int> *l1 = new box<int>{1,
                                new box<int>{1,
                                             new box<int>{2,
                                                          new box<int>{2,
                                                                       new box<int>{2,
                                                                                    new box<int>{3,
                                                                                                 new box<int>{5,
                                                                                                              new box<int>{
                                                                                                                      9,
                                                                                                                      nullptr}}}}}}}};
    makeFib(l1);
    int expected[] = {1, 1, 2, 3, 5};
    for (int x: expected) {
                CHECK(x == l1->data);
        l1 = l1->next;
    }

}

TEST_CASE ("makeFib edges")
{
    box<int> *l2 = new box<int>{1, nullptr};
            CHECK_NOTHROW(makeFib(l2));
            CHECK(l2->data == 1);

    box<int> *l3 = new box<int>{1, new box<int>{2, nullptr}};
            CHECK_NOTHROW(makeFib(l3));
            CHECK(l3->next->data == 2);

            CHECK_NOTHROW(makeFib<int>(nullptr));
}

int main() {

    doctest::Context().run();

    return 0;
}

