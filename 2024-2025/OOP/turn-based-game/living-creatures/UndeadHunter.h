//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_UNDEADHUNTER_H
#define TURNBASEDGAME_UNDEADHUNTER_H

#pragma once

#include "../Unit.h"

/**
 * @class UndeadHunter
 * @brief Главнокомандващ при хората, способен да унищожава немъртви командири.
 */
class UndeadHunter : public Unit {
public:
    UndeadHunter();

    /**
     * @brief Унищожава немъртъв главнокомандващ.
     * @param target Целта.
     * @return true ако е успешно.
     */
    bool destroyUndeadCommander(Unit &target);

    bool isCommanderUnit() const override;
};

#endif //TURNBASEDGAME_UNDEADHUNTER_H
