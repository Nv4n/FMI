//
// Created by Sybatron on 5/10/2023.
//

#include <iostream>
#include <string>
#include "User.h"

User::User(const std::string &fname, const std::string &lname, const std::string &username, const std::string &password,) {
    setFName(fname);
    setLName(lname);
    setUsername(username);
    setPassword(password);
    setPoints(0);
    uid = id++;

    //TODO
    //  CHECK IF IT'S FIRST USER
    //  TO SET IT AS MOD
}

User::~User() = default;

const std::string &User::getFName() const {
    return fname;
}

void User::setFName(const std::string &fname) {
    User::fname = fname;
}

const std::string &User::LName() const {
    return lname;
}

void User::setLName(const std::string &lname) {
    User::lname = lname;
}

const std::string &User::getUsername() const {
    return username;
}

void User::setUsername(const std::string &username) {
    User::username = username;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    User::password = password;
}

size_t User::getId() const {
    return uid;
}

unsigned int User::getPoints() const {
    return points;
}

void User::setPoints(unsigned int points) {
    User::points = points;
}

size_t User::getModId() {
    return modId;
}

void User::setModId(size_t modId) {
    User::modId = modId;
}

