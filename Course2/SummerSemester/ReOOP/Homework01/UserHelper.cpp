//
// Created by Sybatron on 3/28/2023.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include "UserHelper.h"
#include "TransactionHelper.h"

unsigned UserHelper::UserId = 1;

void UserHelper::createUser(const char name[128], double levs) {
    User user{};
    std::strcpy(user.name, name);
    //TODO
    //  DELETE THIS1+
//    for (int i = 0; i < 128 && name[i] != '\0'; ++i) {
//        user.name[i] = name[i];
//    }

    user.id = UserHelper::UserId;
    if (!TransactionHelper::sendCoins(0, user.id, levs * 420)) {
        std::cout << "Unable to transfer coins" << std::endl;
        return;
    }

    std::ofstream out("users.dat", std::ios::binary | std::ios::app);
    if (!out.is_open()) {
        std::cout << "users.dat couldn't be opened" << std::endl;
        return;
    }
    out.write(reinterpret_cast<const char *>(&user), sizeof(user));
    out.close();
    getNextId();
}


void UserHelper::removeUser(const char name[128]) {
    std::ifstream in("users.dat", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "users.dat couldn't be opened" << std::endl;
        return;
    }

    std::ofstream out("tempusers.dat", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "tempusers.dat couldn't be opened" << std::endl;
        return;
    }

    User user{};
    while (!in.eof()) {
        in.read(reinterpret_cast<char *>(&user), sizeof(user));
        if (std::strcmp(user.name, name) != 0) {
            out.write(reinterpret_cast<char *>(&user), sizeof(user));
        } else {
            if (!TransactionHelper::sendAll(user.id)) {
                std::cout << "Unable to transfer all coins from user: " << user.id << std::endl;
                return;
            }
        }
    }
    in.close();
    out.close();

    if (std::remove("users.dat") != 0) {
        std::cout << "Unable to delete users.dat" << std::endl;
    } else if (std::rename("tempusers.dat", "users.dat") != 0) {
        std::cout << "Unable to rename tempusers.dat to users.dat" << std::endl;
    } else {
        std::cout << "User removed successfully" << std::endl;
    }

}

unsigned UserHelper::getNextId() {
    return UserId++;
}

void UserHelper::calibrateId() {
    std::ifstream in("users.dat", std::ios::binary);
    User user{};
    if (in.is_open()) {
        while (!in.eof()) {
            in.read(reinterpret_cast<char *>(&user), sizeof(user));
            UserId = user.id;
        }
    }

    in.close();
    std::cout << "User Id is calibrated" << std::endl;
}
