//
// Created by Sybatron on 1/6/2023.
//
#include <string>
#include "JsonParser/headers/CommandLineValidator.h"

CommandLineValidator::CommandLineValidator(const std::string &commandLine, CommandInterpreter &cmdInterpreter) {
    this->commandLine = commandLine;
    lastIndex = commandLine.size() - 1;
    while (commandLine[lastIndex] != ' ') { lastIndex--; }
    validateCommandLine(cmdInterpreter);
}

bool CommandLineValidator::validateCommandLine(CommandInterpreter &cmdInterpreter) {
    //Nothing was in the input
    if (commandLine.empty()) {
        return false;
    }
    size_t index = 0;
    if (!isCmdStartValid(index)) {
        return false;
    }

    skipSpace(index);
    if (!isFilenameValid(index, cmdInterpreter)) {
        return false;
    }

    skipSpace(index);
    if (!isParamsValid(index, cmdInterpreter)) {
        return false;
    }

    return true;
}

bool CommandLineValidator::isCmdStartValid(size_t &index) {
    //Validate if command_line starts with json-parser
    std::string jsonValidator;

    while (index <= lastIndex && commandLine[index] != ' ') {
        jsonValidator += commandLine[index++];
    }
    if (jsonValidator != "json-parser") {
        return false;
    }
    return true;
}

bool CommandLineValidator::isFilenameValid(size_t &index, CommandInterpreter &cmdInterpreter) {
    //Validate if we have a valid json fileName
    std::string fileName;
    //Get filename
    while (index <= lastIndex && commandLine[index] != ' ') {
        fileName += commandLine[index++];
    }
    //Validate if filename has the minimum chars a.json
    if (fileName.size() < 6) {
        return false;
    }

    //Get and validate the extension of the file
    std::string fileNameValidator;
    for (size_t i = fileName.size() - 5; i < fileName.size(); ++i) {
        fileNameValidator += fileName[i];
    }
    if (fileNameValidator != ".json") {
        return false;
    }
    cmdInterpreter.setFileName(fileName);
    return true;
}

bool CommandLineValidator::isCmdValid(size_t &index, CommandInterpreter &cmdInterpreter) {
    //Validate if the command exist
    std::string command;
    while (index <= lastIndex && commandLine[index] != ' ') {
        command += commandLine[index++];
    }
    if (command.empty() || command != "-find" && command != "-change") {
        return false;
    }
    cmdInterpreter.setCommand(command);
    return true;
}

bool CommandLineValidator::isParamsValid(size_t &index, CommandInterpreter &cmdInterpreter) {
    //Validate all params
    std::string currParam;
    COMMAND_TYPE commandType;

    //Find has only one
    if (cmdInterpreter.getCommand() == "-find") {
        commandType = COMMAND_TYPE::FIND;
        if (!isParameterValid(index, cmdInterpreter)) {
            return false;
        }

        if (!hasReachedCmdEnd(index)) {
            return false;
        }
    }

    if (cmdInterpreter.getCommand() == "-change") {
        for (int i = 0; i < 2; ++i) {
            if (!isParameterValid(index, cmdInterpreter)) {
                return false;
            }
        }
        std::string las
//GET LAST TYPE
        if (!hasReachedCmdEnd(index)) {
            return false;
        }
    }
    return true;
}

bool CommandLineValidator::isParameterValid(size_t &index, CommandInterpreter &cmdInterpreter) {
    skipSpace(index);
    index++; //Go to first " symbol
    if (commandLine[index++] != '"') {
        return false;
    }

    std::string currParam;
    while (index != commandLine.size() && commandLine[index] != '"') {
        currParam += commandLine[index++];
    }
    if (currParam.empty() || index == commandLine.size()) {
        return false;
    }
    index++;
    cmdInterpreter.getParams().push_back(currParam);
    return true;
}

void CommandLineValidator::skipSpace(size_t &index) {
    index++; //Skip the space
}

bool CommandLineValidator::hasReachedCmdEnd(size_t &index) {
    index++;
    if (index != lastIndex ) {
        return false;
    }
    return true;
}


