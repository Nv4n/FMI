//
// Created by Sybatron on 5/11/2023.
//

#ifndef PROJECT_SOCIALMEDIA_SYSTEMCOMMANDER_H
#define PROJECT_SOCIALMEDIA_SYSTEMCOMMANDER_H


#include "Set.h"
#include "User.h"

class SystemCommander {
    Set<std::string> sysUsernames;
public:
    SystemCommander();

    virtual ~SystemCommander();

    void readCmd();

private:
    void signup();

    void login();

    void edit();

    void edit(size_t id);
};


#endif //PROJECT_SOCIALMEDIA_SYSTEMCOMMANDER_H
