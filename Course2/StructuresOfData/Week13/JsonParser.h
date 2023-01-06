//
// Created by Sybatron on 1/6/2023.
//

#ifndef WEEK13_JSONPARSER_JSONPARSER_H
#define WEEK13_JSONPARSER_JSONPARSER_H

#pragma once
struct JsonNode {
    std::string value;
    JsonNode *nextNode;
    JsonNode *subNode;
};

class JsonParser {
private:
    JsonNode *root;
    std::string jsonFileName;
public:
    JsonParser();

    JsonParser(const JsonParser &other);

    JsonParser &operator=(const JsonParser &other);

    virtual ~JsonParser();

private:
    void copy(const JsonParser &other);

    void copyNodes(JsonNode *&sourceNode, JsonNode *copyNode);

    void destroy();

    void deleteNodes(JsonNode *&node);

};


#endif //WEEK13_JSONPARSER_JSONPARSER_H
