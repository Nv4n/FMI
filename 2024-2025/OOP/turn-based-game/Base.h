//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_BASE_H
#define TURNBASEDGAME_BASE_H


#pragma once

#include <vector>
#include <iostream>
#include "Unit.h"
#include "BaseImports.h"


enum class UnitEnum {
    // Living
    INFANTRYMAN, ARCHER, KNIGHT, HEALER, WIZARD, UNDEAD_HUNTER, BLADE_DANCER, PALADIN,
    // Undead
    SKELETON, GHOUL, NECROMANCER, ZOMBIE, DYBBUK, REVENANT, GHOST, LICH, DREADLORD, DEATH_KNIGHT
};

class Base {
private:
    Faction faction;
    int gold;
    std::size_t unitLimit;
    std::vector<Unit *> units;
    std::vector<Unit *> commanders;

public:
    Base(Faction faction, int initialGold, std::size_t unitLimit);

    ~Base();

    bool createUnit(Unit *newUnit);

    bool addCommander(Unit *commander);

    std::vector<Unit *> getAliveUnits() const;

    std::vector<Unit *> getAliveCommanders() const;

    void restoreOtherSide(Base &other);

    void save(std::ostream &out) const;

    void load(std::istream &in);

    int getGold() const;

    void addGold(int amount);

    size_t getRemainingUnitSlots() const;

    Unit *createUnitFromName(UnitEnum type);

};


#endif //TURNBASEDGAME_BASE_H
