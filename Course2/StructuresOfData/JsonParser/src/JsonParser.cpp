//
// Created by Sybatron on 1/6/2023.
//

#include <string>
#include <iostream>
#include <fstream>
#include "JsonParser/headers/JsonParser.h"
#include "JsonParser/headers/CommandLineValidator.h"
#include "JsonParser/headers/CommandInterpreter.h"

JsonParser::JsonParser() = default;

JsonParser::~JsonParser() {
    destroy();
}

JsonParser::JsonParser(const JsonParser &other) {
    copy(other);
}

JsonParser &JsonParser::operator=(const JsonParser &other) {
    if (this != &other) {
        destroy();
        copy(other);
    }

    return *this;
}

void JsonParser::destroy() {
    if (!root) {
        deleteNodes(root);
    }
}

void JsonParser::deleteNodes(JsonNode *&node) {
    if (node == nullptr) {
        return;
    }
    deleteNodes(node->nextNode);
    for (JsonNode *subNode: node->subNodes) {
        deleteNodes(subNode);
    }
    JsonNode *temp = node;
    node = nullptr;
    delete temp;
}

void JsonParser::copy(const JsonParser &other) {
    copyNodes(root, other.root);
}

void JsonParser::copyNodes(JsonNode *&sourceNode, JsonNode *copyNode) {
    if (!copyNode) {
        return;
    }
    //Change value only if there is one
    sourceNode = !copyNode->value.empty()
                 ? new JsonNode{std::string(copyNode->value)}
                 : new JsonNode{""};
    //Add all sub nodes if there are any
    if (!copyNode->subNodes.empty()) {
        for (JsonNode *subNode: copyNode->subNodes) {
            JsonNode *tempNode;
            copyNodes(tempNode, subNode);
            sourceNode->subNodes.push_back(tempNode);
        }
    }
    copyNodes(sourceNode->nextNode, copyNode->nextNode);
}

void JsonParser::readCmdLine() {
    std::string cmdLine;
    std::getline(std::cin, cmdLine);

    CommandLineValidator cmdValidator;
    CommandInterpreter cmdInterpreter;
    try {
        cmdValidator.validate(cmdLine, cmdInterpreter);
        buildJsonTree(cmdInterpreter.getFileName());

        switch (cmdInterpreter.getCommandType()) {
            case FIND: {
                std::string key = cmdInterpreter.getParams().back();
                find(cmdInterpreter.getParams());
                break;
            }
            case OVERWRITE: {
                break;
            }
            case CREATE: {
                break;
            }
        }
    } catch (std::runtime_error &err) {
        std::cout << std::endl << err.what() << std::endl;
        destroy();
        return;
    }


}

#pragma region FIND_KEY

void JsonParser::find(const std::vector<std::string> &params) {
    const std::string &key = params.back();
    JsonNode *currNode = root;
    std::vector<JsonNode *> result;
    findAllNodes(key, currNode, result);
    printNodes(result);
}

void JsonParser::findAllNodes(const std::string &key,
                              JsonParser::JsonNode *node,
                              std::vector<JsonNode *> &result) {
    if (!node) {
        return;
    }
    if (node->key == key) {
        result.push_back(node);
    }
    for (JsonNode *subNode: node->subNodes) {
        findAllNodes(key, subNode, result);
    }

    findAllNodes(key, node->nextNode, result);
}

void JsonParser::printNodes(std::vector<JsonNode *> &nodes) {
    if (nodes.size() > 1) {
        std::cout << "[" << std::endl;
    }
    for (int i = 0; i < nodes.size(); ++i) {
        printNode(nodes[i]);
        std::cout << (i + 1 < nodes.size() ? "," : "") << std::endl;
    }
    if (nodes.size() > 1) {
        std::cout << "]" << std::endl;
    }
}

void JsonParser::printNode(JsonParser::JsonNode *&node, size_t spaces) {
    //TODO
    // ADD SAVE
    // ADD CHOOSE INDEX
    if (!node) {
        return;
    }
    if (node->type == JsonNodeType::VALUE) {
        std::cout << std::string(spaces + 2, ' ') << "\"" << node->value << "\"";
        return;
    }

    if (node->type == JsonNodeType::OBJECT) {
        std::cout << "\"" << node->key << "\":{" << std::endl;
        printArrayNodes(node->subNodes.back());
        std::cout << std::string(node->key.size() + 2 + spaces, ' ') << "}" << std::endl;
    }

    if (node->type == JsonNodeType::ARRAY) {
        std::cout << "\"" << node->key << "\":[" << std::endl;
        for (int i = 0; i < node->subNodes.size(); ++i) {
            std::cout << "\"" << node->key << "\":{" << std::endl;
            printArrayNodes(node->subNodes[i], node->key.size() + 2 + spaces);
            std::cout << std::string(node->key.size() + 2 + spaces, ' ') << "}" << std::endl;
        }
        std::cout << "]" << std::endl;
    }
}

