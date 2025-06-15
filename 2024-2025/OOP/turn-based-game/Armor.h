//
// Created by Sybatron on 6/9/2025.
//

#ifndef TURN_BASED_GAME_ARMOR_H
#define TURN_BASED_GAME_ARMOR_H
#include <string>


/**
 * @enum ArmorType
 * @brief Типове броня, които всяка единица може да има.
 */
enum class ArmorType {
    Unarmored, ///< Без броня
    Leather, ///< Кожена броня
    Medium, ///< Средна броня
    Heavy  ///< Тежка броня
};


#pragma once
/**
 * @brief Представя броня с тип и издръжливост.
 */
class Armor {
private:
    ArmorType type;
    int durability;

public:
    Armor(ArmorType type, int durability);

    /**
     * @brief Изчислява редуцираната стойност на щетата.
     * @param incoming Ударът.
     * @return Намалената стойност на удара.
     */
    int absorb(int incoming);

    /**
     * @brief Проверка дали бронята е изчерпана.
     */
    bool isBroken() const;

    ArmorType getType() const;
    int getDurability() const;
};


#endif //TURN_BASED_GAME_ARMOR_H
