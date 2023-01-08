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
    } catch (std::runtime_error &err) {
        std::cout << err.what() << std::endl;
        return;
    }
    try {
        buildJsonTree(cmdInterpreter.getFileName());
    } catch (std::runtime_error &err) {
        std::cout << err.what() << std::endl;
        destroy();
        return;
    }
}

void JsonParser::buildJsonTree(const std::string &fileName) {
    std::ifstream reader(fileName);
    if (!reader.is_open()) {
        throw std::runtime_error("File couldn't be open");
    }
    std::string firstLine;
    std::getline(reader, firstLine);
    if (!hasOnlyThisSymbol(firstLine, '{')) {
        throw std::runtime_error("File is not in json format");
    }
    destroy();
    buildNode(this->root, reader);
    reader.close();
}

void JsonParser::buildNode(JsonParser::JsonNode *&root, std::ifstream &reader) {
    //Reached the end
    if (reader.eof()) {
        throw std::runtime_error("File is not in json format");
    }
    std::string line;
    std::getline(reader, line);
    //End of object
    if (hasOnlyThisSymbol(line, '}')) {
        return;
    }

    std::string key;
    std::string value;
    lineInterpreter(line, key, value);

    if (value.empty()) {
        throw std::runtime_error("File is not in json format");
    }
    if (value == "[") {
        value = "";
        while (!reader.eof()) {
            std::getline(reader, line);
            if (hasOnlyThisSymbol(line, ']')) {
                break;
            }
            if (!hasOnlyThisSymbol(line, '{')) {
                throw std::runtime_error("File is not in json format");
            }
            auto *tempNode = new JsonNode{"", ""};
            //FIXME
            root->subNodes.push_back(tempNode);
            buildNode(root->subNodes.back(), reader);
        }
//TODO
//  NEED NODE TYPE ENUM
    } else if (value == "{") {
        value = "";
        std::getline(reader, line);
        if (!hasOnlyThisSymbol(line, '{')) {
            throw std::runtime_error("File is not in json format");
        }
        root->subNodes.push_back(new JsonNode{});
        buildNode(root->subNodes.back(), reader);
    } else if (root == nullptr) {
        root = new JsonNode{key, value};
    } else {
        root->key = key;
        root->value = value;
    }
    buildNode(root->nextNode, reader);
}

void JsonParser::lineInterpreter(const std::string &line, std::string &key, std::string &value) {
    size_t index = 0;
    while (index < line.size() && line[index++] != '"') {}
    while (index < line.size() && line[index] != '"') {
        key += line[index++];
    }
    if (key.empty()) {
        throw std::runtime_error("File is not in json format");
    }
    while (index < line.size() && line[index] != ':') {
        index++;
        if (index == line.size()) {
            throw std::runtime_error("File is not in json format");
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
