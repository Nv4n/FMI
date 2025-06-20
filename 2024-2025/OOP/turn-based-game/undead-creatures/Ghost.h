//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_GHOST_H
#define TURNBASEDGAME_GHOST_H

#pragma once

#include "../Unit.h"

class Ghost : public Unit {
public:
    Ghost();

    /**
     * @brief Жертва себе си, за да възстанови 250 HP на съюзна немъртва единица.
     * @param target целта
     * @return true, ако успешно
     */
    bool sacrificeToHeal(Unit &target);
};


#endif //TURNBASEDGAME_GHOST_H
