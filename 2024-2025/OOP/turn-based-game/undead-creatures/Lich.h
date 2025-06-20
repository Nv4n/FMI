//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_LICH_H
#define TURNBASEDGAME_LICH_H

#pragma once

#include "../Unit.h"

/**
 * @class Lich
 * @brief Главнокомандващ на немъртвите, способен да въздига мъртъвци.
 */
class Lich : public Unit {
public:
    Lich();

    /**
     * @brief Въздига мъртви единици.
     * @param deadAlliesThisTurn Брой паднали съюзници през този ход.
     * @param alreadyRaisedThisTurn Дали вече е въздигано този ход.
     * @return true ако заклинанието е успешно.
     */
    bool raiseDead(int deadAlliesThisTurn, bool alreadyRaisedThisTurn);
};


#endif //TURNBASEDGAME_LICH_H
