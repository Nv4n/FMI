

#ifndef TURNBASEDGAME_GAMECONFIG_H
#define TURNBASEDGAME_GAMECONFIG_H

#pragma once

#include <string>
#include <vector>
#include "LeaderEnums.h"

/**
 * @class GameConfig
 * @brief Отговаря за конфигурацията на играта – максимален брой единици, начално злато и главнокомандващите.
 *
 * Класът предоставя функционалности за зареждане на конфигурацията от файл, извеждане на текущите настройки
 * и преобразуване между низове и елементи от изброим тип за видовете главнокомандващите.
 */
class GameConfig {
private:
    int maxUnits = 0; ///< Максимален брой единици, позволен в играта.
    int startLivingGold = 0;  ///< Начално количество злато за фракцията на живите.
    int startUndeadGold = 0; ///< Начално количество злато за фракцията на немъртвите.

    std::vector<LivingLeader> livingLeaders;  ///< Списък с главнокомандващите на живите и техните видове.
    std::vector<UndeadLeader> undeadLeaders;///< Списък с главнокомандващите на немъртвите и техните видове.

    int livingSpeciesCounts[3] = {0, 0, 0}; ///< Брой главнокомандващите за всеки вид при живите.
    int undeadSpeciesCounts[3] = {0, 0, 0}; ///< Брой главнокомандващите за всеки вид при немъртвите.
public:

    /**
     * @brief Зарежда конфигурацията на играта от файл.
     * @param path Път до конфигурационния файл.
     * @throws std::runtime_error ако файлът не може да бъде отворен или съдържа невалидни данни.
     */
    void loadFromFile(const std::string &path);

    /**
    * @brief Извежда текущата конфигурация на екрана.
    */
    void print() const;

private:
    /**
   * @brief Премахва водещите и крайните интервали/знаци за нов ред от низ.
   * @param s Низът, който ще бъде обработен.
   */
    static void trim(std::string &s);

    /**
 * @brief Преобразува низ към изброим тип LivingSpecies.
 * @param name Името на вида.
 * @return Съответстващ LivingSpecies, или LivingSpecies::UNKNOWN, ако не е разпознат.
 */
    LivingSpecies getLivingSpecies(const std::string &name) const;

    /**
     * @brief Преобразува низ към изброим тип UndeadSpecies.
     * @param name Името на вида.
     * @return Съответстващ UndeadSpecies, или UndeadSpecies::UNKNOWN, ако не е разпознат.
     */
    UndeadSpecies getUndeadSpecies(const std::string &name) const;

    /**
     * @brief Преобразува LivingSpecies към низ (на български език).
     * @param s Стойността на LivingSpecies.
     * @return Името на вида като низ.
     */
    std::string livingSpeciesToString(LivingSpecies s) const;

    /**
    * @brief Преобразува UndeadSpecies към низ (на български език).
    * @param s Стойността на UndeadSpecies.
    * @return Името на вида като низ.
    */
    std::string undeadSpeciesToString(UndeadSpecies s) const;
};

#endif //TURNBASEDGAME_GAMECONFIG_H

#pragma clang diagnostic pop