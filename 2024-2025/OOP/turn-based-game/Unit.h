//
// Created by Sybatron on 6/9/2025.
//

#ifndef TURNBASEDGAME_UNIT_H
#define TURNBASEDGAME_UNIT_H
#pragma once
#include <string>
#include <iostream>
#include "Armor.h"


enum class Faction { Living, Undead };



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
    int armorStrength; ///< Сила на бронята
    int attackPower; ///< Атака
    int goldCost; ///< Цена в злато
    std::string name;   ///< Име на единицата
    Faction faction;


public:
    bool isCommanderUnit() const;
    Faction getFaction() const;

    Unit(std::string name, int hp, int mp, const Armor& armor, int atk, int cost);

    virtual ~Unit() = default;

    /**
     * @brief Извършва атака към друга единица.
     */
    virtual void attack(Unit& target);

    /**
     * @brief Получава щети, отчитайки бронята.
     */
    virtual void receiveDamage(int dmg);

    /**
     * @brief Проверява дали единицата е жива.
     */
    bool isAlive() const;

    std::string getName() const;
    int getHealth() const;
    int getMana() const;
    int getCost() const;
    Armor getArmor() const;

    virtual bool canCast() const { return false; }


    /**
 * @brief Конструктор на Unit.
 */
    Unit(std::string n, int hp, int mp, ArmorType at, int as, int ap, int cost)
            : name(n), health(hp), mana(mp), armorType(at), armorStrength(as), attackPower(ap), goldCost(cost) {}

    /**
     * @brief Изпълнява основно действие.
     */
    virtual void performAction() {
        std::cout << name << " performs a basic action.\n";
    }

    int getAttackPower() const { return attackPower; }


    Armor getArmorType() const { return armor; }
};


#endif //TURNBASEDGAME_UNIT_H
