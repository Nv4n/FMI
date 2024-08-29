//
// Created by Sybatron on 8/27/2024.
//

#ifndef ETABLES_CMDINTERPRETER_H
#define ETABLES_CMDINTERPRETER_H

#pragma once

#include <string>
#include "Table.h"

enum class ExecutedCommand {
    CLOSE,
    SAVE,
    SAVEAS,
    OPEN,
};

class CmdInterpreter {
private:
    std::string fileDir;
    Table table;
    bool hasChanges;
public:
    CmdInterpreter();

    virtual ~CmdInterpreter() = default;

    void getCmdLine();

private:
    void open(std::string filedir);

    void save();

    void saveAs(const std::string &newFileDir);

    void close();

    std::vector<std::string> splitArguments(const std::string &input);

    ExecutedCommand runCommand(const std::vector<std::string> &args);
};


#endif //ETABLES_CMDINTERPRETER_H
