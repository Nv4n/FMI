//
// Created by Sybatron on 6/9/2025.
//

#include "Unit.h"

Unit::Unit(std::string name, int hp, int mp, const Armor &a, int atk, int cost)
        : name(std::move(name)), health(hp), mana(mp), armor(a), attackPower(atk), goldCost(cost) {
    maxHealth = health;
    maxMana = mana;
    faction = Faction::UNKNOWN;
}

void Unit::attack(Unit &target) {
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

Armor Unit::getArmor() const {
    return armor;
}

int Unit::getGoldCost() const {
    return goldCost;
}

Faction Unit::getFaction() const {
    return faction;
}

void Unit::restoreMana() {
    mana += 75;
}

void Unit::restoreHealth() {
    health += 100;
}

bool Unit::isCommanderUnit() const {
    return false;
}
