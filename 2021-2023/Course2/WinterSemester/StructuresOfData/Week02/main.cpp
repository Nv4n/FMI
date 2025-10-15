//
// Created by Sybatron on 10/10/2022.
//
#include <iostream>
#include "SLL.h"

int main() {
    SLL<int> list;
    list.pushFront(12);
    list.pushFront(13);
    list.pushFront(14);
    list.pushFront(5);
    list.print();

    list.reverse();
    list.print();
}