//
// Created by Sybatron on 6/9/2025.
//

#ifndef TURNBASEDGAME_UNIT_H
#define TURNBASEDGAME_UNIT_H
#pragma once

#include <string>
#include <iostream>
#include "Armor.h"


enum class Faction {
    Living,
    Undead,
    UNKNOWN
};

/**
 * @class Unit
 * @brief Базов клас за всички бойни единици в играта.
 */
class Unit {
protected:
    int health; ///< Здраве
    int maxHealth;
    int mana; ///< Манна
    int maxMana;
    Armor armor;  ///< Тип броня
    int attackPower; ///< Атака
    int goldCost; ///< Цена в злато
    std::string name;   ///< Име на единицата
    Faction faction;


public:
/**
* @brief Конструктор на Unit.
*/
    Unit(std::string name, int hp, int mp, const Armor &armor, int atk, int cost);

    virtual ~Unit() = default;


    /**
     * @brief Извършва атака към друга единица.
     */
    virtual void attack(Unit &target);

    /**
     * @brief Получава щети, отчитайки бронята.
     */
    virtual void receiveDamage(int dmg);

    bool isCommanderUnit() const;

    Faction getFaction() const;

    /**
     * @brief Проверява дали единицата е жива.
     */
    bool isAlive() const;

    std::string getName() const;

    int getHealth() const;

    int getMana() const;

    Armor getArmor() const;

    int getGoldCost() const;
};


#endif //TURNBASEDGAME_UNIT_H
