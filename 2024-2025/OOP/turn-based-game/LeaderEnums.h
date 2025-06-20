#ifndef TURNBASEDGAME_LEADERENUMS_H
#define TURNBASEDGAME_LEADERENUMS_H
#pragma once

#include <string>

// --- Enum classes for leader species ---
enum class LivingSpecies {
    UNDEAD_HUNTER,
    BLADE_DANCER,
    PALADIN,
    UNKNOWN
};

enum class UndeadSpecies {
    LICH,
    DREAD_LORD,
    DEATH_KNIGHT,
    UNKNOWN
};

// --- Leader structs ---
struct LivingLeader {
    std::string name;
    LivingSpecies specie;
};

struct UndeadLeader {
    std::string name;
    UndeadSpecies specie;
};

#endif //TURNBASEDGAME_LEADERENUMS_H
