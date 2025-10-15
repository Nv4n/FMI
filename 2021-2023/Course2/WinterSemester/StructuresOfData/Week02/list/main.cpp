//
// Created by Sybatron on 10/13/2022.
//

#include <iostream>
#include "LList.h"


int main() {
    LList<int> list;

    list.pushFront(0);
    list.pushFront(1);
    list.pushFront(2);

    list.print();

    std::cout << list.size() << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << i << ": " << list[i] << std::endl;
    }
    return 0;
}
