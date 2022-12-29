#define DOCTEST_CONFIG_IMPLEMENT

#include "../doctest.h"
#include "../treeutils.cpp"

#include <vector>

/*
======================
Решение на задачата:
======================
*/

void expand(box<int> *t1, box<int> *&t2) {
    if (!t1) {
        return;
    }
    if (!t2) {
        t2 = new box<int>{t1->data};
    }
    expand(t1->left, t2->left);
    expand(t1->right, t2->right);
}

/*
======================
Тестове
======================
*/
TEST_CASE("Test Edges")
{
    box<int> *t1 = nullptr,
            *t2 = nullptr,
            *t3 = nullptr;

    setAt(t1, "", 0);
    setAt(t3, "", 0);

    expand(t2, t1);
    CHECK(tree_equals(t1, t3));

    expand(t1, t2);
    CHECK(tree_equals(t2, t1));

}

TEST_CASE("Test Expand")
{
    box<int> *t1 = nullptr,
            *t2 = nullptr,
            *t3 = nullptr;

    setAt(t1, "", 10);
    setAt(t1, "L", 20);
    setAt(t1, "R", 30);
    setAt(t1, "RL", 40);
    setAt(t1, "RLL", 70);
    setAt(t1, "RR", 50);
    setAt(t1, "RRL", 60);

    setAt(t2, "", 0);
    setAt(t2, "R", 0);
    setAt(t2, "RL", 80);
    setAt(t2, "RLL", 90);
    setAt(t2, "RLR", 95);

    setAt(t3, "", 0);
    setAt(t3, "R", 0);
    setAt(t3, "RL", 80);
    setAt(t3, "RLL", 90);
    setAt(t3, "RLR", 95);
    setAt(t3, "L", 20);
    setAt(t3, "RR", 50);
    setAt(t3, "RRL", 60);

    expand(t1, t2);
    CHECK(tree_equals(t2, t3));

}


int main() {
    doctest::Context().run();
}