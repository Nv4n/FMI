//
// Created by Sybatron on 6/9/2025.
//

#include "Armor.h"

#include "Armor.h"

Armor::Armor(ArmorType t, int d) : type(t), durability(d) {}

int Armor::absorb(int damage) {
    if (durability <= 0) return damage;

    float reduction = 0.0f;
    switch (type) {
        case ArmorType::Leather:  reduction = 0.25f; break;
        case ArmorType::Medium:   reduction = 0.50f; break;
        case ArmorType::Heavy:    reduction = 0.75f; break;
        default:                  reduction = 0.0f;
    }

    durability--;
    return static_cast<int>(damage * (1.0f - reduction));
}

bool Armor::isBroken() const {
    return durability <= 0;
}

ArmorType Armor::getType() const { return type; }
int Armor::getDurability() const { return durability; }
