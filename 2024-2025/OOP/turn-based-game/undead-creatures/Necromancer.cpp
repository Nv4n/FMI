//
// Created by Sybatron on 6/20/2025.
//

#include "Necromancer.h"

Necromancer::Necromancer()
        : Unit("Некромант", 300, 200, Armor(ArmorType::Unarmored, 0), 4, 400) {}

std::vector<Skeleton *> Necromancer::summonSkeletons(const std::vector<Unit *> &deadUnits) {
    std::vector<Skeleton *> skeletons;
    if (mana >= 150 && deadUnits.size() >= 3) {
        mana -= 150;
        for (int i = 0; i < 3; ++i) {
            skeletons.emplace_back(new Skeleton());
        }
    }
    return skeletons;
}
//
//bool Necromancer::canCast() const {
//    return mana >= 150;
//}