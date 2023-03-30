//
// Created by Sybatron on 10/3/2022.
//

#ifndef TASK02POLYMORPHISM_HERO_H
#define TASK02POLYMORPHISM_HERO_H
#define pragma once

class Hero {
protected:
    char *name;
    int health;

public:
    Hero(int _health = 100) {
        name = new char[8];
        std::strcpy(name, "Unknown");
        health = _health;
    }

    Hero(const char *name, size_t health) : health(health) {
        name = new char[std::strlen(name) + 1];
        std::strcpy(this->name, name);
    }

    Hero(const Hero &other) {
        copy(other);
    }

    Hero &operator=(const Hero &other) {
        if (this != &other) {
            destroy();
            copy(other);
        }

        return *this;
    }

    virtual ~Hero() {
        destroy();
    }

    virtual Hero *clone() const = 0;

    void setHealth(int _health) {
        health = _health;
    };

    int getHealth() const {
        return health;
    }

    virtual void getInfo() {
        std::cout << "--" << name << "--" << std::endl;
        std::cout << "Health: " << health << std::endl;
    };

    virtual void attack(Hero *enemy) = 0;

protected:
    virtual void copy(const Hero &other) {
        name = new char[std::strlen(other.name) + 1];
        std::strcpy(name, other.name);
        health = other.health;
    }

private:
    void destroy() {
        if (name != nullptr) {
            delete[] name;
        }
    }
};

#endif //TASK02POLYMORPHISM_HERO_H
