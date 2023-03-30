//
// Created by Sybatron on 10/3/2022.
//

#ifndef TASK02POLYMORPHISM_ARENA_H
#define TASK02POLYMORPHISM_ARENA_H
#define pragma once

#include "Hero.h"
#include <iostream>

class Arena {
private:
    Hero **heroes;
    size_t size;
    size_t capacity = 8;
public:
    Arena() {
        size = 0;
        heroes = new Hero *[capacity];
    }

    Arena(const Arena &other) {
        copy(other);
    }

    Arena &operator=(const Arena &other) {
        if (this != &other) {
            destroy();
            copy(other);
        }
        return *this;
    }

    ~Arena() {
        destroy();
    }

    void fight() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == j) continue;
                heroes[i]->attack(heroes[j]);
            }
        }
        for (int i = 0; i < size; ++i) {
            heroes[i]->getInfo();
        }
    }

private:
    void copy(const Arena &other) {
        size = other.size;
        heroes = new Hero *[capacity];
        for (int i = 0; i < size; ++i) {
            heroes[i] = other.heroes[i]->clone();
        }
    }

    void destroy() {
        for (int i = 0; i < size; ++i) {
            delete heroes[i];
        }
        delete[] heroes;
    }
};


#endif //TASK02POLYMORPHISM_ARENA_H
