//
// Created by Sybatron on 6/15/2023.
//

#ifndef PROJECT_SOCIALMEDIA_QUESTION_H
#define PROJECT_SOCIALMEDIA_QUESTION_H
#pragma once


class Question {
private:
    std::string title;
    std::string content;
    size_t creatorId{};
    size_t uid{};
    static size_t id;
public:
    Question(const std::string &title, const std::string &content, size_t creatorId);

    virtual ~Question();

    const std::string &getTitle() const;

    void setTitle(const std::string &_title);

    const std::string &getContent() const;

    void setContent(const std::string &_content);

    size_t getCreatorId() const;

    size_t getUid() const;

private:
    void setCreatorId(size_t _creatorId);
};

size_t Question::id = 1;


#endif //PROJECT_SOCIALMEDIA_QUESTION_H
