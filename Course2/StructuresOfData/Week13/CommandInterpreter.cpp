//
// Created by Sybatron on 1/6/2023.
//

#include <string>
#include <iostream>
#include "CommandInterpreter.h"

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
    if (command != "-find" && command != "-change") {
        return false;
    }

    //Validate and get the change type
    index++;
    if (command == "-change") {
        //Validate and get params first then get the change type if needed


        std::string changeType;
        size_t tempIndex = commandLine.size() - 1;
        while (commandLine[tempIndex] != ' ') {
            changeType = commandLine[tempIndex--] + changeType;
        }
    }

    return false;
}
