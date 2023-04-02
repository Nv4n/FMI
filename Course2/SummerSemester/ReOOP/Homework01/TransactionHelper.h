//
// Created by Sybatron on 3/28/2023.
//

#ifndef WEEK05_OOPCOIN_HOMEWORK01_TRANSACTIONHELPER_H
#define WEEK05_OOPCOIN_HOMEWORK01_TRANSACTIONHELPER_H

#pragma once


class TransactionHelper {
private:
    struct Transaction {
        unsigned sender;
        unsigned receiver;
        double coins;
        long long time;
    };

    static unsigned TsBlockId;
public:
    struct TransactionBlock {
        unsigned id;
        unsigned prevBlockId;
        unsigned prevBlockHash;
        int validTransactions;
        Transaction transactions[16];
    };

    static bool sendCoins(unsigned sender, unsigned receiver, double coins);

    static bool sendAll(unsigned sender);

    static double getUserCoins(unsigned userId);

    static void verifyTransactions();

    static void calibrateId();

private:
    static double getCoins(std::ifstream &in, unsigned sender);

    static void findLastBlock(std::ifstream &in);

    static bool
    addTransaction(unsigned sender, unsigned receiver, double coins);

    static unsigned computeHash(const unsigned char *memory, int length);
};


#endif //WEEK05_OOPCOIN_HOMEWORK01_TRANSACTIONHELPER_H
