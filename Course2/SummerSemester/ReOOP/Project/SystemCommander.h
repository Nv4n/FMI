//
// Created by Sybatron on 5/11/2023.
//

#ifndef PROJECT_SOCIALMEDIA_SYSTEMCOMMANDER_H
#define PROJECT_SOCIALMEDIA_SYSTEMCOMMANDER_H

#pragma once

#include "Database.h"


class SystemCommander {
    Database database;
    size_t loggedUserId{};
public:
    SystemCommander();

    virtual ~SystemCommander();

    void readCmd();

private:
    void signup();

    void login();

    void edit();

    void edit(size_t id);

    void create();

    void search();

    void open();

    void list();

    void post();

    void post_open();

    void post_quit();

    void quit();

    void logout();

    void exit();

    void createUser();

    void createTopic();
};


#endif //PROJECT_SOCIALMEDIA_SYSTEMCOMMANDER_H
