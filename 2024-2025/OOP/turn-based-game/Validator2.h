//
// Created by Sybatron on 6/9/2025.
//

#ifndef TURNBASEDGAME_VALIDATOR2_H
#define TURNBASEDGAME_VALIDATOR2_H

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <vector>
#include <string>
#include <stdexcept>
#include <unordered_map>

/**
 * @brief Типове броня.
 */
enum class ArmorType {
    Unarmored,
    Leather,
    Medium,
    Heavy
};

/**
 * @brief Клас, описващ единица в играта.
 */
class Unit {
public:
    enum class Faction { Living, Undead };

protected:
    std::string name;
    int health;
    int mana;
    ArmorType armorType;
    int armorStrength;
    int attackPower;
    bool isCommander;
    Faction faction;

public:
    /**
     * @brief Конструктор на Unit.
     * @param n Име на единицата.
     * @param hp Здраве.
     * @param mp Мана.
     * @param at Тип броня.
     * @param as Стойност на бронята.
     * @param ap Сила на атаката.
     * @param commander Главнокомандващ ли е.
     * @param f Фракция.
     */
    Unit(std::string n, int hp, int mp, ArmorType at, int as, int ap, bool commander, Faction f);

    virtual ~Unit() = default;

    std::string getName() const;
    int getHealth() const;
    void setHealth(int hp);
    int getMana() const;
    void setMana(int mp);
    ArmorType getArmorType() const;
    int getArmorStrength() const;
    void decreaseArmorStrength();
    int getAttackPower() const;
    bool isCommanderUnit() const;
    Faction getFaction() const;

    /**
     * @brief Нанася щети на единицата с оглед на бронята.
     * @param damage Входящи щети.
     */
    void receiveDamage(int damage);

    /**
     * @brief Възстановява здраве на единицата.
     * @param amount Количество здраве за възстановяване.
     */
    void restoreHealth(int amount);

    /**
     * @brief Възстановява мана на единицата.
     * @param amount Количество мана за възстановяване.
     */
    void restoreMana(int amount);
};

/**
 * @brief Клас, описващ база, която създава единици.
 */
class Base {
    int gold;
    int unitLimit;
    int currentUnits;
    Unit::Faction faction;

public:
    /**
     * @brief Конструктор на Base.
     * @param g Начално злато.
     * @param limit Максимален брой единици.
     * @param f Фракция.
     */
    Base(int g, int limit, Unit::Faction f);

    /**
     * @brief Проверява дали може да се създаде единица с дадена цена.
     * @param cost Цена на единицата.
     * @return true, ако може да се създаде.
     */
    bool canCreateUnit(int cost) const;

    /**
     * @brief Създава единица (намалява златото и броя единици).
     * @param cost Цена на единицата.
     * @return true ако успешно.
     */
    bool createUnit(int cost);

    int getGold() const;
    int getUnitLimit() const;
    int getCurrentUnits() const;
    Unit::Faction getFaction() const;
};

/**
 * @brief Клас за валидация на игровите правила.
 */
class Validator {
    Base& livingBase;
    Base& undeadBase;

    std::unordered_map<std::string, int> commanderCountsLiving;
    std::unordered_map<std::string, int> commanderCountsUndead;
    const int maxCommanderCount = 7;

public:
    /**
     * @brief Конструктор на Validator.
     * @param lb Референция към базата на живите.
     * @param ub Референция към базата на немъртвите.
     */
    Validator(Base& lb, Base& ub);

    /**
     * @brief Валидира възстановяване на здраве.
     * @param allUnits Всички единици в играта.
     */
    void validateHealthRestoration(const std::vector<Unit*>& allUnits);

    /**
     * @brief След края на хода увеличава здравето и маната на другата фракция.
     * @param turnFaction Фракция, която току-що е изиграла ход.
     * @param allUnits Всички единици.
     */
    void endTurnHealthAndManaBoost(Unit::Faction turnFaction, std::vector<Unit*>& allUnits);

    /**
     * @brief Валидира и прилага бронята за намаляване на щети.
     * @param target Единицата, която получава щети.
     * @param incomingDamage Входящи щети.
     */
    void validateArmorUsage(Unit& target, int incomingDamage);

    /**
     * @brief Валидира създаване на единица спрямо ресурси и лимит.
     * @param base Базата на фракцията.
     * @param cost Цена на единицата.
     */
    void validateUnitCreation(Base& base, int cost);

    /**
     * @brief Проверява и добавя главнокомандващ към играта.
     * @param commanderName Име на главнокомандващия.
     * @param faction Фракция.
     * @throws std::runtime_error при надвишаване на лимита.
     */
    void addCommander(const std::string& commanderName, Unit::Faction faction);

    /**
     * @brief Връща броя на главнокомандващите от даден вид и фракция.
     * @param commanderName Име на главнокомандващия.
     * @param faction Фракция.
     * @return Брой.
     */
    int getCommanderCount(const std::string& commanderName, Unit::Faction faction) const;
};

#endif // VALIDATOR_H



#endif //TURNBASEDGAME_VALIDATOR2_H
