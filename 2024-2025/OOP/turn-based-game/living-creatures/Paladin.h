//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_PALADIN_H
#define TURNBASEDGAME_PALADIN_H

#pragma once

#include "../Unit.h"

/**
 * @class Paladin
 * @brief Главнокомандващ при хората, способен да лекува и възкресява.
 */
class Paladin : public Unit {
public:
    Paladin();

    /**
     * @brief Лекува съюзна единица.
     * @param ally Съюзникът, който ще бъде излекуван.
     */
    void healAlly(Unit &ally);

    bool isCommanderUnit() const override;
};


#endif //TURNBASEDGAME_PALADIN_H
