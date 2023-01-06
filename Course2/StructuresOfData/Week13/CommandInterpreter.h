//
// Created by Sybatron on 1/6/2023.
//

#ifndef WEEK13_JSONPARSER_COMMANDINTERPRETER_H
#define WEEK13_JSONPARSER_COMMANDINTERPRETER_H
#pragma once
enum COMMAND_TYPE {
    FIND,
    CHANGE,
    CREATE
};

class CommandInterpreter {
private:
    std::string fileName;
    std::string command;
    std::string params;
    COMMAND_TYPE commandType;
public:
    CommandInterpreter();

private:
    bool validateCommandLine(const std::string &commandLine);

};


#endif //WEEK13_JSONPARSER_COMMANDINTERPRETER_H
