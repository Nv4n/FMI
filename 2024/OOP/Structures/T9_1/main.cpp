#include "Time.h"

//
// Created by Sybatron on 3/30/2024.
//
#include <iostream>

int main() {
    Time t1;
    t1.mins(23);
    t1.hoursMethod(4);
    std::cout << t1.totalMins() << std::endl;
    Time t2;
    t2.mins(50);
    t2.hoursMethod(10);
    Time t3 = t1 + t2;
    std::cout << std::boolalpha << (t1 < t3) << std::endl;
    std::cout << std::boolalpha << (t1 == t3) << std::endl;
    std::cout << t3.hoursMethod() << ":" << t3.mins() << std::endl;
    std::cout << (t3 * 5).totalMins() << std::endl;
}