//
// Created by Sybatron on 2/25/2024.
//
#include <iostream>

struct Point {
    double x;
    double y;
};

void sortPoints(Point *&points, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (points[j].x > points[j + 1].x ||
                points[j].x == points[j + 1].x && points[j].y > points[j + 1].y) {
                Point temp = {points[j].x, points[j].y};
                points[j].x = points[j + 1].x;
                points[j].y = points[j + 1].y;
                points[j + 1].x = temp.x;
                points[j + 1].y = temp.y;
                continue;
            }
        }
    }
}

int main() {
    Point *points = new Point[10]{{3,  4},
                                  {4,  7},
                                  {1,  2},
                                  {5,  6},
                                  {7,  1},
                                  {-3, 5},
                                  {-3, 10},
                                  {3,  -10},
                                  {1,  4},
                                  {1,  -3}};
    sortPoints(points, 10);
    for (int i = 0; i < 10; ++i) {
        std::cout << "Point[" << i << "]{"
                  << "X: " << points[i].x << ", "
                  << "Y: " << points[i].y << "}" << std::endl;
    }
    delete[]points;
}