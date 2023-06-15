//
// Created by Sybatron on 5/11/2023.
//
#include <iostream>
#include <string>
#include <stdexcept>
#include "SystemCommander.h"

SystemCommander::SystemCommander() = default;

SystemCommander::~SystemCommander() = default;

void SystemCommander::readCmd() {
    std::string cmd;
    std::cin >> cmd;
    if (cmd == "signup") {
        signup();
        return;
    }
    if (cmd == "login") {
        login();
        return;
    }
    if (cmd == "edit") {
        edit();
        return;
    }
    if (cmd == "create") {
        create();
    }

    throw std::runtime_error(cmd + ": invalid cmd");

}

void SystemCommander::signup() {
    std::string fname;
    std::string lname;
    std::string username;
    std::string password;

    std::cin >> username >> password >> fname >> lname;
    if (!sysUsernames.insert(username)) {
        std::cout << "Username already exist... signup is unsuccessful" << std::endl;
        return;
    }

    std::cout << "You signup successfully" << std::endl;

    User user(fname, lname, username, password);
    //TODO
    //  ADD USER TO FILE OR SOMEWHERE
}

void SystemCommander::login() {
    std::string username;
    std::string password;

    std::cin >> username >> password;
    if (!sysUsernames.contains(username)) {
        std::cout << "User doesn't exist... login is unsuccessful" << std::endl;
        return;
    }
//TODO
//  SOME IF USER EXIST WITH THIS PASS
//  CHECK
    std::cout << "You logged in" << std::endl;
}

//TODO EDIT
//Всеки потребител трябва да има възможност за промяна на данните
// в собствения си акаунт (команда edit). Променят се имената или паролата.
// Ако потребителят е модератор, той може да променя и чужд акаунт (edit id),
// като освен имената и паролата
// има право да променя и ролята (да дава или да отнема модераторски права).
void SystemCommander::edit() {

}

void SystemCommander::edit(size_t id) {

}

void SystemCommander::create() {

}
