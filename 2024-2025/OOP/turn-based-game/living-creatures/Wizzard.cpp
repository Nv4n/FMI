//
// Created by Sybatron on 6/20/2025.
//

#include "Wizzard.h"

Wizard::Wizard()
        : Unit("Магьосник", 325, 200, Armor(ArmorType::Leather, 3), 10, 250) {}

void Wizard::attack(Unit &target) {
    if (mana >= 50) {
        mana -= 50;
        target.receiveDamage(attackPower);
    }
}

//bool Wizard::canCast() const {
//    return mana >= 50;
//}