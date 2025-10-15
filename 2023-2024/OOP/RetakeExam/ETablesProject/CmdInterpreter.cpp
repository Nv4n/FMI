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
        std::getline(std::cin, line);
        std::vector<std::string> args(splitCmdArguments(line));

        try {
            ExecutedCommand cmdType = runCommand(args);
            if (cmdType == ExecutedCommand::CLOSE) {
                return;
            }
            if (cmdType == ExecutedCommand::EDIT) {
                hasChanges = true;
            }
            std::cout << "Operation successful!" << std::endl;
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
 * @throws runtime_error
 *
 * @see open(), saveas(), save(), close(), print(), edit()
 */
ExecutedCommand CmdInterpreter::runCommand(const std::vector<std::string> &args) {
    if (args.empty()) {
        throw std::invalid_argument("Can't enter empty command");
    }

    if (args[0] == "save") {
        if (args.size() != 1) {
            throw std::invalid_argument("Wrong format! save");
        }
        save();
        return ExecutedCommand::SAVE;
    }
    if (args[0] == "close") {
        if (args.size() != 1) {
            throw std::invalid_argument("Wrong format! close");
        }
        close();
        return ExecutedCommand::CLOSE;
    }
    if (args[0] == "saveas") {
        if (args.size() != 2) {
            throw std::invalid_argument("Wrong format! saveas \"filedir\"");
        }
        saveAs(args[1]);
        return ExecutedCommand::SAVEAS;
    }
    if (args[0] == "open") {
        if (args.size() != 2) {
            throw std::invalid_argument("Wrong format! open \"filedir\"");
        }
        open(args[1]);
        return ExecutedCommand::OPEN;
    }
    if (args[0] == "print") {
        if (args.size() != 1) {
            throw std::invalid_argument("Wrong format! print");
        }
        print();
        return ExecutedCommand::PRINT;
    }
    if (args[0] == "edit") {
        if (args.size() != 4) {
            throw std::invalid_argument("Wrong format! edit row col \"new value\"");
        }
        edit(args);
        return ExecutedCommand::EDIT;
    }

    throw std::invalid_argument("Unrecognized command");
}

/**
 * @brief Command for opening and reading the table
 * @param fileDir File directory of the table text file
 * @see splitTableRow(), CellValueInterpreter::convertToCell()
 * @throws runtime_error When can't open file directory
 * @throws invalid_argument When catches Invalid Cell Value
 */
void CmdInterpreter::open(const std::string &fileDir) {
    std::ifstream reader(fileDir);
    if (!reader.is_open()) {
        throw std::runtime_error("file directory can't be opened");
    }
    table.reset();
    std::string line;
    size_t row = 1;
    while (!reader.eof()) {
        std::getline(reader, line);

        if (line.back() == '\r') {
            line.pop_back();
        }
        std::vector<std::string> tableRowStrings = splitTableRow(line);
        Row tableRow;
        for (size_t i = 0; i < tableRowStrings.size(); ++i) {
            try {
                Cell curr = CellValueInterpreter::convertToCell(tableRowStrings[i]);
                tableRow.push_back(curr);
            } catch (std::invalid_argument &e) {
                std::string expandedException = e.what();
                expandedException += ": R" + std::to_string(row) + "C" + std::to_string(i + 1);

                tableRowStrings.clear();
                tableRow.clear();
                line.clear();
                table.reset();
                reader.close();
                throw std::invalid_argument(expandedException);
            }
        }
        table.addRow(tableRow);
        row++;
    }
    this->fileDir = fileDir;
    reader.close();
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
    writer.close();
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
    writer.close();
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
 * @brief Prints the table on terminal
 */
void CmdInterpreter::print() {
    std::cout << table;
}

/**
 *
 * @param args
 */
void CmdInterpreter::edit(const std::vector<std::string> &args) {
    if (!CellValueInterpreter::isInteger(args[1])) {
        throw std::invalid_argument("Row is not an integer");
    }
    if (!CellValueInterpreter::isInteger(args[2])) {
        throw std::invalid_argument("Col is not an integer");
    }

    Cell newCell = CellValueInterpreter::convertToCell(args[3]);
    Coordinates coords{std::stoul(args[1]), std::stoul(args[2])};
    table.editCell(coords, newCell);
}


/**
 * @brief Split command line into arguments
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
 * @brief Split table row into string values
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
            current += input[ind];
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