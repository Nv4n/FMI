//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_NECROMANCER_H
#define TURNBASEDGAME_NECROMANCER_H

#pragma once

#include <vector>
#include "../Unit.h"
#include "Skeleton.h"

/**
 * @brief Некромант – призовава до 3 скелета, ако има достатъчно мана и мъртви живи единици.
 */
class Necromancer : public Unit {
public:
    Necromancer();

    /**
     * @brief Призовава до 3 скелета, ако има условия.
     * @param deadUnits мъртви "живи" единици от предишния ход
     * @return вектор с нови скелети (до 3)
     */
    std::vector<Skeleton *> summonSkeletons(const std::vector<Unit *> &deadUnits);

//    bool canCast() const override;
};


#endif //TURNBASEDGAME_NECROMANCER_H
