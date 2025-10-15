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
    PRINT,
    EDIT,
};

/**
 * @brief Class for entering and executing commands
 *
 * @var fileDir The directory of the table text file
 * @var table The storage variable of the table data
 * @var hasChanges Flag variable if changes were made
 */
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
    void open(const std::string &fileDir);

    void save();

    void saveAs(const std::string &newFileDir);

    void close();

    void print();

    void edit(const std::vector<std::string> &args);

    std::vector<std::string> splitCmdArguments(const std::string &cmd);

    std::vector<std::string> splitTableRow(const std::string &input);

    ExecutedCommand runCommand(const std::vector<std::string> &args);
};


#endif //ETABLES_CMDINTERPRETER_H
