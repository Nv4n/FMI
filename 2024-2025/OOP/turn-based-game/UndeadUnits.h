//
// Created by Sybatron on 6/9/2025.
//

#ifndef TURNBASEDGAME_UNDEADUNITS_H
#define TURNBASEDGAME_UNDEADUNITS_H
#pragma once
#include "Unit.h"
#include <vector>
#include <memory>

/**
 * @brief Скелет – основна немъртва единица.
 */
class Skeleton : public Unit {
public:
    Skeleton();
};

/**
 * @brief Гул – бронирана немъртва единица.
 */
class Ghoul : public Unit {
public:
    Ghoul();
};

/**
 * @brief Некромант – призовава до 3 скелета, ако има достатъчно мана и мъртви живи единици.
 */
class Necromancer : public Unit {
public:
    Necromancer();

    /**
     * @brief Призовава до 3 скелета, ако има условия.
     * @param deadUnits мъртви живи единици от предишния ход
     * @return вектор с нови скелети (до 3)
     */
    std::vector<std::unique_ptr<Skeleton>> summonSkeletons(const std::vector<Unit*>& deadUnits);

    bool canCast() const override;
};

/**
 * @brief Зомби – немъртва единица.
 */
class Zombie : public Unit {
public:
    Zombie();
};

/**
 * @brief Дибук – зомби с мана, използва 150 мана за атака.
 */
class Dybbuk : public Zombie {
public:
    Dybbuk();

    void attack(Unit& target) override;
    bool canCast() const override;
};

/**
 * @brief Ревенант – силна зомби единица с повече здраве.
 */
class Revenant : public Zombie {
public:
    Revenant();
};

/**
 * @brief Призрак – саможертвена единица, дава 250 здраве на друг немъртъв.
 */
class Ghost : public Unit {
public:
    Ghost();

    /**
     * @brief Жертва себе си, за да възстанови 250 HP на съюзна немъртва единица.
     * @param target целта
     * @return true, ако успешно
     */
    bool sacrificeToHeal(Unit& target);
};

#endif //TURNBASEDGAME_UNDEADUNITS_H
