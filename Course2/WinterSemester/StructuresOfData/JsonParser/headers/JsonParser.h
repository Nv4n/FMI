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
#pragma region BUILD_JSON

    void buildJsonTree(const std::string &fileName);

    void buildNodes(JsonNode *&root, std::istream &reader);

    void lineInterpreter(const std::string &line, std::string &key, std::string &value);

    bool hasOnlyThisSymbol(const std::string &line, char searchedSymbol);

#pragma endregion

#pragma region FIND_KEY

    void find(const std::vector<std::string> &params);

    void findAllNodes(const std::string &key, JsonNode *node, std::vector<JsonNode *> &result);

    void toString(std::vector<JsonNode *> &nodes, std::string &res);

    void nodeToString(JsonNode *&node, std::string &res, size_t spaces = 0, bool keepKeys = false);

    void subNodesToString(JsonNode *&node, std::string &res, size_t spaces = 0);

#pragma endregion

#pragma region CHANGE

    void
    overwrite(const std::vector<std::string> &path, const std::string &changeValue);

    void
    create(const std::vector<std::string> &path, const std::string &changeValue);

    void saveJsonTree(const std::string &fileName);

    void saveNodes(JsonNode *&root, std::ofstream &writer);

    void pathInterpreter(const std::string &rawPath, std::vector<std::string> &formattedPath);

    void valueInterpreter(const std::string &changeValue, std::string &result);

    JsonNode *&getNodeByPath(JsonNode *&root, const std::vector<std::string> &path, size_t index = 0);

#pragma endregion

    void copy(const JsonParser &other);

    void copyNodes(JsonNode *&sourceNode, JsonNode *copyNode);

    void destroy();

    void deleteNodes(JsonNode *&node);
};


#endif //WEEK13_JSONPARSER_JSONPARSER_H