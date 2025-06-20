//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_WIZARD_H
#define TURNBASEDGAME_WIZARD_H

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

#endif //TURNBASEDGAME_WIZARD_H
