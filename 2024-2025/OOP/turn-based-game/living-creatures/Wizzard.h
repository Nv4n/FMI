//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_WIZZARD_H
#define TURNBASEDGAME_WIZZARD_H

#pragma once

#include "../Unit.h"

/**
 * @brief Магьосник – атакуваща единица с мана.
 */
class Wizard : public Unit {
public:
    Wizard();

    void attack(Unit &target) override;
//    bool canCast() const override;
};

#endif //TURNBASEDGAME_WIZZARD_H
