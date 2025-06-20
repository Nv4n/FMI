//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_DEATHKNIGHT_H
#define TURNBASEDGAME_DEATHKNIGHT_H

#pragma once

#include "../Unit.h"

/**
 * @class DeathKnight
 * @brief Немъртъв рицар, който може да се създаде след смъртта на жив рицар.
 */
class DeathKnight : public Unit {
public:
    DeathKnight();

    /**
     * @brief Лекува друга немъртва единица.
     * @param target Единицата, която ще бъде излекувана.
     */
    void healUndead(Unit &target);

    /**
     * @brief Опит за създаване на Death Knight след смъртта на жив рицар.
     * @return true с вероятност 25%.
     */
    static bool tryCreateFromDeadKnight();
};


#endif //TURNBASEDGAME_DEATHKNIGHT_H
