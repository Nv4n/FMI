//
// Created by Sybatron on 6/9/2025.
//

#ifndef TURNBASEDGAME_LIVINGUNITS_H
#define TURNBASEDGAME_LIVINGUNITS_H


#pragma once
#include "Unit.h"

/**
 * @brief Пехотинец – основна жива единица.
 */
class Infantryman : public Unit {
public:
    Infantryman();
};

/**
 * @brief Стрелец – единица с дистанционна атака.
 */
class Archer : public Unit {
public:
    Archer();
};

/**
 * @brief Рицар – тежковъоръжена и бронирана единица.
 */
class Knight : public Unit {
public:
    Knight();
};

/**
 * @brief Лечител – поддържаща единица, може да лекува други.
 */
class Healer : public Unit {
public:
    Healer();

    /**
     * @brief Лекува жива единица.
     * @param target единицата, която ще бъде излекувана
     * @return true, ако лечението е успешно
     */
    bool heal(Unit& target);

    bool canCast() const override;
};

/**
 * @brief Магьосник – атакуваща единица с мана.
 */
class Wizard : public Unit {
public:
    Wizard();

    void attack(Unit& target) override;
    bool canCast() const override;
};



#endif //TURNBASEDGAME_LIVINGUNITS_H
