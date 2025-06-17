//
// Created by Sybatron on 6/9/2025.
//

#ifndef TURNBASEDGAME_LEADERS_H
#define TURNBASEDGAME_LEADERS_H


/**
 * @file main.cpp
 * @brief Симулира бойни единици и главнокомандващи в игра с живи и немъртви фракции.
 */

#include <iostream>
#include <fstream>
#include <new>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include "Unit.h"
#include "Armor.h"

/**
 * @class Lich
 * @brief Главнокомандващ на немъртвите, способен да въздига мъртъвци.
 */
class Lich : public Unit {
public:
    Lich() : Unit("Lich", 1500, 1000, ArmorType::Heavy, 15, 100, 0) {}

    /**
     * @brief Въздига мъртви единици.
     * @param deadAlliesThisTurn Брой паднали съюзници през този ход.
     * @param alreadyRaisedThisTurn Дали вече е въздигано този ход.
     * @return true ако заклинанието е успешно.
     */
    bool raiseDead(int deadAlliesThisTurn, bool alreadyRaisedThisTurn);
};

bool Lich::raiseDead(int deadAlliesThisTurn, bool alreadyRaisedThisTurn) {
    if (!alreadyRaisedThisTurn && deadAlliesThisTurn > 0 && mana >= 750) {
        mana -= 750;
        std::cout << "Lich raises dead units!\n";
        return true;
    }
    return false;
}

/**
 * @class Dreadlord
 * @brief Главнокомандващ на немъртвите, способен да призовава гулове и некроманти.
 */
class Dreadlord : public Unit {
public:
    Dreadlord() : Unit("Dreadlord", 3000, 2000, ArmorType::Heavy, 20, 200, 0) {}

    /**
     * @brief Призовава немъртви създания.
     * @param mana Референция към текущата манна на владетеля.
     * @return Вектор с призовани единици.
     */
    std::vector<Unit*> summon(int& mana);
};

std::vector<Unit*> Dreadlord::summon(int& mana) {
    std::vector<Unit*> summoned;
    if (mana >= 400) {
        mana -= 400;
        summoned.push_back(new Unit("Necromancer", 300, 200, ArmorType::Unarmored, 0, 4, 400));
    }
    if (mana >= 500) {
        mana -= 500;
        summoned.push_back(new Unit("Ghoul", 400, 0, ArmorType::Heavy, 6, 12, 250));
    }
    return summoned;
}

/**
 * @class DeathKnight
 * @brief Немъртъв рицар, който може да се създаде след смъртта на жив рицар.
 */
class DeathKnight : public Unit {
public:
    DeathKnight() : Unit("Death Knight", 2500, 1000, ArmorType::Heavy, 15, 150, 0) {}

    /**
     * @brief Лекува друга немъртва единица.
     * @param target Единицата, която ще бъде излекувана.
     */
    void healUndead(Unit& target);

    /**
     * @brief Опит за създаване на Death Knight след смъртта на жив рицар.
     * @return true с вероятност 25%.
     */
    static bool tryCreateFromDeadKnight();
};

void DeathKnight::healUndead(Unit& target) {
    if (mana >= 350) {
        mana -= 350;
        target = Unit(target.getName(), target.getHealth() + 100, target.getMana(), ArmorType::Unarmored, 0, target.getAttackPower(), 0);
        std::cout << "Death Knight heals undead unit.\n";
    }
}

bool DeathKnight::tryCreateFromDeadKnight() {
    return (std::rand() % 100) < 25;
}

/**
 * @class UndeadHunter
 * @brief Главнокомандващ при хората, способен да унищожава немъртви командири.
 */
class UndeadHunter : public Unit {
public:
    UndeadHunter() : Unit("Undead Hunter", 2000, 1500, ArmorType::Heavy, 17, 75, 0) {}

    /**
     * @brief Унищожава немъртъв главнокомандващ.
     * @param target Целта.
     * @return true ако е успешно.
     */
    bool destroyUndeadCommander(Unit& target);
};

bool UndeadHunter::destroyUndeadCommander(Unit& target) {
    if (mana >= 1000) {
        mana -= 1000;
        std::cout << "Undead commander destroyed by Undead Hunter!\n";
        return true;
    }
    return false;
}

/**
 * @class BladeDancer
 * @brief Главнокомандващ при хората със силна атака.
 */
class BladeDancer : public Unit {
public:
    BladeDancer() : Unit("Blade Dancer", 4000, 0, ArmorType::Medium, 25, 300, 0) {}
};

/**
 * @class Paladin
 * @brief Главнокомандващ при хората, способен да лекува и възкресява.
 */
class Paladin : public Unit {
public:
    Paladin() : Unit("Paladin", 5000, 3000, ArmorType::Heavy, 20, 250, 0) {}

    /**
     * @brief Лекува съюзна единица.
     * @param ally Съюзникът, който ще бъде излекуван.
     */
    void healAlly(Unit& ally);

    /// @return Тип броня на паладина.
    ArmorType getArmorType() const;
};

void Paladin::healAlly(Unit& ally) {
    if (mana >= 500) {
        mana -= 500;
        ally = Unit(ally.getName(), ally.getHealth() + 100, ally.getMana(), ally.getArmorType(), 0, ally.getAttackPower(), 0);
        std::cout << "Paladin heals ally.\n";
    }
}

/**
 * @brief Главна функция.
 * @return 0 при успешно изпълнение.
 */
int main() {
    Lich lich;
    Dreadlord dreadlord;
    DeathKnight dk;
    UndeadHunter hunter;
    BladeDancer dancer;
    Paladin paladin;

    lich.raiseDead(2, false);
    auto summoned = dreadlord.summon(dreadlord.mana);
    for (auto* u : summoned) delete u;

    if (DeathKnight::tryCreateFromDeadKnight()) {
        std::cout << "A Death Knight has risen!\n";
    }

    hunter.destroyUndeadCommander(lich);
    paladin.healAlly(dancer);

    return 0;
}


#endif //TURNBASEDGAME_LEADERS_H
