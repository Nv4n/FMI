//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_DREADLORD_H
#define TURNBASEDGAME_DREADLORD_H

#pragma once

#include <vector>
#include "../Unit.h"

/**
 * @class Dreadlord
 * @brief Главнокомандващ на немъртвите, способен да призовава гулове и некроманти.
 */
class Dreadlord : public Unit {
public:
    Dreadlord();

    /**
     * @brief Призовава немъртви създания.
     * @param mana Референция към текущата манна на владетеля.
     * @return Вектор с призовани единици.
     */
    std::vector<Unit *> summon(int &mana);
};


#endif //TURNBASEDGAME_DREADLORD_H
