//
// Created by Sybatron on 6/20/2025.
//

#include "Lich.h"

bool Lich::raiseDead(int deadAlliesThisTurn, bool alreadyRaisedThisTurn) {
    if (!alreadyRaisedThisTurn && deadAlliesThisTurn > 0 && mana >= 750) {
        mana -= 750;
        std::cout << "Lich raises dead units!\n";
        return true;
    }
    return false;
}

Lich::Lich() : Unit("Lich", 1500, 1000, Armor(ArmorType::Heavy, 15), 100, 0) {}
