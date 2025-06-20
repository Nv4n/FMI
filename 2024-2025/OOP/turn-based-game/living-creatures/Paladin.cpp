//
// Created by Sybatron on 6/20/2025.
//

#include "Paladin.h"

Paladin::Paladin() : Unit("Paladin", 5000, 3000, Armor(ArmorType::Heavy, 20), 250, 0) {}

void Paladin::healAlly(Unit &ally) {
    if (mana >= 500) {
        mana -= 500;
        ally.receiveDamage(-100);
        std::cout << "Paladin heals ally.\n";
    }
}

bool Paladin::isCommanderUnit() const {
    return true;
}
