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
    for (;;) {
        //19 characters is the longest command length
        char cmd[19];
        char c;
        int i = 0;
        while (std::cin.get(c) && c != ' ' && c != '\n') {
            if (i == 19) {
                cmd[0] = '\0'; //Invalidating the whole command
                break;
            }
            cmd[i++] = c;
        }
        cmd[i] = '\0';
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
        std::cin.ignore();
    }
}

void getCreateUserInput() {
    char tempName[128];
    char c;
    int i = 0;
    while (std::cin.get(c) && c != ' ' && c != '\n') {
        if (i == 128) {
            std::cout << "Invalid length of name";
            return;
        }
        tempName[i++] = c;
    }
    tempName[i] = i != 127 ? '\0' : tempName[i];
    double levs;
    std::cin >> levs;
    UserHelper::createUser(tempName, levs);
}

void getRemoveUserInput() {
    char tempName[128];
    char c;
    int i = 0;
    while (std::cin.get(c) && c != ' ' && c != '\n') {
        if (i == 128) {
            std::cout << "Invalid length of name";
            return;
        }
        tempName[i++] = c;
    }
    tempName[i] = i != 127 ? '\0' : tempName[i];
    UserHelper::removeUser(tempName);
}

void getSendCoinsInput() {
    unsigned sender;
    unsigned receiver;
    double coins;
    std::cin >> sender >> receiver >> coins;
    TransactionHelper::sendCoins(sender, receiver, coins);
}