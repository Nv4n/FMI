//
// Created by Sybatron on 1/6/2023.
//

#include <string>
#include "JsonParser/headers/JsonParser.h"

JsonParser::JsonParser() {

}

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
    if (!node) {
        return;
    }
    deleteNodes(node->nextNode);
    deleteNodes(node->subNode);
    JsonNode *temp = node;
    node = nullptr;
    delete node;
}

void JsonParser::copy(const JsonParser &other) {
    copyNodes(root, other.root);
}

void JsonParser::copyNodes(JsonNode *&sourceNode, JsonNode *copyNode) {
    if (!copyNode) {
        return;
    }
    sourceNode = new JsonNode{std::string(copyNode->value)};
    copyNodes(sourceNode->subNode, copyNode->subNode);
    copyNodes(sourceNode->nextNode, copyNode->nextNode);
}
