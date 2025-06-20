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

    Unit *createUnitFromName(UnitEnum type) {
        Unit *unit = nullptr;
        switch (type) {
            // Living
            case UnitEnum::INFANTRYMAN:
                unit = new Infantryman();
                break;
            case UnitEnum::ARCHER:
                unit = new Archer();
                break;
            case UnitEnum::KNIGHT:
                unit = new Knight();
                break;
            case UnitEnum::HEALER:
                unit = new Healer();
                break;
            case UnitEnum::WIZARD:
                unit = new Wizard();
                break;
            case UnitEnum::UNDEAD_HUNTER:
                unit = new UndeadHunter();
                break;
            case UnitEnum::BLADE_DANCER:
                unit = new BladeDancer();
                break;
            case UnitEnum::PALADIN:
                unit = new Paladin();
                break;
                // Undead
            case UnitEnum::SKELETON:
                unit = new Skeleton();
                break;
            case UnitEnum::GHOUL:
                unit = new Ghoul();
                break;
            case UnitEnum::NECROMANCER:
                unit = new Necromancer();
                break;
            case UnitEnum::ZOMBIE:
                unit = new Zombie();
                break;
            case UnitEnum::DYBBUK:
                unit = new Dybbuk();
                break;
            case UnitEnum::REVENANT:
                unit = new Revenant();
                break;
            case UnitEnum::GHOST:
                unit = new Ghost();
                break;
            case UnitEnum::LICH:
                unit = new Lich();
                break;
            case UnitEnum::DREADLORD:
                unit = new Dreadlord();
                break;
            case UnitEnum::DEATH_KNIGHT:
                unit = new DeathKnight();
                break;
        }
        if (unit && createUnit(unit)) return unit;
        delete unit;
        return nullptr;
    }

};


#endif //TURNBASEDGAME_BASE_H
