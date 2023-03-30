#define DOCTEST_CONFIG_IMPLEMENT

#include "../doctest.h"
#include "../treeutils.cpp"

#include <vector>

/*
======================
Решение на задачата:
======================
*/
void getLevelSizes(box<int> *t, int level, std::vector<int> &v) {
    if (!t) {
        return;
    }
    if (!v.at(level)) {
        v.push_back(0);
    }
    v[level]++;
    getLevelSizes(t->left, level + 1, v);
    getLevelSizes(t->right, level + 1, v);
}


std::vector<int> levelsGrowing(box<int> *t) {
    std::vector<int> res;
    if (!t) {
        return res;
    }
    std::vector<int> sizes;
    getLevelSizes(t, 0, sizes);
    int prev = 1;
    std::vector<int> levels;
    levels.push_back(0);
    for (int i = 1; i < sizes.size(); ++i) {
        if (sizes[i] > sizes[i - 1]) {
            levels.push_back(i);
        }
    }

    return res;
}

/*
======================
Тестове
======================
*/

TEST_CASE("Test Edges")
{
    box<int> *t = nullptr;

    CHECK(levelsGrowing(t).size() == 0);

    setAt(t, "", 10);

    CHECK(levelsGrowing(t).size() == 1);

}


TEST_CASE("Test Levels Growing")
{
    box<int> *t = nullptr;

    setAt(t, "", 10);
    setAt(t, "L", 20);
    setAt(t, "R", 30);
    setAt(t, "RL", 40);
    setAt(t, "RR", 50);
    setAt(t, "RRL", 60);
    setAt(t, "RLL", 70);
    setAt(t, "RRR", 80);

    std::vector<int> expected = {10, 30, 20, 80, 60, 70};
    CHECK(expected == levelsGrowing(t));

}


int main() {
    doctest::Context().run();
}