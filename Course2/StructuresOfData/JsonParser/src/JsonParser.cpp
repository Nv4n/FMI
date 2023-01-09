//
// Created by Sybatron on 1/6/2023.
//

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
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
    for (JsonNode *&subNode: node->subNodes) {
        deleteNodes(subNode);
    }
    node->subNodes.clear();
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
    std::getline(std::cin, cmdLine, '\n');

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
                std::vector<std::string> path;
                pathInterpreter(cmdInterpreter.getParams()[0], path);
                overwrite(path, cmdInterpreter.getParams()[1]);
                saveJsonTree(cmdInterpreter.getFileName());
                break;
            }
            case CREATE: {
                std::vector<std::string> path;
                pathInterpreter(cmdInterpreter.getParams()[0], path);
                create(path, cmdInterpreter.getParams()[1]);
                saveJsonTree(cmdInterpreter.getFileName());
                break;
            }
        }
    } catch (std::exception &err) {
        std::cout << std::endl << err.what() << std::endl;
        destroy();
        return;
    } catch (...) {
        std::cout << "Unknown exception" << std::endl;
        destroy();
        return;
    }
}

#pragma region FIND_KEY

void JsonParser::find(const std::vector<std::string> &params) {
    const std::string &key = params.back();
    JsonNode *currNode = root;
    std::vector<JsonNode *> foundNodes;
    findAllNodes(key, currNode, foundNodes);
    if (foundNodes.size() == 0) {
        throw std::invalid_argument("There isn't such key in the file");
    }
    size_t choice;
    std::cout << "Choose one of the options" << std::endl
              << "1. Print all values" << std::endl
              << "2. Choose index of wanted value" << std::endl
              << "3. Save result in find.txt file" << std::endl;
    std::cin >> choice;
    std::string result;
    switch (choice) {
        case 1:
            toString(foundNodes, result);
            std::cout << result << std::endl;
            break;
        case 2: {
            std::cout << "Choose index between 0-" << foundNodes.size() - 1 << ": ";
            std::cin >> choice;
            if (!(choice >= 0 && choice <= foundNodes.size())) {
                throw std::invalid_argument("Invalid index");
            }
            nodeToString(foundNodes[choice], result);
            std::cout << result << std::endl;
            break;
        }
        case 3: {
            toString(foundNodes, result);
            std::ofstream writer("./find.txt", std::ios::out | std::ios::trunc);
            if (!writer.is_open()) {
                throw std::runtime_error("find.txt couldn't be opened");
            }
            writer << result;
            writer.close();
            std::cout << "File saved successfully" << std::endl;
            break;
        }
        default:
            throw std::invalid_argument("Invalid choice... command is terminated");
    }
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

void JsonParser::toString(std::vector<JsonNode *> &nodes, std::string &res) {
    if (nodes.size() > 1) {
        res += "[\n";
    }
    for (int i = 0; i < nodes.size(); ++i) {
        nodeToString(nodes[i], res);
        res += std::string(i + 1 < nodes.size() ? "," : "");
        res += "\n";
    }
    if (nodes.size() > 1) {
        res += "]\n";
    }
}

void JsonParser::nodeToString(JsonParser::JsonNode *&node, std::string &res, size_t spaces, bool keepKeys) {

    if (!node) {
        return;
    }
    if (node->type == JsonNodeType::VALUE) {
        if (keepKeys) {
            res += std::string(spaces + 2, ' ');
            res += "\"" + node->key + "\": ";
        } else {
            res += std::string(spaces + 2, ' ');
        }
        res += "\"" + node->value + "\"";
        return;
    }

    if (node->type == JsonNodeType::OBJECT) {
        res += std::string(spaces + 2, ' ');
        res += "\"" + node->key + "\":{\n";
        subNodesToString(node->subNodes.back(), res, node->key.size() + spaces + 4);
        res += std::string(node->key.size() + spaces + 4, ' ');
        res += "}";
    }

    if (node->type == JsonNodeType::ARRAY) {
        res += std::string(spaces + 2, ' ');
        res += "\"" + node->key + "\":[\n";
        for (int i = 0; i < node->subNodes.size(); ++i) {
            res += std::string(node->key.size() + spaces + 2, ' ');
            res += "{\n";
            subNodesToString(node->subNodes[i], res, node->key.size() + spaces + 2);
            res += std::string(node->key.size() + spaces + 2, ' ');
            res += "}";
            res += (i + 1 < node->subNodes.size() ? "," : "");
            res += "\n";
        }
        res += std::string(node->key.size() + spaces, ' ');
        res += "]";
    }
}

void JsonParser::subNodesToString(JsonParser::JsonNode *&node, std::string &res, size_t spaces) {
    if (!node) {
        return;
    }
    nodeToString(node, res, spaces, true);
    res += (node->nextNode ? "," : "");
    res += "\n";
    subNodesToString(node->nextNode, res, spaces);
}

#pragma endregion FIND_KEY


#pragma  region CHANGE

void
JsonParser::overwrite(const std::vector<std::string> &path, const std::string &changeValue) {
    JsonNode *&node = getNodeByPath(this->root, path);
    if (!node) {
        throw std::invalid_argument("You can't change nodes that don't exist");
    }

    if (node->type != JsonNodeType::VALUE) {
        std::string type;
        switch (node->type) {
            case OBJECT:
                type = "OBJECT";
                break;
            case ARRAY:
                type = "ARRAY";
                break;
        }
        throw std::runtime_error("Non-Value nodes can't be changed; Type: " + type);
    }
    for (JsonNode *&subNode: node->subNodes) {
        deleteNodes(subNode);
    }
    node->subNodes.clear();
    std::string jsonChangeValue;
    valueInterpreter(changeValue, jsonChangeValue);
    jsonChangeValue = "\"" + node->key + "\": " + jsonChangeValue + "}";
    std::istringstream reader(jsonChangeValue);
    if (!reader.good()) {
        throw std::runtime_error("Couldn't open change value in stream");
    }
    buildNodes(node, reader);
}

void JsonParser::create(const std::vector<std::string> &path, const std::string &changeValue) {
    JsonNode *&node = getNodeByPath(this->root, path);
    if (node) {
        throw std::runtime_error("You can't create node on non-empty node address");
    }
    std::string jsonChangeValue;
    valueInterpreter(changeValue, jsonChangeValue);
    jsonChangeValue = "\"" + path.back() + "\": " + jsonChangeValue + "}";
    std::istringstream reader(jsonChangeValue);
    if (!reader.good()) {
        throw std::runtime_error("Couldn't open change value in stream");
    }
    buildNodes(node, reader);
}

void JsonParser::saveJsonTree(const std::string &fileName) {
    std::ofstream writer(fileName, std::ios::out | std::ios::trunc);
    if (!writer.is_open()) {
        throw std::runtime_error("File couldn't be open");
    }

    writer << "{\n";
    saveNodes(this->root, writer);
    writer << "}";
    writer.close();
}

void JsonParser::saveNodes(JsonParser::JsonNode *&root, std::ofstream &writer) {
    JsonNode *currRoot = root;
    while (currRoot) {
        std::string nodeText;
        nodeToString(currRoot, nodeText, 0, true);
        writer << nodeText
               << std::string(currRoot->nextNode ? "," : "")
               << "\n";
        currRoot = currRoot->nextNode;
    }
}

void JsonParser::pathInterpreter(const std::string &rawPath, std::vector<std::string> &formattedPath) {
    std::string currKey;
    size_t index = 0;
    while (index < rawPath.size()) {
        if (rawPath[index] == '/') {
            if (currKey.empty()) {
                throw std::invalid_argument("Invalid path");
            }
            formattedPath.push_back(currKey);
            currKey = "";
            index++;
            continue;
        }
        currKey += rawPath[index++];
    }

    if (currKey.empty()) {
        throw std::invalid_argument("Invalid path");
    }
    formattedPath.push_back(currKey);
}

void JsonParser::valueInterpreter(const std::string &changeValue, std::string &result) {
    size_t index = 0;
    while (index != changeValue.size()) {
        switch (changeValue[index]) {
            case '{':
            case '}':
            case '[':
            case ']':
            case ',': {
                result += changeValue[index++];
                result += "\n";
                continue;
            }
        }
        if (index + 1 < changeValue.size() &&
            changeValue[index + 1] == '}') {
            result += changeValue[index++];
            result += "\n";
            continue;
        }
        result += changeValue[index++];
    }
}

JsonParser::JsonNode *&
JsonParser::getNodeByPath(JsonParser::JsonNode *&root, const std::vector<std::string> &path, size_t index) {
    if (index >= path.size()) {
        throw std::invalid_argument("Invalid path");
    }

    if (!root ||
        (index + 1 == path.size() && root->key == path.back())) {
        return root;
    }
    if (root->key != path[index]) {
        return getNodeByPath(root->nextNode, path, index);
    }

    //Root->Key == currentKey
    if (root->type == JsonNodeType::ARRAY) {
        index++;
        size_t subNodeIndex = 0;
        size_t charIndex = 0;
        while (charIndex <= path[index].size()) {
            if (path[index][charIndex] < '0' || path[index][charIndex] > '9') {
                throw std::invalid_argument("Invalid index: " + path[index]);
            }
            subNodeIndex += (path[index][charIndex++] - '0');
        }
        if (subNodeIndex >= root->subNodes.size()) {
            throw std::invalid_argument("Index is out of range");
        }

        return getNodeByPath(root->subNodes[subNodeIndex], path, index + 1);
    } else if (root->type == JsonNodeType::OBJECT) {
        return getNodeByPath(root->subNodes[0], path, index + 1);
    }

    throw std::invalid_argument("Invalid path");
}


#pragma endregion

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

void JsonParser::buildNodes(JsonParser::JsonNode *&root, std::istream &reader) {
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