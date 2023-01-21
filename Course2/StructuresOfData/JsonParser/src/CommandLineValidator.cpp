//
// Created by Sybatron on 1/6/2023.
//
#include <string>
#include <stdexcept>
#include <iostream>
#include "JsonParser/headers/CommandLineValidator.h"

CommandLineValidator::CommandLineValidator() = default;

void CommandLineValidator::validate(const std::string &commandLine, CommandInterpreter &cmdInterpreter) {
    this->commandLine = commandLine;
    //Get the index of last valid character
    lastIndex = this->commandLine.size() - 1;
    while (lastIndex >= 0 && this->commandLine[lastIndex] == ' ') { lastIndex--; }
    if (!validateCommandLine(cmdInterpreter)) {
        throw std::runtime_error("Invalid command line: " + getErrorType());
    }
}

std::string CommandLineValidator::getErrorType() {
    switch (errorCause) {

        case CMD_START:
            return "COMMAND_LINE_START";
        case FILENAME:
            return "FILENAME";
        case CMD:
            return "COMMAND";
        case JSON_PATH:
            return "JSON_PATH";
        case CHANGE_VALUE:
            return "CHANGE_VALUE";
        case CMD_TYPE:
            return "CHANGE_CMD_TYPE";
        case NOT_FINISHED:
            return "DIDNT_FINISH";
        case EMPTY:
            return "EMPTY_COMMAND_LINE";
    }
}


bool CommandLineValidator::validateCommandLine(CommandInterpreter &cmdInterpreter) {
    //Nothing was in the input
    if (commandLine.empty()) {
        errorCause = ErrorCause::EMPTY;
        return false;
    }
    //CmdStart FileName Cmd  Params [changeType depending on conditions]
    size_t index = 0;
    if (!isCmdStartValid(index)) {
        errorCause = ErrorCause::CMD_START;
        return false;
    }

    skipSpace(index);
    if (!isFilenameValid(index, cmdInterpreter)) {
        errorCause = ErrorCause::FILENAME;

        return false;
    }

    skipSpace(index);
    if (!isCommandValid(index, cmdInterpreter)) {
        errorCause = ErrorCause::CMD;

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
    std::string extensionValidator;
    for (size_t i = fileName.size() - 5; i < fileName.size(); ++i) {
        extensionValidator += fileName[i];
    }
    if (extensionValidator != ".json") {
        return false;
    }
    cmdInterpreter.setFileName(fileName);
    return true;
}

bool CommandLineValidator::isCommandValid(size_t &index, CommandInterpreter &cmdInterpreter) {
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

    if (cmdInterpreter.getCommand() == "-find") {
        //Check if there is a find-key
        cmdInterpreter.setCommandType(COMMAND_TYPE::FIND);
        if (!isPathValid(index, cmdInterpreter)) {
            return false;
        }
    } else if (cmdInterpreter.getCommand() == "-change") {
        //Check if we have path and change value
        if (!isPathValid(index, cmdInterpreter)) {
            return false;
        }
        skipSpace(index);

        if (!isChangeValueValid(index, cmdInterpreter)) {
            return false;
        }
        skipSpace(index);

        //Check if the change type is valid
        std::string changeType;
        while (index <= lastIndex) { changeType += commandLine[index++]; }
        if (changeType != "-overwrite" && changeType != "-create") {
            errorCause = ErrorCause::CMD_TYPE;

            return false;
        }
        cmdInterpreter.setCommandType(
                changeType == "-overwrite" ? COMMAND_TYPE::OVERWRITE : COMMAND_TYPE::CREATE);
    }

    //Check if we reached command_line's end
    if (!hasReachedCmdEnd(index)) {
        return false;
    }
    return true;
}

bool CommandLineValidator::isPathValid(size_t &index, CommandInterpreter &cmdInterpreter) {
    if (commandLine[index++] != '"') {
        errorCause = ErrorCause::JSON_PATH;

        return false;
    }

    std::string currParam;
    while (index != commandLine.size() && commandLine[index] != '"') {
        currParam += commandLine[index++];
    }
    if (currParam.empty()) {
        errorCause = ErrorCause::JSON_PATH;

        return false;
    }
    index++;
    cmdInterpreter.pushToParams(currParam);
    return true;
}

bool CommandLineValidator::isChangeValueValid(size_t &index, CommandInterpreter &cmdInterpreter) {
    std::string changeValue;
    while (index <= lastIndex && commandLine[index] != ' ') {
        changeValue += commandLine[index++];
    }

    cmdInterpreter.pushToParams(changeValue);
    if (changeValue[0] == '"' && changeValue[changeValue.size() - 1] == '"' ||
        changeValue[0] == '{' && changeValue[changeValue.size() - 1] == '}' ||
        changeValue[0] == '[' && changeValue[changeValue.size() - 1] == ']') {
        return true;
    }
    errorCause = ErrorCause::CHANGE_VALUE;

    return false;
}

void CommandLineValidator::skipSpace(size_t &index) {
    index++; //Skip the space
}

bool CommandLineValidator::hasReachedCmdEnd(size_t &index) {
    if (index != lastIndex + 1) {
        return false;
    }
    return true;
}


CommandLineValidator::~CommandLineValidator() = default;

