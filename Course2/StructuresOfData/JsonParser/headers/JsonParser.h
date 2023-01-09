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
    enum JsonNodeType {
        UNKNOWN = -1,
        VALUE,
        OBJECT,
        ARRAY
    };

    struct JsonNode {
        std::string key;
        std::string value;
        JsonNode *nextNode;
        std::vector<JsonNode *> subNodes;
        JsonNodeType type = JsonNodeType::UNKNOWN;
    };
    JsonNode *root{};
public:
    JsonParser();

    JsonParser(const JsonParser &other);

    JsonParser &operator=(const JsonParser &other);

    virtual ~JsonParser();

    void readCmdLine();

private:
    //TODO
    //  Put in JsonBuilder.h
    void buildJsonTree(const std::string &fileName);

    void buildNodes(JsonNode *&root, std::ifstream &reader);

    void lineInterpreter(const std::string &line, std::string &key, std::string &value);

    bool hasOnlyThisSymbol(const std::string &line, const char searchedSymbol);

    void find(const std::vector<std::string> &params);

    void findAllNodes(const std::string &key, JsonNode *node, std::vector<JsonNode *> &result);

    void printNodes(std::vector<JsonNode *> &nodes);

    void printNode(JsonNode *&node, size_t spaces = 0);

    void printArrayNodes(JsonNode *&node, size_t spaces = 0);

    void copy(const JsonParser &other);

    void copyNodes(JsonNode *&sourceNode, JsonNode *copyNode);

    void destroy();

    void deleteNodes(JsonNode *&node);
};


#endif //WEEK13_JSONPARSER_JSONPARSER_H
