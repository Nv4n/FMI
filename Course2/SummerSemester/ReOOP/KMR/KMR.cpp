//
// Created by Sybatron on 6/13/2023.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>

void layer7_protocol(const char *buffer, size_t size);

void layer6_protocol(const char *buffer, size_t size);

void layer5_protocol(const char *buffer, size_t size);

void layer4_protocol(const char *buffer, size_t size);

void layer3_protocol(const char *buffer, size_t size);

void layer2_protocol(const char *buffer, size_t size);

void layer1_protocol(const char *buffer, size_t size);

void printMessage(const char *buffer) {
    std::ofstream os("protocolLogs.txt", std::ios::app);
    if (!os.is_open()) {
        os.close();
        return;
    }
    std::cout << buffer << std::endl;
    os << buffer << "\n";
    os.close();
}

const char *generateMessage() {
    unsigned seed = std::time(nullptr);
    std::srand(seed);
    char *message = new char[15 * 3 + 1];
    for (int i = 0; i < 15 * 3; ++i) {
        message[i++] = (char) ('A' + std::rand() % 26);
        message[i++] = (char) ('0' + std::rand() % 10);
        message[i] = (char) ('a' + std::rand() % 26);
    }
    message[15 * 3] = '\0';
    return message;
}

int main() {
    // Разкоментирайте за ръчно въвеждане
//    char message[81];
//    std::cout << "Enter a message (up to 80 characters): ";
//    std::cin.ignore();
//    std::cin.getline(message, 80);

    //Закоментирайте за ръчно въвеждане
    const char *message = generateMessage();
    layer7_protocol(message, std::strlen(message));

    return 0;
}

void layer7_protocol(const char *buffer, size_t size) {
    const char *header = "H_LAYER_7_";
    size_t currSize = std::strlen(header) + size + 1;
    char *message = new char[currSize];
    std::strcpy(message, header);
    std::strcat(message, buffer);
    printMessage(message);
    layer6_protocol(message, std::strlen(message));
}

void layer6_protocol(const char *buffer, size_t size) {
    const char *header = "H_LAYER_6_";
    size_t currSize = std::strlen(header) + size + 1;
    char *message = new char[currSize];
    std::strcpy(message, header);
    std::strcat(message, buffer);
    printMessage(message);

    layer5_protocol(message, std::strlen(message));
}

void layer5_protocol(const char *buffer, size_t size) {
    const char *header = "H_LAYER_5_";
    size_t currSize = std::strlen(header) + size + 1;
    char *message = new char[currSize];
    std::strcpy(message, header);
    std::strcat(message, buffer);
    printMessage(message);

    layer4_protocol(message, std::strlen(message));
}

void layer4_protocol(const char *buffer, size_t size) {
    const char *header = "H_LAYER_4_";
    size_t currSize = std::strlen(header) + size + 1;
    char *message = new char[currSize];
    std::strcpy(message, header);
    std::strcat(message, buffer);
    printMessage(message);

    layer3_protocol(message, std::strlen(message));
}

void layer3_protocol(const char *buffer, size_t size) {
    const char *header = "H_LAYER_3_";
    size_t currSize = std::strlen(header) + size + 1;
    char *message = new char[currSize];
    std::strcpy(message, header);
    std::strcat(message, buffer);
    printMessage(message);

    layer2_protocol(message, std::strlen(message));
}

void layer2_protocol(const char *buffer, size_t size) {
    const char *header = "H_LAYER_2_";
    size_t currSize = std::strlen(header) + size + 1;
    char *message = new char[currSize];
    std::strcpy(message, header);
    std::strcat(message, buffer);
    printMessage(message);

    layer1_protocol(message, std::strlen(message));
}

void layer1_protocol(const char *buffer, size_t size) {
    const char *header = "H_LAYER_1_";
    size_t currSize = std::strlen(header) + size + 1;
    char *message = new char[currSize];
    std::strcpy(message, header);
    std::strcat(message, buffer);
    printMessage(message);
}