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
    std::string username;
    std::string password;
    std::string fname;
    std::string lname;

    std::cin >> username >> password >> fname >> lname;
    if (database.hasUser(username)) {
        std::cout << "Username already exist... signup is unsuccessful" << std::endl;
        return;
    }

    std::cout << "You signup successfully" << std::endl;

    User user(fname, lname, username, password);
    database.addUser(user);
    //TODO
    //  ADD USER TO FILE OR SOMEWHERE
}

void SystemCommander::login() {
    std::string username;
    std::string password;

    std::cin >> username >> password;
    size_t userId = database.didLogin(username, password);
    if (userId == 0) {
        std::cout << "Password or Username are wrong" << std::endl;
        return;
    }
    loggedUserId = userId;
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
