//
// Created by Sybatron on 6/15/2023.
//
#include <string>
#include "Comment.h"

size_t Comment::commentId = 1;

Comment::Comment(const std::string &content, size_t authorId) {
    setContent(content);
    setAuthorId(authorId);
    uid = commentId++;
    rating = 0;
}

Comment::~Comment() = default;

size_t Comment::getAuthorId() const {
    return authorId;
}

void Comment::setAuthorId(size_t _authorId) {
    authorId = _authorId;
}

const std::string &Comment::getContent() const {
    return content;
}

void Comment::setContent(const std::string &_content) {
    content = _content;
}

int Comment::getRating() const {
    return rating;
}


size_t Comment::getUid() const {
    return uid;
}