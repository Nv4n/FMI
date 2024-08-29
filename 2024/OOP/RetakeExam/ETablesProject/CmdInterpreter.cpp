//
// Created by Sybatron on 8/27/2024.
//

#include <iostream>
#include <stdexcept>
#include "CmdInterpreter.h"

CmdInterpreter::CmdInterpreter() : hasChanges(false) {}

/**
 * @brief The main method for reading commands
*/
void CmdInterpreter::getCmdLine() {
    while (true) {
        std::string line;
        std::cin >> line;
        std::vector<std::string> args = splitArguments(line);
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
 * @brief Choose command from args and executing it
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
    if (args.size() > 2) {
        throw std::invalid_argument("Too many arguments");
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
 * @param filedir File directory of the table text file
 */
void CmdInterpreter::open(std::string filedir) {
    //TODO
    std::ofstream writer(filedir);
}

/**
 * @brief Save method for current active file
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
 * @brief Save As method for saving the table to new file
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

    if (fileDir.empty() || hasChanges) {
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

std::vector<std::string> CmdInterpreter::splitArguments(const std::string &input) {
    std::vector<std::string> result;
    std::string token;
    bool inQuotes = false;

    for (size_t i = 0; i < input.size(); ++i) {
        char current = input[i];

        if (current == '"') {
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
        if (current == ' ' && !inQuotes && !token.empty()) {
            result.push_back(token);
            token.clear();
            continue;
        }
        token += current;
    }

    if (!token.empty()) {
        result.push_back(token);
    }

    return result;
}
