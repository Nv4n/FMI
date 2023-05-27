//
// Created by Sybatron on 5/26/2023.
//

#include "User.h"

User::User() = default;

User::~User() = default;

const MinString &User::getName() const {
    return name;
}
