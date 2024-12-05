//
// Created by Sybatron on 5/10/2023.
//

#ifndef PROJECT_SOCIALMEDIA_USER_H
#define PROJECT_SOCIALMEDIA_USER_H

#pragma once

#include "Set.h"


class User {

private:
    std::string fname;
    std::string lname;
    std::string username; //UNIQUE
    std::string password;
    size_t uid;
    static Set<size_t> modIds;
    static size_t userId;
    unsigned int points{};
public:
    User(const std::string &fname, const std::string &lname, const std::string &username, const std::string &password);

    virtual ~User();

    const std::string &getFName() const;

    void setFName(const std::string &_fname);

    const std::string &LName() const;

    void setLName(const std::string &_lname);

    const std::string &getUsername() const;

    void setUsername(const std::string &_username);

    const std::string &getPassword() const;

    void setPassword(const std::string &_password);

    size_t getUid() const;

    unsigned int getPoints() const;

    void setPoints(unsigned int _points);

    bool operator==(const User &rvs) const;

    bool operator!=(const User &rvs) const;

    bool operator==(const std::string &rvs) const;

    bool operator!=(const std::string &rvs) const;
};


#endif //PROJECT_SOCIALMEDIA_USER_H
