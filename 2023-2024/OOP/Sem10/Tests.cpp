//
// Created by Sybatron on 5/10/2024.
//
#include <iostream>
#include <cstring>

class Base {
protected:
    int baseInt;
public:
    Base(int x) : baseInt(x) {}
};

class DerStatic : public Base {
protected:
    char pass[8];
public:
    DerStatic(const char arg[8], int x) : Base(x) {
        strcpy(pass, arg);
    }
};

class DerDynamic : public DerStatic {
    char *name;

    void free() {
        delete[] name;
    }

    void copyFrom(const DerDynamic &other) {
        int len = strlen(other.name);
        this->name = new char[len + 1];
        strcpy(this->name, other.name);
    }

public:
    DerDynamic(const char *name, const char pass[8], int x) : DerStatic(pass, x) {
        int len = strlen(name);
        this->name = new char[len + 1];
        strcpy(this->name, name);
    }

    DerDynamic(const DerDynamic &other) {
        copyFrom(other);
    }

    DerDynamic &operator=(const DerDynamic &other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }
        return *this;
    }

    ~DerDynamic() {
        free();
    }
};

int main() {
    DerDynamic d("text", "1223344", 10);
}