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

    struct TransactionBlock {
        unsigned id;
        unsigned prevBlockId;
        unsigned prevBlockHash;
        int validTransactions;
        Transaction transactions[16];
    };

    static unsigned TsBlockId;
public:
    static bool sendCoins(unsigned sender, unsigned receiver, double coins);

    static bool sendAll(unsigned sender);

    static double getUserCoins(unsigned userId);

    static void calibrateId();

private:
    static double getCoins(std::ifstream &in, unsigned sender, long long &pos, TransactionBlock &tsblock);

    static void findLastBlock(std::ifstream &in, long long int &pos, TransactionBlock &tsblock);

    static bool
    addTransaction(TransactionBlock tsblock, unsigned sender, unsigned receiver, double coins, long long pos);

    static unsigned computeHash(const unsigned char *memory, int length);
};


#endif //WEEK05_OOPCOIN_HOMEWORK01_TRANSACTIONHELPER_H
