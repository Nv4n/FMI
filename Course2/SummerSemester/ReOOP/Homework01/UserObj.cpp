//
// Created by Sybatron on 3/28/2023.
//

#include "UserObj.h"

UserObj::UserObj(const char name[128], const double levs) {
    for (int i = 0; i < 128 && name[i] != '\0'; ++i) {
        user.name[i] = name[i];
    }
    user.id = Id++;
}
