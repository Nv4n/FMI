//
// Created by Sybatron on 3/28/2023.
//

#include <iostream>
#include <ctime>
#include <fstream>
#include "TransactionHelper.h"

unsigned TransactionHelper::TsBlockId = 0;

bool TransactionHelper::sendCoins(unsigned int sender, unsigned int receiver, double coins) {
    //TODO
    // UPDATE SO YOU DON'T UPDATE POSITION IF TSBLOCK IS NOT FULL
    if (coins <= 0) {
        std::cout << "coins can't be less than 0" << std::endl;
        return false;
    }

    std::ifstream in("blocks.dat", std::ios::binary);
    double currentCoinsSender = 0;

    if (in && sender != 0) {
        currentCoinsSender = getCoins(in, sender);
    } else {
        currentCoinsSender = coins;
    }
    in.close();

    if (currentCoinsSender < coins) {
        std::cout << "Sender doesn't have enough coins" << std::endl;
        return false;
    }

    TransactionBlock tsblock{};
    if (tsblock.id == 0) {
        tsblock.prevBlockId = 0;
    }
    return addTransaction(sender, receiver, coins);
}

bool TransactionHelper::sendAll(unsigned int sender) {
    std::ifstream in("blocks.dat", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "Reader couldn't open blocks.dat" << std::endl;
        return false;
    }

    double currentCoinsSender = getCoins(in, sender);
    in.close();

    TransactionBlock tsblock{};
    if (tsblock.id == 0) {
        tsblock.prevBlockId = 0;
    }
    return addTransaction(sender, 0, currentCoinsSender);
}

double TransactionHelper::getUserCoins(unsigned int userId) {
    std::ifstream in("blocks.dat", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "Reader couldn't open blocks.dat" << std::endl;
        return -1;
    }

    double currentCoinsSender = getCoins(in, userId);
    in.close();
    return currentCoinsSender;
}


void TransactionHelper::verifyTransactions() {
    std::ifstream in("blocks.dat", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "blocks.dat couldn't be opened" << std::endl;
        return;
    }

    TransactionBlock tsblock{};
    unsigned prevId = -1;
    unsigned prevHash = -1;
    while (!in.eof()) {
        in.read(reinterpret_cast<char *>(&tsblock), sizeof(TransactionBlock));
        unsigned currentId = tsblock.id;
        unsigned currentHash = computeHash(reinterpret_cast<unsigned char *>(&tsblock), sizeof(TransactionBlock));

        //The same result is in multiple ifs for readability
        if (currentId == 0 && tsblock.prevBlockId != 0) {
            std::cout << "TransactionBlock #" << tsblock.id << " is invalid" << std::endl;
        } else if (currentId <= prevId) {
            std::cout << "TransactionBlock #" << tsblock.id << " is invalid" << std::endl;
        } else if (currentId != 0 && prevHash != tsblock.prevBlockHash) {
            std::cout << "TransactionBlock #" << tsblock.id << " is invalid" << std::endl;
        }

        prevId = currentId;
        prevHash = currentHash;
    }
    in.close();
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

bool TransactionHelper::addTransaction(unsigned int sender,
                                       unsigned int receiver, double coins) {
    std::ifstream in("tempblocks.dat", std::ios::binary);
    if (!in.is_open()) {
        std::cout << "Reader couldn't open blocks.dat" << std::endl;
        return false;
    }

    std::ofstream out("tempblocks.dat", std::ios::binary);
    if (!out.is_open()) {
        std::cout << "Writer couldn't open tempblocks.dat" << std::endl;
        return false;
    }
    TransactionBlock tsblock{};
    while (!in.eof()) {
        in.read(reinterpret_cast<char *>(&tsblock), sizeof(TransactionBlock));
        if (tsblock.validTransactions < 16) {
            out.write(reinterpret_cast<char *>(&tsblock), sizeof(TransactionBlock));
        }
    }

    if (tsblock.id == 0) {
        tsblock.prevBlockId = 0;
    }

    if (tsblock.validTransactions == 16) {
        unsigned prevId = tsblock.id;
        unsigned prevHash = computeHash(reinterpret_cast<unsigned char *>(&tsblock), sizeof(TransactionBlock));
        tsblock = {};
        tsblock.id = TransactionHelper::TsBlockId;
        TransactionHelper::TsBlockId++;
        tsblock.prevBlockId = prevId;
        tsblock.prevBlockHash = prevHash;
    }

    Transaction ts{};
    ts.coins = coins;
    ts.receiver = receiver;
    ts.sender = sender;
    ts.time = std::time(nullptr);

    tsblock.transactions[tsblock.validTransactions] = ts;
    tsblock.validTransactions = tsblock.validTransactions + 1;
    out.write(reinterpret_cast<const char *>(&tsblock), sizeof(TransactionBlock));
    out.close();

    
    return true;
}

double
TransactionHelper::getCoins(std::ifstream &in, unsigned int sender) {
    double currentCoinsSender = 0;
    TransactionBlock tsblock;
    while (!in.eof()) {
        in.read(reinterpret_cast<char *>(&tsblock), sizeof(TransactionBlock));
        for (int i = 0; i < tsblock.validTransactions; ++i) {
            if (tsblock.transactions[i].sender == sender) {
                currentCoinsSender = currentCoinsSender - tsblock.transactions[i].coins;
            } else if (tsblock.transactions[i].receiver == sender) {
                currentCoinsSender += tsblock.transactions[i].coins;
            }
        }
    }
    return currentCoinsSender;
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

