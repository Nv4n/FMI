//
// Created by Sybatron on 5/26/2022.
//

#ifndef VECTOR_ORDER_H
#define VECTOR_ORDER_H

#include <cstring>

enum Meal {
    UNKNOWN = -1,
    CHICKEN,
    PORK,
    SALAD,
    DESSERT
};

class Order {
private:
    static size_t Id;
    size_t orderId{};
    Meal meal{};
    double weight{};
    char *address{};
public:
    Order() : orderId(Id++), meal(Meal::UNKNOWN), weight(0), address(std::strcpy(new char[1], "")) {};
    Order(const Order& other):orderId(other.orderId),meal(other.meal),weight(other.weight),address(std::strcpy(new char[std::strlen(other.address)],other.address)){};
    Order& operator=(const Order& other)=delete;
    Order(Meal meal,double weight, const char* address):orderId(Id++),meal(meal),weight(weight),address(stpcpy(new char[std::strlen(address)],address)){};
    ~Order() { delete[] address;};
};

size_t Order::Id = 0;
#endif //VECTOR_ORDER_H
