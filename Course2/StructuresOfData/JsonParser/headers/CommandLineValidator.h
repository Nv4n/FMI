//
// Created by Sybatron on 1/6/2023.
//

#ifndef WEEK13_JSONPARSER_COMMANDLINEVALIDATOR_H
#define WEEK13_JSONPARSER_COMMANDLINEVALIDATOR_H

#include "JsonParser/headers/CommandInterpreter.h"

#pragma once
//TODO
//  Add error type to know which argument caused the error

class CommandLineValidator {
private:
    std::string commandLine;
    size_t lastIndex{};
public:
    CommandLineValidator();

    virtual ~CommandLineValidator();

    void validate(const std::string &commandLine, CommandInterpreter &cmdInterpreter);

private:
    bool validateCommandLine(CommandInterpreter &cmdInterpreter);

    bool isCmdStartValid(size_t &index);

    bool isFilenameValid(size_t &index, CommandInterpreter &cmdInterpreter);

    bool isCommandValid(size_t &index, CommandInterpreter &cmdInterpreter);

    bool isParamsValid(size_t &index, CommandInterpreter &cmdInterpreter);

    bool isParameterValid(size_t &index, CommandInterpreter &cmdInterpreter);

    bool hasReachedCmdEnd(size_t &index);

    void skipSpace(size_t &index);
};


#endif //WEEK13_JSONPARSER_COMMANDLINEVALIDATOR_H
