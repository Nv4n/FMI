//
// Created by Sybatron on 8/27/2024.
//

#include <iostream>
#include <stdexcept>
#include "CmdInterpreter.h"
#include "CellValueInterpreter.h"

CmdInterpreter::CmdInterpreter() : hasChanges(false) {}

/**
 * @brief The main method for reading commands
*/
void CmdInterpreter::getCmdLine() {
    while (true) {
        std::string line;
        std::cin >> line;
        std::vector<std::string> args = splitCmdArguments(line);
        try {
            ExecutedCommand cmdType = runCommand(args);
            if (cmdType == ExecutedCommand::CLOSE) {
                return;
            }
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

/**
 * @brief Method for choosing command from the args and executing it
 *
 * @param args Arguments from the command line
 *
 * @return ExecutedCommand The command that was executed
 * used for determining end of program
 *
 * @throws invalid_argument When there are no or too many arguments
 *
 * @see open(), saveas(), save(), close()
 */
ExecutedCommand CmdInterpreter::runCommand(const std::vector<std::string> &args) {
    if (args.empty()) {
        throw std::invalid_argument("Can't enter empty command");
    }

    if (args[0] == "save") {
        if (args.size() != 1) {
            throw std::invalid_argument("Too many arguments");
        }
        save();
        return ExecutedCommand::SAVE;
    }
    if (args[0] == "close") {
        if (args.size() != 1) {
            throw std::invalid_argument("Too many arguments");
        }
        close();
        return ExecutedCommand::CLOSE;
    }
    if (args[0] == "saveas") {
        if (args.size() > 2) {
            throw std::invalid_argument("Too many arguments");
        }
        saveAs(args[1]);
        return ExecutedCommand::SAVEAS;
    }
    if (args[0] == "open") {
        if (args.size() > 2) {
            throw std::invalid_argument("Too many arguments");
        }
        open(args[1]);
        return ExecutedCommand::OPEN;
    }

    throw std::invalid_argument("Unrecognized command");
}

/**
 * @brief Command for opening and reading the table
 * @param fileDir File directory of the table text file
 */
void CmdInterpreter::open(const std::string &fileDir) {
    //TODO Read table file
    std::ifstream reader(fileDir);
    if (!reader.is_open()) {
        throw std::runtime_error("file directory can't be opened");
    }
    std::string line;
    while (!reader.eof()) {
        reader >> line;
        std::vector<std::string> tableRowStrings = splitTableRow(line);
        Row tableRow;
        for (size_t i = 0; i < tableRowStrings.size(); ++i) {
            Optional<Cell> curr = CellValueInterpreter::convertToCell(tableRowStrings[i]);
            Optional<Cell> opt = curr;
            tableRow.push_back();
        }
    }
}

/**
 * @brief Command for saving to current active file
 * @throws logic_error When filedir is empty (haven't opened file at least one time)
 * @throws runtime_error When file directory can't be opened
 */
void CmdInterpreter::save() {
    if (fileDir.empty()) {
        throw std::logic_error("file directory is empty, need to open file once");
    }

    std::ofstream writer(fileDir);
    if (!writer.is_open()) {
        throw std::runtime_error("file directory can't be opened");
    }
    writer << table;
}

/**
 * @brief Command for saving the table to new file
 *
 * @param newFileDir String parameter with file directory
 *
 * @throws runtime_error When file directory can't be opened
 */
void CmdInterpreter::saveAs(const std::string &newFileDir) {
    std::ofstream writer(newFileDir);
    if (!writer.is_open()) {
        throw std::runtime_error("file directory can't be opened");
    }
    writer << table;
}

/**
 * @brief Command for ending the program and saving any changes to the table
 *
 * @throws invalid_argument When it doesn't get correct Y/N answer
 *
 * @see save() for the save functionality
 */
void CmdInterpreter::close() {

    if (fileDir.empty() || !hasChanges) {
        return;
    }

    std::cout << "Do you want to save your changes [Y/N]" << std::endl;
    std::string answer;
    std::cin >> answer;
    if (answer == "y" || answer == "Y" || answer == "1") {
        save();
        return;
    }
    if (answer == "n" || answer == "N" || answer == "0") {
        return;
    }

    throw std::invalid_argument("Invalid argument for close");
}

/**
 *
 * @param cmd Command line
 * @return vector of all command arguments
 */
std::vector<std::string> CmdInterpreter::splitCmdArguments(const std::string &cmd) {
    std::vector<std::string> result;
    std::string token;
    bool inQuotes = false;
//TODO " breaks all the time
    for (size_t i = 0; i < cmd.size(); ++i) {
        if (cmd[i] == '\\' && i + 1 < cmd.size()) {
            if (!inQuotes) {
                return {};
            }
            if (cmd[i + 1] != '\\' && cmd[i + 1] != '"') {
                return {};
            }
            token += cmd[i];
            i++;
            token += cmd[i];
            continue;
        }

        if (cmd[i] == '"') {
            inQuotes = !inQuotes;

            if (!inQuotes && token.empty()) {
                return {};
            }
            if (!inQuotes) {
                result.push_back(token);
                token.clear();
            }
            continue;
        }

        if (cmd[i] == ' ' && !inQuotes && !token.empty()) {
            result.push_back(token);
            token.clear();
            continue;
        }
        token += cmd[i];
    }

    if (!token.empty()) {
        result.push_back(token);
    }

    return result;
}

/**
 *
 * @param input Table row in string form
 * @return Cell values as strings
 */
std::vector<std::string> CmdInterpreter::splitTableRow(const std::string &input) {
    std::vector<std::string> result;
    std::string current;
    bool inQuotes = false;

    for (size_t ind = 0; ind < input.size(); ++ind) {

        if (input[ind] == '\\' && ind + 1 < input.size() && (input[ind + 1] == '"' || input[ind + 1] == '\\')) {
            current += input[ind];
            current += input[++ind];
        } else if (input[ind] == '"') {
            inQuotes = !inQuotes;
        } else if (input[ind] == ',' && !inQuotes) {
            result.push_back(current);
            current.clear();
        } else {
            current += input[ind];
        }
    }

    result.push_back(current);

    return result;
}
