//
// Created by Sybatron on 1/6/2023.
//

#ifndef WEEK13_JSONPARSER_COMMANDINTERPRETER_H
#define WEEK13_JSONPARSER_COMMANDINTERPRETER_H

#include <string>
#include <vector>

#pragma once
enum COMMAND_TYPE {
    UNKNOWN = -1,
    FIND,
    OVERWRITE,
    CREATE
};

class CommandInterpreter {
private:
    std::string fileName;
    std::string command;
    std::vector<std::string> params;
    COMMAND_TYPE commandType = COMMAND_TYPE::UNKNOWN;
public:
    CommandInterpreter();

    virtual ~CommandInterpreter();

    const std::string &getFileName() const;

    const std::string &getCommand() const;

    const std::vector<std::string> &getParams() const;

    COMMAND_TYPE getCommandType() const;

    void setFileName(const std::string &fileName);

    void setCommand(const std::string &command);

    void setCommandType(COMMAND_TYPE commandType);

    void pushToParams(const std::string &param);
};


#endif //WEEK13_JSONPARSER_COMMANDINTERPRETER_H