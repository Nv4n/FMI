//
// Created by Sybatron on 6/20/2025.
//

#ifndef TURNBASEDGAME_GAME_H
#define TURNBASEDGAME_GAME_H

#include "Base.h"

class Game {
private:
    Base living;
    Base undead;
    int livingWins = 0;
    int undeadWins = 0;

    std::vector<Unit *> selectedLivingUnits;
    std::vector<Unit *> selectedLivingCommanders;

    std::vector<Unit *> selectedUndeadUnits;
    std::vector<Unit *> selectedUndeadCommanders;

public:
    Game(int gold, size_t unitLimit);

    void handleCommand();

    void startDuel();

    void saveGame(const std::string &filename);

    void loadGame(const std::string &filename);

    void restart();

    bool isGameOver() const;
};


#endif //TURNBASEDGAME_GAME_H
