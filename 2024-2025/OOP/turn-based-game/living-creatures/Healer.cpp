//
// Created by Sybatron on 6/20/2025.
//

#include "Healer.h"

Healer::Healer()
        : Unit("Лечител", 290, 200, Armor(ArmorType::Unarmored, 0), 2, 150) {}

bool Healer::heal(Unit &target) {
    if (mana >= 100 && target.isAlive()) {
        mana -= 100;
        target.receiveDamage(-100); // отрицателна щета = лечение
        return true;
    }
    return false;
}

//bool Healer::canCast() const {
//    return mana >= 100;
//}