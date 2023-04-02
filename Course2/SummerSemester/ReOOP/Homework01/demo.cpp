#include <iostream>
#include <cstring>
#include "UserHelper.h"
#include "TransactionHelper.h"

//
// Created by Sybatron on 3/28/2023.
//

void getMenuInput();

void getCreateUserInput();

void getRemoveUserInput();

void getSendCoinsInput();

int main() {
    UserHelper::calibrateId();
    TransactionHelper::calibrateId();
    getMenuInput();
}

void getMenuInput() {
    while (true) {
        // 19 characters is the longest command length
        // Adding more symbols if we have
        // invalid commands with more than 19 symbols
        char cmd[21];
        std::cin >> cmd;

        if (std::strcmp(cmd, "create-user") == 0) {
            getCreateUserInput();
        } else if (std::strcmp(cmd, "remove-user") == 0) {
            getRemoveUserInput();
        } else if (std::strcmp(cmd, "send-coins") == 0) {
            getSendCoinsInput();
        } else if (std::strcmp(cmd, "verify-transactions") == 0) {
            std::cout << "success" << std::endl;
        } else if (std::strcmp(cmd, "wealthiest-users") == 0) {
            std::cout << "success" << std::endl;
        } else if (std::strcmp(cmd, "biggest-blocks") == 0) {
            std::cout << "success" << std::endl;
        } else if (std::strcmp(cmd, "exit") == 0) {
            return;
        } else {
            std::cout << "Invalid command" << std::endl;
        }
    }
}

void getCreateUserInput() {
    char tempName[128];
    double levs;
    std::cin >> tempName >> levs;
    UserHelper::createUser(tempName, levs);
}

void getRemoveUserInput() {
    char tempName[128];
    std::cin >> tempName;
    UserHelper::removeUser(tempName);
}

void getSendCoinsInput() {
    unsigned sender;
    unsigned receiver;
    double coins;
    std::cin >> sender >> receiver >> coins;
    TransactionHelper::sendCoins(sender, receiver, coins);
}