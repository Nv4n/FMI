//
// Created by Sybatron on 1/6/2023.
//


#include "JsonParser/headers/CommandInterpreter.h"

CommandInterpreter::CommandInterpreter() = default;

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

void CommandInterpreter::setCommandType(COMMAND_TYPE commandType) {
    CommandInterpreter::commandType = commandType;
}

void CommandInterpreter::pushToParams(const std::string &param) {
    params.push_back(param);
}

CommandInterpreter::~CommandInterpreter() = default;