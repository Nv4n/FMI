//
// Created by Sybatron on 6/9/2025.
//

#include "Armor.h"

#include "Armor.h"

Armor::Armor(ArmorType t, int d) : type(t), durability(d) {}

int Armor::absorb(int damage) {
    if (durability <= 0) return damage;

    double reduction = 0.0;
    switch (type) {
        case ArmorType::Leather:
            reduction = 0.25;
            break;
        case ArmorType::Medium:
            reduction = 0.50;
            break;
        case ArmorType::Heavy:
            reduction = 0.75;
            break;
        default:
            reduction = 0.0;
    }

    durability--;
    return static_cast<int>(damage * (1.0 - reduction));
}

bool Armor::isBroken() const {
    return durability <= 0;
}

ArmorType Armor::getType() const { return type; }

int Armor::getDurability() const { return durability; }
