//
// Created by Sybatron on 6/9/2025.
//

#include "Validator2.h"
#include <iostream>

Unit::Unit(std::string n, int hp, int mp, ArmorType at, int as, int ap, bool commander, Faction f)
        : name(std::move(n)), health(hp), mana(mp), armorType(at), armorStrength(as),
          attackPower(ap), isCommander(commander), faction(f) {}

std::string Unit::getName() const { return name; }
int Unit::getHealth() const { return health; }
void Unit::setHealth(int hp) { health = hp; }
int Unit::getMana() const { return mana; }
void Unit::setMana(int mp) { mana = mp; }
ArmorType Unit::getArmorType() const { return armorType; }
int Unit::getArmorStrength() const { return armorStrength; }
void Unit::decreaseArmorStrength() { if (armorStrength > 0) armorStrength--; }
int Unit::getAttackPower() const { return attackPower; }
bool Unit::isCommanderUnit() const { return isCommander; }
Unit::Faction Unit::getFaction() const { return faction; }

void Unit::receiveDamage(int damage) {
    int reduction = 0;
    switch (armorType) {
        case ArmorType::Unarmored: reduction = 0; break;
        case ArmorType::Leather: reduction = damage / 4; break;    // 25%
        case ArmorType::Medium: reduction = damage / 2; break;     // 50%
        case ArmorType::Heavy: reduction = (damage * 3) / 4; break; // 75%
    }

    if (armorStrength > 0) {
        damage -= reduction;
        decreaseArmorStrength();
    }

    if (damage < 0) damage = 0;

    health -= damage;
    if (health < 0) health = 0;
}

void Unit::restoreHealth(int amount) {
    health += amount;
    // Максимум здраве може да се ограничи тук, ако е дефиниран
}

void Unit::restoreMana(int amount) {
    mana += amount;
    // Максимум мана може да се ограничи тук, ако е дефиниран
}

Base::Base(int g, int limit, Unit::Faction f)
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
Unit::Faction Base::getFaction() const { return faction; }

Validator::Validator(Base& lb, Base& ub)
        : livingBase(lb), undeadBase(ub) {}

void Validator::validateHealthRestoration(const std::vector<Unit*>& allUnits) {
    // Тук трябва да се имплементира логика за проверка,
    // че само определени единици възстановяват здраве
    // TODO: В зависимост от играта и логиката на лекуване
}

void Validator::endTurnHealthAndManaBoost(Unit::Faction turnFaction, std::vector<Unit*>& allUnits) {
    Unit::Faction otherFaction = (turnFaction == Unit::Faction::Living) ? Unit::Faction::Undead : Unit::Faction::Living;

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
    if (!base.canCreateUnit(cost)) {
        throw std::runtime_error("Не може да се създаде единица: недостатъчно ресурси или лимит достигнат.");
    }
    base.createUnit(cost);
}

void Validator::addCommander(const std::string& commanderName, Unit::Faction faction) {
    auto& map = (faction == Unit::Faction::Living) ? commanderCountsLiving : commanderCountsUndead;
    if (++map[commanderName] > maxCommanderCount) {
        throw std::runtime_error("Превишен е лимитът от 7 главнокомандващи от един вид за тази фракция.");
    }
}

int Validator::getCommanderCount(const std::string& commanderName, Unit::Faction faction) const {
    const auto& map = (faction == Unit::Faction::Living) ? commanderCountsLiving : commanderCountsUndead;
    auto it = map.find(commanderName);
    return (it != map.end()) ? it->second : 0;
}