void JsonParser::printArrayNodes(JsonParser::JsonNode *&node, size_t spaces) {
    if (!node) {
        return;
    }
    std::cout << std::string(spaces + 2, ' ') << "\t";
    std::cout << "\t\"" << node->key << "\": \"" << node->value << "\"";
    std::cout << (node->nextNode ? "," : "") << std::endl;
    printArrayNodes(node->nextNode, spaces);
}

#pragma endregion FIND_KEY

#pragma region BUILD_JSON

void JsonParser::buildJsonTree(const std::string &fileName) {
    std::ifstream reader(fileName);
    if (!reader.is_open()) {
        throw std::runtime_error("File couldn't be open");
    }
    std::string firstLine;
    std::getline(reader, firstLine);
    if (!hasOnlyThisSymbol(firstLine, '{')) {
        throw std::runtime_error("File is not in the right format");
    }
    destroy();
    buildNodes(this->root, reader);
    reader.close();
}

void JsonParser::buildNodes(JsonParser::JsonNode *&root, std::ifstream &reader) {
    if (!root) {
        root = new JsonNode{"", ""};
    }
    JsonNode *currRoot = root;
    while (!reader.eof()) {
        std::string line;
        std::getline(reader, line);
        //End of object

        std::string key;
        std::string value;
        lineInterpreter(line, key, value);

        currRoot->key = key;
        if (value == "[") {
            currRoot->type = JsonNodeType::ARRAY;
            while (!reader.eof()) {
                std::getline(reader, line);
                if (hasOnlyThisSymbol(line, ']')) {
                    break;
                }
                if (!hasOnlyThisSymbol(line, '{')) {
                    throw std::runtime_error("File is not in the right format");
                }
                JsonNode *tempNode = new JsonNode{};
                buildNodes(tempNode, reader);
                currRoot->subNodes.push_back(tempNode);
            }
        } else if (value == "{") {
            currRoot->type = JsonNodeType::OBJECT;
            JsonNode *tempNode = new JsonNode{};
            buildNodes(tempNode, reader);
            currRoot->subNodes.push_back(tempNode);
        } else {
            currRoot->type = JsonNodeType::VALUE;
            currRoot->value = value;
        }

        if (currRoot->type == JsonNodeType::UNKNOWN) {
            throw std::runtime_error("File is not in the right format");
        }

        //If next line is the end of the object
        std::streampos pos = reader.tellg();
        std::getline(reader, line);
        if (hasOnlyThisSymbol(line, '}')) {
            return;
        }
        if (!currRoot->nextNode) {
            currRoot->nextNode = new JsonNode{};
        }
        currRoot = currRoot->nextNode;
        reader.seekg(pos, std::ios::beg);
    }
}

void JsonParser::lineInterpreter(const std::string &line, std::string &key, std::string &value) {
    //If its beginning of object in array
    if (hasOnlyThisSymbol(line, '{')) {
        value = "{";
        return;
    }

    size_t index = 0;
    while (index < line.size() && line[index++] != '"') {}
    while (index < line.size() && line[index] != '"') {
        key += line[index++];
    }
    while (index < line.size() && line[index] != ':') {
        index++;
        if (index == line.size()) {
            throw std::runtime_error("File is not in the right format");
        }
    }
    while (index < line.size() &&
           line[index] != '"' &&
           line[index] != '[' &&
           line[index] != '{') {
        index++;
    }
    if (index < line.size() && line[index] != '"') {
        value = line[index];
    } else {
        index++;//skip the first
        while (index < line.size() && line[index] != '"') {
            value += line[index++];
        }
    }
}

bool JsonParser::hasOnlyThisSymbol(const std::string &line, const char searchedSymbol) {
    size_t index = 0;
    if (line[index] == ' ') {
        while (line[index] == ' ') { index++; }
    }
    if (line[index] == searchedSymbol) {
        return true;
    }
    return false;
}


#pragma endregion