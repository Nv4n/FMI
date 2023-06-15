//
// Created by Sybatron on 5/10/2023.
//

#ifndef PROJECT_SOCIALMEDIA_USER_H
#define PROJECT_SOCIALMEDIA_USER_H

#pragma once

class User {
private:
    std::string fname;
    std::string lname;
    std::string username; //UNIQUE
    std::string password;
    size_t uid;
    static std::vector<size_t> modIds;
    static size_t id;
    unsigned int points{};
public:
    User(const std::string &fname, const std::string &lname, const std::string &username, const std::string &password);

    virtual ~User();

    const std::string &getFName() const;

//TODO
// THROW Arg exception on empty args

//TODO
// Test with spaces data
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


    //TODO
    //  ADD COMPARE USER SO I CAN PUT THEM IN SET
};

size_t User::id = 1;


#endif //PROJECT_SOCIALMEDIA_USER_H
