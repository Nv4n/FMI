//
// Created by Sybatron on 6/9/2025.
//

#include "UndeadUnits.h"
#include "UndeadUnits.h"

Skeleton::Skeleton()
        : Unit("Скелет", 500, 0, Armor(ArmorType::Medium, 8), 5, 100) {}

Ghoul::Ghoul()
        : Unit("Гул", 400, 0, Armor(ArmorType::Heavy, 6), 12, 250) {}

Necromancer::Necromancer()
        : Unit("Некромант", 300, 200, Armor(ArmorType::Unarmored, 0), 4, 400) {}

std::vector<std::unique_ptr<Skeleton>> Necromancer::summonSkeletons(const std::vector<Unit*>& deadUnits) {
    std::vector<std::unique_ptr<Skeleton>> skeletons;
    if (mana >= 150 && deadUnits.size() >= 3) {
        mana -= 150;
        for (int i = 0; i < 3; ++i) {
            skeletons.emplace_back(std::make_unique<Skeleton>());
        }
    }
    return skeletons;
}

bool Necromancer::canCast() const {
    return mana >= 150;
}

Zombie::Zombie()
        : Unit("Зомби", 250, 0, Armor(ArmorType::Unarmored, 0), 15, 300) {}

Dybbuk::Dybbuk()
        : Zombie() {
    this->name = "Дибук";
    this->mana = 300;
}

void Dybbuk::attack(Unit& target) {
    if (mana >= 150) {
        mana -= 150;
        target.receiveDamage(attackPower);
    }
}

bool Dybbuk::canCast() const {
    return mana >= 150;
}

Revenant::Revenant()
        : Zombie() {
    this->name = "Ревенант";
    this->health = 600;
}

Ghost::Ghost()
        : Unit("Призрак", 0, 0, Armor(ArmorType::Unarmored, 0), 0, 500) {}

bool Ghost::sacrificeToHeal(Unit& target) {
    if (!isAlive()) return false;

    // Призрак се унищожава, целта получава 250 здраве
    target.receiveDamage(-250);
    this->health = 0;
    return true;
}
