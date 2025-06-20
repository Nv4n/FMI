//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_GAME_H
#define TURNBASEDGAME_GAME_H

#include "Base.h"

/**
 * @class Game
 * @brief Управлява основния геймплей между фракциите Живи и Немъртви.
 *
 * Класът Game контролира създаването на единици, провеждането на дуели, запазването и зареждането
 * на състоянието на играта, обработката на команди и рестартирането на играта.
 * Също така следи броя на победите за всяка фракция.
 */
class Game {
private:
    Base living; ///< База на фракцията Живи.
    Base undead;///< База на фракцията Немъртви.
    int livingWins = 0;///< Брой спечелени дуели от фракцията Живи.
    int undeadWins = 0;///< Брой спечелени дуели от фракцията Немъртви.

    std::vector<Unit *> selectedLivingUnits;///<  Избраните единици от фракцията Живи за дуел.
    std::vector<Unit *> selectedLivingCommanders;///< Избраните командири от фракцията Живи за дуел.

    std::vector<Unit *> selectedUndeadUnits;///< Избраните единици от фракцията Немъртви за дуел.
    std::vector<Unit *> selectedUndeadCommanders;///< Избраните командири от фракцията Немъртви за дуел.

public:
    /**
 * @brief Създава нова игра с начално количество злато и лимит на единици за всяка фракция.
 * @param gold Начално злато за всяка база.
 * @param unitLimit Максимален брой единици, които всяка база може да създаде.
 */
    Game(int gold, size_t unitLimit);

    /**
 * @brief Обработва подадена команда (например създаване на единици, стартиране на дуел, запазване/зареждане).
 */
    void handleCommand();

    /**
    * @brief Стартира дуел между избрани единици на Живите и случайно избрани единици на Немъртвите.
    * Провежда битка, определя победителя и разпределя наградно злато.
    */
    void startDuel();

    /**
 * @brief Запазва текущото състояние на играта във файл.
 * @param filename Име на файла, в който да се запази.
 * @throws std::runtime_error ако файлът не може да бъде отворен.
 */
    void saveGame(const std::string &filename);

    /**
     * @brief Зарежда състоянието на играта от файл.
     * @param filename Име на файла, от който да се зареди.
     * @throws std::runtime_error ако файлът не може да бъде отворен.
     */
    void loadGame(const std::string &filename);

    /**
   * @brief Рестартира играта, като нулира базите и броя на победите.
   */
    void restart();

    /**
 * @brief Проверява дали играта е приключила (някоя фракция е спечелила 3 дуела).
 * @return Връща true ако играта е приключила, false в противен случай.
 */
    bool isGameOver() const;
};


#endif //TURNBASEDGAME_GAME_H
