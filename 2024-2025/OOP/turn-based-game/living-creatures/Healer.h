//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_HEALER_H
#define TURNBASEDGAME_HEALER_H

#pragma once

#include "../Unit.h"

/**
 * @brief Лечител – поддържаща единица, може да лекува други.
 */
class Healer : public Unit {
public:
    Healer();

    /**
     * @brief Лекува жива единица.
     * @param target единицата, която ще бъде излекувана
     * @return true, ако лечението е успешно
     */
    bool heal(Unit &target);

//    bool canCast() const override;
};


#endif //TURNBASEDGAME_HEALER_H
