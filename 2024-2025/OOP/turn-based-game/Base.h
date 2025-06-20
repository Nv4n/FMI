//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_BASE_H
#define TURNBASEDGAME_BASE_H


#pragma once

#include <vector>
#include <iostream>
#include "Unit.h"
#include "BaseImports.h"

/**
 * @enum UnitEnum
 * @brief Типове единици, които могат да бъдат създадени.
 *
 * Включва всички видове единици от двете фракции: Живи и Неживи.
 */
enum class UnitEnum {
    // Living
    INFANTRYMAN, ARCHER, KNIGHT, HEALER, WIZARD, UNDEAD_HUNTER, BLADE_DANCER, PALADIN,
    // Undead
    SKELETON, GHOUL, NECROMANCER, ZOMBIE, DYBBUK, REVENANT, GHOST, LICH, DREADLORD, DEATH_KNIGHT
};

/**
 * @class Base
 * @brief Представлява база, която управлява единици, командири и ресурси (злато).
 */
class Base {
private:
    Faction faction; ///< Фракцията на базата.
    int gold; ///< Наличното злато.
    std::size_t unitLimit; ///< Максимален брой единици
    std::vector<Unit *> units;  ///< Списък с всички обикновени единици.
    std::vector<Unit *> commanders; ///< Списък с всички командири.

public:
    /**
     * @brief Конструктор.
     * @param faction Фракцията на базата.
     * @param initialGold Начално количество злато.
     * @param unitLimit Ограничение за броя единици.
     */
    Base(Faction faction, int initialGold, std::size_t unitLimit);

    /**
     * @brief Деструктор.
     * Освобождава динамично заделената памет за единици и командири.
     */
    ~Base();

    /**
     * @brief Създава единица, ако има достатъчно място и злато.
     * @param newUnit Указател към новата единица.
     * @return true ако създаването е успешно, иначе false.
     */
    bool createUnit(Unit *newUnit);

    /**
    * @brief Добавя командир към базата.
    * @param commander Указател към командира.
    * @return true ако добавянето е успешно, иначе false.
    */
    bool addCommander(Unit *commander);

    /**
   * @brief Връща всички живи единици.
   * @return Вектор с указатели към живите единици.
   */
    std::vector<Unit *> getAliveUnits() const;

    /**
    * @brief Връща всички живи командири.
    * @return Вектор с указатели към живите командири.
    */
    std::vector<Unit *> getAliveCommanders() const;

    /**
    * @brief Възстановява здравето и маната на противниковата страна.
    * @param other Базата на противника.
    */
    void restoreOtherSide(Base &other);

    /**
  * @brief Записва информация за командирите във файл.
  * @param out Изходен поток.
  */
    void save(std::ostream &out) const;

    /**
    * @brief Зарежда информация за командирите от файл.
    * @param in Входен поток.
    */
    void load(std::istream &in);

    /**
     * @brief Връща текущото количество злато.
     * @return Брой злато.
     */
    int getGold() const;

    /**
     * @brief Добавя злато към базата.
     * @param amount Количество за добавяне.
     */
    void addGold(int amount);

    /**
    * @brief Връща броя на оставащите свободни места за единици.
    * @return Оставащ брой места.
    */
    size_t getRemainingUnitSlots() const;

    /**
    * @brief Създава единица по зададен тип.
    * @param type Типът на единицата.
    * @return Указател към създадената единица или nullptr при неуспех.
    */
    Unit *createUnitFromName(UnitEnum type);

};


#endif //TURNBASEDGAME_BASE_H
