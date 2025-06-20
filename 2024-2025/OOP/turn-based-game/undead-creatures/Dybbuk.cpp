//
// Created by Sybatron on 6/20/2025.
//

#include "Dybbuk.h"

Dybbuk::Dybbuk()
        : Zombie() {
    this->name = "Дибук";
    this->mana = 300;
}

void Dybbuk::attack(Unit &target) {
    if (mana >= 150) {
        mana -= 150;
        target.receiveDamage(attackPower);
    }
}

//bool Dybbuk::canCast() const {
//    return mana >= 150;
//}
