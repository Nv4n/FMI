//
// Created by Sybatron on 4/2/2023.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include <ctime>
#include "RichDataHelper.h"
#include "UserHelper.h"


#include "TransactionHelper.h"

void RichDataHelper::getWealthyUsers(unsigned int entityCount) {
    std::ifstream in("users.dat", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "users.dat couldn't be open" << std::endl;
        return;
    }
    const unsigned int topN = entityCount;
    WealthyUser wealthUsers[topN];

    while (!in.eof()) {
        UserHelper::User currUser{};
        in.read(reinterpret_cast<char *>(&currUser), sizeof(UserHelper::User));
        double coins = TransactionHelper::getUserCoins(currUser.id);

        WealthyUser currWealthUser{};
        std::strcpy(currWealthUser.name, currUser.name);
        currWealthUser.coins = coins;

        int minInd = 0;
        for (int i = 1; i < topN; i++) {
            if (wealthUsers[i].coins < wealthUsers[minInd].coins) {
                minInd = i;
            }
        }
        if (currWealthUser.coins > wealthUsers[minInd].coins) {
            wealthUsers[minInd] = currWealthUser;
        }
    }
    in.close();

    char cmd[] = "wealthiest-users";
    long long time = std::time(nullptr);
    std::ofstream out(std::strcat(cmd, reinterpret_cast<const char *>(time)));
    if (!out.is_open()) {
        std::cout << "Couldn't save the wealthiest-users" << std::endl;
        return;
    }

    for (int i = 0; i < topN; i++) {
        out << "Name: " << wealthUsers[i].name << ", coins: " << wealthUsers[i].coins << "\n";
    }
    out.close();
}

void RichDataHelper::getBigBlocks(unsigned int entityCount) {
    std::ifstream in("blocks.dat", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "blocks.dat couldn't be open" << std::endl;
        return;
    }
    const unsigned int topN = entityCount;
    BigBlock bigBlocks[topN];

    while (!in.eof()) {
        TransactionHelper::TransactionBlock currBlock{};
        in.read(reinterpret_cast<char *>(&currBlock), sizeof(TransactionHelper::TransactionBlock));
        double coins = 0;
        for (int i = 0; i < currBlock.validTransactions; ++i) {
            coins += currBlock.transactions[i].coins;
        }

        BigBlock currBigBlock{};
        currBigBlock.id = currBlock.id;
        currBigBlock.coins = coins;

        int minInd = 0;
        for (int i = 1; i < topN; i++) {
            if (bigBlocks[i].coins < bigBlocks[minInd].coins) {
                minInd = i;
            }
        }
        if (currBigBlock.coins > bigBlocks[minInd].coins) {
            bigBlocks[minInd] = currBigBlock;
        }
    }
    in.close();

    char cmd[] = "biggest-blocks";
    long long time = std::time(nullptr);
    std::ofstream out(std::strcat(cmd, reinterpret_cast<const char *>(time)));
    if (!out.is_open()) {
        std::cout << "Couldn't save the biggest-blocks" << std::endl;
        return;
    }

    for (int i = 0; i < topN; i++) {
        out << "Id: " << bigBlocks[i].id << ", coins: " << bigBlocks[i].coins << "\n";
    }
    out.close();
}
