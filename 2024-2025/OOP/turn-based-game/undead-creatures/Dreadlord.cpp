//
// Created by Sybatron on 6/20/2025.
//

#include "Dreadlord.h"
#include "Necromancer.h"
#include "Ghoul.h"

Dreadlord::Dreadlord() : Unit("Dreadlord", 3000, 2000, Armor(ArmorType::Heavy, 20), 200, 0) {}

std::vector<Unit *> Dreadlord::summon(int &mana) {
    std::vector<Unit *> summoned;
    if (mana >= 400) {
        mana -= 400;
        summoned.push_back(new Necromancer);
    }
    if (mana >= 500) {
        mana -= 500;
        summoned.push_back(new Ghoul());
    }
    return summoned;
}
