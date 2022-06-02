//
// Created by Sybatron on 5/28/2022.
//

#ifndef TICKET_SET_H
#define TICKET_SET_H

#include <iostream>
#include <stdexcept>

class Set {
private:
    int *storage;
    size_t size;
    size_t capacity;
public:
    bool member(int x) {
        for (int i = 0; i < size; ++i) {
            if (x == storage[i]) {
                return true;
            }
        }
        return false;
    };

    int length() {
        return size;
    };

    friend bool operator<(const Set &lvalue, const Set &rvalue) {
        if (lvalue.size > rvalue.size) {
            return false;
        }
        size_t startIndex;
        for (int i = 0; i < rvalue.size; ++i) {
            if (lvalue.storage[0] == rvalue.storage[i]) {
                startIndex = i;
                if (startIndex + rvalue.size - 1) {
                    return false;
                }
                break;
            }
        }

        for (int i = 0; i < rvalue.size; ++i) {

        }
    };

    int operator[](size_t indx) {
        if (indx >= size) {
            throw std::invalid_argument("Invalid index");
        }
        return storage[indx];
    };
};

#endif //TICKET_SET_H
