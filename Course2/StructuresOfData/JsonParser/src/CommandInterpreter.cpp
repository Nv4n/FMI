//
// Created by Sybatron on 1/6/2023.
//

#include <iostream>
#include <string>
#include <vector>
#include "JsonParser/headers/CommandInterpreter.h"

CommandInterpreter::CommandInterpreter() {
    std::string commandLine;
    std::cin >> commandLine;
}

bool CommandInterpreter::validateCommandLine(const std::string &commandLine) {
    //Nothing was in the input
    if (commandLine.empty()) {
        return false;
    }

    //Validate if command_line starts with json-parser
    std::string jsonValidator;
    size_t index = 0;
    while (index != commandLine.size() && commandLine[index] != ' ') {
        jsonValidator += commandLine[index++];
    }
    if (jsonValidator != "json-parser") {
        return false;
    }

    //Validate if we have a valid json fileName
    index++;
    while (index != commandLine.size() && commandLine[index] != ' ') {
        fileName += commandLine[index++];
    }
    std::string fileNameValidator;
    if (fileName.size() < 6) {
        return false;
    }
    for (size_t i = fileName.size() - 5; i < fileName.size(); ++i) {
        fileNameValidator += fileName[i];
    }
    if (fileNameValidator != ".json") {
        return false;
    }

    //Validate if the command exist
    index++;
    while (index != commandLine.size() && commandLine[index] != ' ') {
        command += commandLine[index++];
    }
    if (command.empty() || command != "-find" && command != "-change") {
        return false;
    }

    //Validate all params


    std::string currParam;
    if (command == "-find") {
        commandType = COMMAND_TYPE::FIND;
        index += 2;
        if (commandLine[index] != '"') {
            return false;
        }
        while (index != commandLine.size() && commandLine[index] != '"') {
            currParam += commandLine[index++];
        }
        if (currParam.empty()) {
            return false;
        }
        params.push_back(currParam);
        index++;
        if (index != commandLine.size()) {
            return false;
        }
    }

    if (command == "-change") {
        for (int i = 0; i < 2; ++i) {
            //DUPLICATING CODE
            index += 2;
            if (commandLine[index] != '"') {
                return false;
            }
            while (index != commandLine.size() && commandLine[index] != '"') {
                currParam += commandLine[index++];
            }
            if (currParam.empty()) {
                return false;
            }
            params.push_back(currParam);
            //============================================
        }

        //DUPLICATING CODE
        index++;
        if (index != commandLine.size()) {
            return false;
        }
        //============================================
    }

    return true;
}

const std::string &CommandInterpreter::getFileName() const {
    return fileName;
}

const std::string &CommandInterpreter::getCommand() const {
    return command;
}

const std::vector<std::string> &CommandInterpreter::getParams() const {
    return params;
}

COMMAND_TYPE CommandInterpreter::getCommandType() const {
    return commandType;
}

void CommandInterpreter::setFileName(const std::string &fileName) {
    CommandInterpreter::fileName = fileName;
}

void CommandInterpreter::setCommand(const std::string &command) {
    CommandInterpreter::command = command;
}

void CommandInterpreter::setParams(const std::vector<std::string> &params) {
    CommandInterpreter::params = params;
}

void CommandInterpreter::setCommandType(COMMAND_TYPE commandType) {
    CommandInterpreter::commandType = commandType;
}

CommandInterpreter::~CommandInterpreter() = default;
