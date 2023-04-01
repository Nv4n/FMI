//
// Created by Sybatron on 3/28/2023.
//

#include <iostream>
#include <ctime>
#include <fstream>
#include "TransactionHelper.h"

unsigned TransactionHelper::TsBlockId = 0;

bool TransactionHelper::sendCoins(unsigned int sender, unsigned int receiver, double coins) {
    if (coins <= 0) {
        std::cout << "coins can't be less than 0" << std::endl;
        return false;
    }

    std::ifstream in("blocks.dat", std::ios::binary);
    TransactionBlock tsblock{};
    long long pos = 0;
    double currentCoinsSender = 0;

    if (!in) {
        currentCoinsSender = coins;
    } else if (sender != 0) {
        currentCoinsSender = getCoins(in, sender, pos, tsblock);
    } else {
        currentCoinsSender = coins;
        findLastBlock(in, pos, tsblock);
    }
    in.close();

    if (currentCoinsSender < coins) {
        std::cout << "Sender doesn't have enough coins" << std::endl;
        return false;
    }

    if (tsblock.id == 0) {
        tsblock.prevBlockId = 0;
    }
    return addTransaction(tsblock, sender, receiver, coins, pos);
}

bool TransactionHelper::sendAll(unsigned int sender) {
    std::ifstream in("blocks.dat", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "Reader couldn't open blocks.dat" << std::endl;
        return false;
    }

    TransactionBlock tsblock{};
    long long pos;
    double currentCoinsSender = getCoins(in, sender, pos, tsblock);
    in.close();

    if (tsblock.id == 0) {
        tsblock.prevBlockId = 0;
    }
    return addTransaction(tsblock, sender, 0, currentCoinsSender, pos);
}


bool TransactionHelper::addTransaction(TransactionHelper::TransactionBlock tsblock, unsigned int sender,
                                       unsigned int receiver, double coins, long long int pos) {
    std::ofstream out("blocks.dat", std::ios::binary | std::ios::app);
    if (!out.is_open()) {
        std::cout << "Writer couldn't open blocks.dat" << std::endl;
        return false;
    }

    if (tsblock.validTransactions == 16) {
        unsigned prevId = tsblock.id;
        unsigned prevHash = computeHash(reinterpret_cast<unsigned char *>(&tsblock), sizeof(tsblock));
        tsblock = {};
        tsblock.id = TransactionHelper::TsBlockId;
        TransactionHelper::TsBlockId++;
        tsblock.prevBlockId = prevId;
        tsblock.prevBlockHash = prevHash;
    } else {
        out.seekp(pos);
    }

    Transaction ts{};
    ts.coins = coins;
    ts.receiver = receiver;
    ts.sender = sender;
    ts.time = std::time(nullptr);

    tsblock.transactions[tsblock.validTransactions] = ts;
    tsblock.validTransactions++;
    out.write(reinterpret_cast<const char *>(&tsblock), sizeof(tsblock));
    out.close();
    return true;
}

double
TransactionHelper::getCoins(std::ifstream &in, unsigned int sender, long long int &pos, TransactionBlock &tsblock) {
    double currentCoinsSender = 0;
    while (!in.eof()) {
        pos = in.tellg();

        in.read(reinterpret_cast<char *>(&tsblock), sizeof(tsblock.transactions));
        for (int i = 0; i < tsblock.validTransactions; ++i) {
            if (tsblock.transactions[i].sender == sender) {
                currentCoinsSender -= tsblock.transactions[i].coins;
            } else if (tsblock.transactions[i].receiver == sender) {
                currentCoinsSender += tsblock.transactions[i].coins;
            }
        }
    }
    return currentCoinsSender;
}

void
TransactionHelper::findLastBlock(std::ifstream &in, long long int &pos, TransactionBlock &tsblock) {
    double currentCoinsSender = 0;
    while (!in.eof()) {
        pos = in.tellg();
        in.read(reinterpret_cast<char *>(&tsblock), sizeof(tsblock.transactions));
    }
}

unsigned TransactionHelper::computeHash(const unsigned char *memory, int length) {
    unsigned hash = 0xbeaf;

    for (int c = 0; c < length; c++) {
        hash += memory[c];
        hash += hash << 10;
        hash ^= hash >> 6;
    }

    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}

void TransactionHelper::calibrateId() {
    std::ifstream in("blocks.dat", std::ios::binary);
    TransactionBlock tsblock{};
    if (in.is_open()) {
        while (!in.eof()) {
            in.read(reinterpret_cast<char *>(&tsblock), sizeof(tsblock));
            TsBlockId = tsblock.id;
        }
    }

    in.close();
    std::cout << "TransactionBlocks Id is calibrated" << std::endl;
}
