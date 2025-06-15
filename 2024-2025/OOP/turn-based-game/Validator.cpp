//
// Created by Sybatron on 6/9/2025.
//

#include "Validator.h"

#include <iostream>

//Unit::Unit(std::string n, int hp, int mp, ArmorType at, int as, int ap, bool commander, Faction f)
//        : name(n), health(hp), mana(mp), armorType(at), armorStrength(as),
//          attackPower(ap), isCommander(commander), faction(f) {}
//
//std::string Unit::getName() const { return name; }
//int Unit::getHealth() const { return health; }
//void Unit::setHealth(int hp) { health = hp; }
//int Unit::getMana() const { return mana; }
//void Unit::setMana(int mp) { mana = mp; }
//ArmorType Unit::getArmorType() const { return armorType; }
//int Unit::getArmorStrength() const { return armorStrength; }
//void Unit::decreaseArmorStrength() { if (armorStrength > 0) armorStrength--; }
//int Unit::getAttackPower() const { return attackPower; }
//bool Unit::isCommanderUnit() const { return isCommander; }
//Unit::Faction Unit::getFaction() const { return faction; }

//void Unit::receiveDamage(int damage) {
//    int reduction = 0;
//    switch (armorType) {
//        case ArmorType::Unarmored: reduction = 0; break;
//        case ArmorType::Leather: reduction = damage / 4; break;    // 25%
//        case ArmorType::Medium: reduction = damage / 2; break;     // 50%
//        case ArmorType::Heavy: reduction = (damage * 3) / 4; break; // 75%
//    }
//
//    if (armorStrength > 0) {
//        damage -= reduction;
//        decreaseArmorStrength();
//    }
//
//    if (damage < 0) damage = 0;
//
//    health -= damage;
//    if (health < 0) health = 0;
//}
//
//void Unit::restoreHealth(int amount) {
//    health += amount;
//    // Може да добавиш максимален лимит, ако е необходимо
//}
//
//void Unit::restoreMana(int amount) {
//    mana += amount;
//    // Може да добавиш максимален лимит, ако е необходимо
//}

Base::Base(int g, int limit, Faction f)
        : gold(g), unitLimit(limit), currentUnits(0), faction(f) {}

bool Base::canCreateUnit(int cost) const {
    return gold >= cost && currentUnits < unitLimit;
}

bool Base::createUnit(int cost) {
    if (!canCreateUnit(cost)) return false;
    gold -= cost;
    currentUnits++;
    return true;
}

int Base::getGold() const { return gold; }
int Base::getUnitLimit() const { return unitLimit; }
int Base::getCurrentUnits() const { return currentUnits; }
Faction Base::getFaction() const { return faction; }

Validator::Validator(Base& lb, Base& ub) : livingBase(lb), undeadBase(ub) {}

// Здравето може да се възстановява само от лечители или командира на живите за живите единици
// и само от некроманти или командира на немъртвите за немъртвите
void Validator::validateHealthRestoration(const std::vector<Unit*>& allUnits) {
    for (Unit* u : allUnits) {
        if (u->getHealth() <= 0) continue;

        if (u->getFaction() == Unit::Faction::Living) {
            // Провери дали някой жив лечител или командир на живите е дал живот
            // Тук примерна логика — да се добави реална проверка за лекуване
            // TODO: Имплементирай според играта
        } else {
            // Немъртви: само некроманти или командири
            // TODO: Имплементирай според играта
        }
    }
}

// След края на хода на една фракция се увеличава 100 здраве и 75 мана на другата
void Validator::endTurnHealthAndManaBoost(Faction turnFaction, std::vector<Unit*>& allUnits) {
    Faction otherFaction = (turnFaction == Faction::Living) ? Faction::Undead : Faction::Living;

    for (Unit* u : allUnits) {
        if (u->getFaction() == otherFaction && u->getHealth() > 0) {
            u->restoreHealth(100);
            u->restoreMana(75);
        }
    }
}

void Validator::validateArmorUsage(Unit& target, int incomingDamage) {
    target.receiveDamage(incomingDamage);
}

void Validator::validateUnitCreation(Base& base, int cost) {
    if (!base.createUnit(cost)) {
        throw std::runtime_error("Cannot create unit: insufficient gold or unit limit reached.");
    }
}
