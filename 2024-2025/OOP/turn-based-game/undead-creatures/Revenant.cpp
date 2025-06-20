//
// Created by Sybatron on 6/20/2025.
//

#include "Revenant.h"

Revenant::Revenant()
        : Zombie() {
    this->name = "Ревенант";
    this->health = 600;
    armor = Armor(ArmorType::Unarmored, 0);
}
