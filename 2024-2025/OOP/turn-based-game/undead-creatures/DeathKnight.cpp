#include "DeathKnight.h"
#include <cstdlib>
#include <ctime>

DeathKnight::DeathKnight(): Unit("Death Knight", 2500, 1000, Armor(ArmorType::Heavy, 15), 150, 0) {} {}

void DeathKnight::healUndead(Unit &target) {
    if (mana >= 350) {
        mana -= 350;
        target.receiveDamage(-100);
        std::cout << "Death Knight heals undead unit.\n";
    }
}

bool DeathKnight::tryCreateFromDeadKnight() {
    std::srand(std::time(nullptr));
    return (std::rand() % 100) < 25;
}