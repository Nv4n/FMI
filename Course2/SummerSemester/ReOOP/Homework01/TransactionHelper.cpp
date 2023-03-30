//
// Created by Sybatron on 3/28/2023.
//

#include <ctime>
#include <fstream>
#include <iostream>
#include "TransactionHelper.h"

void TransactionHelper::sendCoins(unsigned int sender, unsigned int receiver, double coins) {
    if (coins <= 0) {
        std::cout << "coins can't be less than 0" << std::endl;
        return;
    }
    long long ms = std::time(nullptr);
    Transaction ts{};
    ts.coins = coins;
    ts.receiver = receiver;
    ts.sender = sender;
    ts.time = std::time(nullptr);

    std::ifstream in("block.dat", std::ios::binary);

    if (!in.is_open()) {
        std::cout << "Block file couldn't be opened" << std::endl;
        return;
    }

    double currentCoinsSender = 0;
    TransactionBlock tsblock{};
    std::size_t pos;
    if (sender != 0) {
        while (!in.eof()) {
            pos = (std::size_t) in.tellg();

            in >> tsblock.id >> tsblock.prevBlockId >> tsblock.prevBlockHash >> tsblock.validTransactions;
            in.read(reinterpret_cast<char *>(tsblock.transactions), sizeof(tsblock.transactions));
            for (int i = 0; i < tsblock.validTransactions; ++i) {
                if (tsblock.transactions[i].sender == sender) {
                    currentCoinsSender -= tsblock.transactions[i].coins;
                } else if (tsblock.transactions[i].receiver == sender) {
                    currentCoinsSender += tsblock.transactions[i].coins;
                }
            }
        }
    }

    
    std::ofstream out("blocks.dat", std::ios::binary | std::ios::ate);
}
