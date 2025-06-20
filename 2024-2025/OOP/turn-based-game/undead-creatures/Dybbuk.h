//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_DYBBUK_H
#define TURNBASEDGAME_DYBBUK_H


#include "Zombie.h"

/**
 * @brief Дибук – зомби с мана, използва 150 мана за атака.
 */
class Dybbuk : public Zombie {
public:
    Dybbuk();

    void attack(Unit &target) override;
//    bool canCast() const override;
};


#endif //TURNBASEDGAME_DYBBUK_H
