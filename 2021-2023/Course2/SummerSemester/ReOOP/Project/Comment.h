//
// Created by Sybatron on 6/15/2023.
//

#ifndef PROJECT_SOCIALMEDIA_COMMENT_H
#define PROJECT_SOCIALMEDIA_COMMENT_H


#pragma once

class Comment {
//    автор;
//    текст на коментара;
//    оценка (цяло число със знак - сума от всички положителни и отрицателни реакции);
//    уникален идентификатор на коментара в рамките на въпроса.
private:
    size_t authorId{};
    std::string content;
    int rating;
    size_t uid;
    static size_t commentId;
public:
    Comment(const std::string &content, size_t authorId);

    virtual ~Comment();

    size_t getAuthorId() const;

    const std::string &getContent() const;

    void setContent(const std::string &_content);

    int getRating() const;

    size_t getUid() const;

private:
    void setAuthorId(size_t _authorId);
};


#endif //PROJECT_SOCIALMEDIA_COMMENT_H
