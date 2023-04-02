//
// Created by Sybatron on 4/2/2023.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include <ctime>
#include "RichDataHelper.h"
#include "TransactionHelper.h"

void RichDataHelper::getWealthyUsers(unsigned int entityCount) {
    //TODO
    std::ifstream in("users.dat", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "users.dat couldn't be open" << std::endl;
        return;
    }
    const unsigned int topN = entityCount;
    WealthyUser wealthUsers[topN];
    int numRead = 0;

    while (!in.eof()) {
        WealthyUser currentWealthyUser{};

        in.read(reinterpret_cast<char *>(&wealthUsers[numRead]), sizeof(WealthyUser));
        int minIndex = 0;
        for (int i = 1; i < topN; i++) {
            if (wealthUsers[i].coins < wealthUsers[minIndex].coins) {
                minIndex = i;
            }
        }
        if (wealthUsers[numRead].coins > wealthUsers[minIndex].coins) {
            wealthUsers[minIndex] = wealthUsers[numRead];
        }

        numRead++;
    }
    in.close();

    char cmd[] = "wealthiest-users";
    long long time = std::time(nullptr);
    std::ofstream out(std::strcat(cmd, reinterpret_cast<const char *>(time)));

    for (int i = 0; i < topN; i++) {
    }
}

void RichDataHelper::getBigBlocks(unsigned int entityCount) {
    char cmd[] = "biggest-blocks";
    long long time = std::time(nullptr);
    std::ofstream out(std::strcat(cmd, reinterpret_cast<const char *>(time)));
}
