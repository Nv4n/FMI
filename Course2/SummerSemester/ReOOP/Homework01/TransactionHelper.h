//
// Created by Sybatron on 3/28/2023.
//

#ifndef WEEK05_OOPCOIN_HOMEWORK01_TRANSACTIONHELPER_H
#define WEEK05_OOPCOIN_HOMEWORK01_TRANSACTIONHELPER_H

#pragma once
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

class TransactionHelper {
private:
    static unsigned Id;
public:
    static void sendCoins(unsigned sender, unsigned receiver, double coins);

};

unsigned TransactionHelper::Id = 0;


#endif //WEEK05_OOPCOIN_HOMEWORK01_TRANSACTIONHELPER_H
