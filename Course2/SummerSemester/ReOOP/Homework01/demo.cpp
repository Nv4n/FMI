#include <iostream>
#include <cstring>

//
// Created by Sybatron on 3/28/2023.
//
unsigned computeHash(const unsigned char *memory, int length) {
    unsigned hash = 0xbeaf;

    for (int c = 0; c < length; c++) {
        hash += memory[c];
        hash += hash << 10;
        hash ^= hash >> 6;
    }

    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}


void getInput() {
    //19 characters is the longest command length
    //20 to make sure there aren't any characters after last one
    char cmd[20];
    std::cin >> cmd;
    
    if (std::strcmp(cmd, "create-user") == 0) {
        std::cout << "success" << std::endl;
    } else if (std::strcmp(cmd, "remove-user") == 0) {
        std::cout << "success" << std::endl;
    } else if (std::strcmp(cmd, "send-coins") == 0) {
        std::cout << "success" << std::endl;
    } else if (std::strcmp(cmd, "verify-transactions") == 0) {
        std::cout << "success" << std::endl;
    } else if (std::strcmp(cmd, "wealthiest-users") == 0) {
        std::cout << "success" << std::endl;
    } else if (std::strcmp(cmd, "biggest-blocks") == 0) {
        std::cout << "success" << std::endl;
    } else if (std::strcmp(cmd, "exit") == 0) {
        return;
    } else {
        std::cout << "Invalid command" << std::endl;
    }
    getInput();
}

int main() {
    getInput();
}