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
    std::vector<std::string> params;
    COMMAND_TYPE commandType;
public:
    CommandInterpreter();

    const std::string &getFileName() const;

    const std::string &getCommand() const;

    const std::vector<std::string> &getParams() const;

    COMMAND_TYPE getCommandType() const;

    void setFileName(const std::string &fileName);

    void setCommand(const std::string &command);

    void setParams(const std::vector<std::string> &params);

    void setCommandType(COMMAND_TYPE commandType);

private:
    bool validateCommandLine(const std::string &commandLine);

};


#endif //WEEK13_JSONPARSER_COMMANDINTERPRETER_H
