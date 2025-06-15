//
// Created by Sybatron on 6/9/2025.
//

#include "Unit.h"
#include "Unit.h"
#include <algorithm>

Unit::Unit(std::string name, int hp, int mp, const Armor& a, int atk, int cost)
        : name(n), health(hp), mana(mp), armorType(at), armorStrength(as), attackPower(ap), goldCost(cost) {}

        : name(name), health(hp), maxHealth(hp), mana(mp), maxMana(mp), armor(a), attackPower(atk), goldCost(cost) {}

void Unit::attack(Unit& target) {
    target.receiveDamage(attackPower);
}

void Unit::receiveDamage(int dmg) {
    int reduced = armor.absorb(dmg);
    health = std::max(0, health - reduced);
}

bool Unit::isAlive() const { return health > 0; }
std::string Unit::getName() const { return name; }
int Unit::getHealth() const { return health; }
int Unit::getMana() const { return mana; }
int Unit::getCost() const { return goldCost; }
Armor Unit::getArmor() const { return armor; }
