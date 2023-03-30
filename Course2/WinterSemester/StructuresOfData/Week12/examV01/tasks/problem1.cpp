#define DOCTEST_CONFIG_IMPLEMENT

#include "../doctest.h"
#include "../treeutils.cpp"

#include <vector>

/*
======================
Решение на задачата:
======================
*/
/*
 * "Разлика на дървета":
 * ако имаме елемент на една и съща позиция в двете дървета търсим наляво и надясно по двете дървета
 * докато второто дърво остане празно, тогава всички останали елементи и сегашния на първото дърво се добавят към резултата
 * на функцията
 *
 * Is tree1 nullptr -> return;
 * Is tree2 nullptr -> tree1->data is outside the difference
 * and all tree1->left datas and tree1->right datas will be outside the difference accordingly
 *  Else
 *  go tree1->left and tree2->left until we reach datas outside the difference
 *  go tree1->right and tree2->right until we reach datas outside the difference
 *
 *  Провери: Ако дърво1 е празно => няма други елементи => върни назад;
 *  Провери: Ако дърво2 е празно => стигнали сме краят на разликата на дървета
 *  => добави сегашен елемент към резултата
 *  => добави всички леви елементи към резултата
 *  => добави всички десни елементи към резултата
 *  Иначе:
 *  => премини наляво на дърво1 и дърво2
 *  => премини надясно на дърво1 и дърво2
 */
void diffHelper(box<int> *t1, box<int> *t2, std::vector<int> &v) {
    if (!t1) {
        return;
    }
    if (!t2) {
        v.push_back(t1->data);
        diffHelper(t1->left, t2, v);
        diffHelper(t1->right, t2, v);
        return;
    }
    diffHelper(t1->left, t2->left, v);
    diffHelper(t1->right, t2->right, v);
}

std::vector<int> diff(box<int> *t1, box<int> *t2) {
    std::vector<int> res;
    diffHelper(t1, t2, res);
    return res;
}

/*
======================
Тестове
======================
*/
TEST_CASE("Test Edges")
{
    box<int> *t1 = nullptr,
            *t2 = nullptr;

    setAt(t2, "", 0);
    setAt(t2, "R", 0);

    CHECK(diff(t1, t2).size() == 0);
    CHECK(set_equals(diff(t2, t1), {0}));

}

TEST_CASE("Test Diff")
{
    box<int> *t1 = nullptr,
            *t2 = nullptr;

    setAt(t1, "", 10);
    setAt(t1, "L", 20);
    setAt(t1, "R", 30);
    setAt(t1, "RL", 40);
    setAt(t1, "RR", 50);
    setAt(t1, "RRL", 60);

    setAt(t2, "", 0);
    setAt(t2, "R", 0);

    CHECK(set_equals(diff(t1, t2), {20, 40, 50, 60}));

}

int main() {
    doctest::Context().run();
}