//
// Created by Sybatron on 4/2/2023.
//

#ifndef WEEK05_OOPCOIN_HOMEWORK01_RICHDATAHELPER_H
#define WEEK05_OOPCOIN_HOMEWORK01_RICHDATAHELPER_H

#pragma once

class RichDataHelper {
private:
    struct WealthyUser {
        char name[128];
        double coins;
    };
    struct BigBlock {
        unsigned id;
        double coins;
    };
public:
    static void getWealthyUsers(unsigned entityCount);

    static void getBigBlocks(unsigned entityCount);
};


#endif //WEEK05_OOPCOIN_HOMEWORK01_RICHDATAHELPER_H
