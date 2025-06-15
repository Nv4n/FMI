//
// Created by Sybatron on 6/9/2025.
//

#ifndef TURNBASEDGAME_VALIDATOR_H
#define TURNBASEDGAME_VALIDATOR_H


#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <vector>
#include <string>
#include <stdexcept>
#include "Armor.h"
#include "Unit.h"

class Base {
    int gold;
    int unitLimit;
    int currentUnits;

public:
    Base(int g, int limit, Faction f);

    bool canCreateUnit(int cost) const;
    bool createUnit(int cost);
    int getGold() const;
    int getUnitLimit() const;
    int getCurrentUnits() const;
    Faction getFaction() const;
};

class Validator {
    Base& livingBase;
    Base& undeadBase;

public:
    Validator(Base& lb, Base& ub);

    void validateHealthRestoration(const std::vector<Unit*>& allUnits);

    void endTurnHealthAndManaBoost(Faction turnFaction, std::vector<Unit*>& allUnits);

    void validateArmorUsage(Unit& target, int incomingDamage);

    void validateUnitCreation(Base& base, int cost);

};

#endif // VALIDATOR_H



#endif //TURNBASEDGAME_VALIDATOR_H
