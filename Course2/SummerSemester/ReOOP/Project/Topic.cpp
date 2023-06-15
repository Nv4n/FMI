//
// Created by Sybatron on 5/11/2023.
//
#include <string>
#include "Topic.h"

size_t Topic::topicId = 1;

Topic::Topic(const std::string &title, const std::string &description, size_t creatorId) {
    setTitle(title);
    setDescription(description);
    setCreatorId(creatorId);
    uid = topicId++;
}

Topic::~Topic() = default;

const std::string &Topic::getTitle() const {
    return title;
}

void Topic::setTitle(const std::string &_title) {
    Topic::title = _title;
}

size_t Topic::getCreatorId() const {
    return creatorId;
}

void Topic::setCreatorId(size_t _creatorId) {
    Topic::creatorId = _creatorId;
}

const std::string &Topic::getDescription() const {
    return description;
}

void Topic::setDescription(const std::string &_description) {
    Topic::description = _description;
}

size_t Topic::getUid() const {
    return uid;
}



