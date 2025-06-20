//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_BLADEDANCER_H
#define TURNBASEDGAME_BLADEDANCER_H

#pragma once

#include "../Unit.h"

/**
 * @class BladeDancer
 * @brief Главнокомандващ при хората със силна атака.
 */
class BladeDancer : public Unit {
public:
    BladeDancer();

    bool isCommanderUnit() const override;
};


#endif //TURNBASEDGAME_BLADEDANCER_H
