//
// Created by Sybatron on 6/9/2025.
//

#include "LivingUnits.h"
#include "LivingUnits.h"

Infantryman::Infantryman()
        : Unit("Пехотинец", 420, 0, Armor(ArmorType::Medium, 8), 7, 250) {}

Archer::Archer()
        : Unit("Стрелец", 535, 0, Armor(ArmorType::Medium, 3), 10, 300) {}

Knight::Knight()
        : Unit("Рицар", 835, 0, Armor(ArmorType::Heavy, 10), 45, 700) {}

Healer::Healer()
        : Unit("Лечител", 290, 200, Armor(ArmorType::Unarmored, 0), 2, 150) {}

bool Healer::heal(Unit& target) {
    if (mana >= 100 && target.isAlive()) {
        mana -= 100;
        target.receiveDamage(-100); // отрицателна щета = лечение
        return true;
    }
    return false;
}

bool Healer::canCast() const {
    return mana >= 100;
}

Wizard::Wizard()
        : Unit("Магьосник", 325, 200, Armor(ArmorType::Leather, 3), 10, 250) {}

void Wizard::attack(Unit& target) {
    if (mana >= 50) {
        mana -= 50;
        target.receiveDamage(attackPower);
    }
}

bool Wizard::canCast() const {
    return mana >= 50;
}
