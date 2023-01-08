//
// Created by Sybatron on 1/6/2023.
//

#ifndef WEEK13_JSONPARSER_JSONPARSER_H
#define WEEK13_JSONPARSER_JSONPARSER_H

#include <vector>
#include <ostream>

#pragma once

class JsonParser {
private:
    struct JsonNode {
        std::string key;
        std::string value;
        JsonNode *nextNode;
        std::vector<JsonNode *> subNodes;
    };
    JsonNode *root{};
public:
    JsonParser();

    JsonParser(const JsonParser &other);

    JsonParser &operator=(const JsonParser &other);

    virtual ~JsonParser();

    void readCmdLine();

private:

    void buildJsonTree(const std::string &fileName);

    void buildNode(JsonNode *&root, std::ifstream &reader);

    void lineInterpreter(const std::string &line, std::string &key, std::string &value);

    bool hasOnlyThisSymbol(const std::string &line, const char searchedSymbol);

    void copy(const JsonParser &other);

    void copyNodes(JsonNode *&sourceNode, JsonNode *copyNode);

    void destroy();

    void deleteNodes(JsonNode *&node);
};


#endif //WEEK13_JSONPARSER_JSONPARSER_H
