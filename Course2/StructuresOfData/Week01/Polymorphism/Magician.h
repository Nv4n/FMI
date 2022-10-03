//
// Created by Sybatron on 10/3/2022.
//

#ifndef TASK02POLYMORPHISM_MAGICIAN_H
#define TASK02POLYMORPHISM_MAGICIAN_H
#define pragma once

#include "Hero.h"

class Magician : public Hero {
private:
    int mana;

public:
    Magician() : Hero(), mana(200) {};

    Magician(const Magician &other) : Hero(other), mana(other.mana) {};

    Magician &operator=(const Magician &other) {
        if (this != &other) {
            Hero::operator=(other);
            mana = other.mana;
        }

        return *this;
    }

    Hero *clone() const override {
        return new Magician(*this);
    }

    int getMana() const {
        return mana;
    }

    virtual void getInfo() override {
        Hero::getInfo();
        std::cout << "Mana: " << mana << std::endl;
    };

    virtual void attack(Hero *enemy) override {
        enemy->setHealth(enemy->getHealth() - mana);
        mana -= 20;
    };
};


#endif //TASK02POLYMORPHISM_MAGICIAN_H
