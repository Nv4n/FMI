//
// Created by Sybatron on 6/15/2023.
//
#include <string>
#include "Question.h"

size_t Question::questionId = 1;

Question::Question(const std::string &title, const std::string &content, size_t creatorId) {
    setTitle(title);
    setContent(content);
    setCreatorId(creatorId);
    uid = questionId++;
}

Question::~Question() = default;

const std::string &Question::getTitle() const {
    return title;
}

void Question::setTitle(const std::string &_title) {
    title = _title;
}

const std::string &Question::getContent() const {
    return content;
}

void Question::setContent(const std::string &_content) {
    content = _content;
}

size_t Question::getCreatorId() const {
    return creatorId;
}

void Question::setCreatorId(size_t _creatorId) {
    creatorId = _creatorId;
}

size_t Question::getUid() const {
    return uid;
}