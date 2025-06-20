//
// Created by Sybatron on 6/20/2025.
//

#include "Base.h"

Base::Base(Faction faction, int initialGold, size_t unitLimit)
        : faction(faction), gold(initialGold), unitLimit(unitLimit) {}

Base::~Base() {
    for (Unit *u: units) {
        delete u;
    }
    for (Unit *c: commanders) {
        delete c;
    }
}

bool Base::createUnit(Unit *newUnit) {
    if (units.size() >= unitLimit) {
        return false;
    }
    if (gold < newUnit->getGoldCost()) {
        delete newUnit;
        return false;
    }
    gold -= newUnit->getGoldCost();
    units.push_back(newUnit);
    return true;
}

bool Base::addCommander(Unit *commander) {
    if (!commander->isCommanderUnit()) {
        return false;
    }
    std::size_t count = 0;
    for (Unit *c: commanders) {
        if (c->getName() == commander->getName()) count++;
    }
    if (count >= 7) {
        delete commander;
        return false;
    }
    commanders.push_back(commander);
    return true;
}

std::vector<Unit *> Base::getAliveUnits() const {
    std::vector<Unit *> alive;
    for (Unit *u: units) {
        if (u->isAlive()) {
            alive.push_back(u);
        }
    }
    return alive;
}

std::vector<Unit *> Base::getAliveCommanders() const {
    std::vector<Unit *> alive;
    for (Unit *c: commanders) {
        if (c->isAlive()) {
            alive.push_back(c);
        }
    }
    return alive;
}

void Base::restoreOtherSide(Base &other) {
    for (Unit *u: other.getAliveUnits()) {
        u->restoreHealth();
    }
    for (Unit *c: other.getAliveCommanders()) {
        c->restoreHealth();
    }
    for (Unit *u: other.getAliveUnits()) {
        u->restoreMana();
    }
    for (Unit *c: other.getAliveCommanders()) {
        c->restoreMana();
    }
}

void Base::save(std::ostream &out) const {
    out << gold << ' ' << commanders.size() << '\n';
    for (Unit *c: commanders) {
        out << c->getName() << ' ' << c->getHealth() << ' ' << c->getMana() << '\n';
    }
}

void Base::load(std::istream &in) {
    size_t cmdCount;
    in >> gold >> cmdCount;
    commanders.clear();
    for (size_t i = 0; i < cmdCount; ++i) {
        std::string name;
        int hp, mp;
        in >> name >> hp >> mp;
        // TODO: създай съответен Leader по име
    }
}

int Base::getGold() const {
    return gold;
}

void Base::addGold(int amount) {
    gold += amount;
}

size_t Base::getRemainingUnitSlots() const {
    return unitLimit - units.size();
}

Unit *Base::createUnitFromName(UnitEnum type) {
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
    if (unit && createUnit(unit)) {
        return unit;
    }
    delete unit;
    return nullptr;
}
