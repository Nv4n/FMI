//
// Created by Sybatron on 5/11/2023.
//

#ifndef PROJECT_SOCIALMEDIA_TOPIC_H
#define PROJECT_SOCIALMEDIA_TOPIC_H

#pragma once

class Topic {
private:
    std::string title;
    size_t creatorId{};
    std::string description;
    size_t uid{};
    static size_t id;
public:
    Topic(const std::string &title, const std::string &description, size_t creatorId);

    virtual ~Topic();

    const std::string &getTitle() const;

    void setTitle(const std::string &_title);

    size_t getCreatorId() const;

    const std::string &getDescription() const;

    void setDescription(const std::string &_description);

    size_t getUid() const;

private:

    void setCreatorId(size_t _creatorId);

};

size_t Topic::id = 1;

#endif //PROJECT_SOCIALMEDIA_TOPIC_H
