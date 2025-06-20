//
// Created by Sybatron on 6/20/2025.
//

#include "UndeadHunter.h"

UndeadHunter::UndeadHunter()
        : Unit("Undead Hunter", 2000, 1500, Armor(ArmorType::Heavy, 17), 75, 0) {}

bool UndeadHunter::destroyUndeadCommander(Unit &target) {
    if (mana >= 1000) {
        mana -= 1000;
        std::cout << "Undead commander destroyed by Undead Hunter!\n";
        return true;
    }
    return false;
}