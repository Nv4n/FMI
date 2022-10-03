//
// Created by Sybatron on 10/3/2022.
//

#ifndef TASK02POLYMORPHISM_WARRIOR_H
#define TASK02POLYMORPHISM_WARRIOR_H
#define pragma once

#include <iostream>
#include "Hero.h"

class Warrior : public Hero {
private:
    int fury;
public:
    Warrior() : Hero(120), fury(0) {
        health = 120;
    };

    Warrior(const Warrior &other) : Hero(other), fury(other.fury) {};

    Warrior &operator=(const Warrior &other) {
        if (this != &other) {
            Hero::operator=(other);
            fury = other.fury;
        }

        return *this;
    }

    Hero *clone() const override {
        return new Warrior(*this);
    }

    int getFury() const {
        return fury;
    }

    void getInfo() override {
        Hero::getInfo();
        std::cout << "Fury: " << fury << std::endl;
    }

    void attack(Hero *enemy) override {
        enemy->setHealth(enemy->getHealth() - (fury + 10));
        fury += 20;
    }
};


#endif //TASK02POLYMORPHISM_WARRIOR_H
