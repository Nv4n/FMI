//
// Created by Sybatron on 6/20/2025.
//

#include "Ghost.h"

Ghost::Ghost()
        : Unit("Призрак", 0, 0, Armor(ArmorType::Unarmored, 0), 0, 500) {}

bool Ghost::sacrificeToHeal(Unit &target) {
    if (!isAlive()) return false;

    // Призрак се унищожава, целта получава 250 здраве
    target.receiveDamage(-250);
    this->health = 0;
    return true;
}
