//
// Created by Sybatron on 2/25/2024.
//
#include <iostream>
#include <cmath>

struct RectCoordinates {
    double x;
    double y;
};

struct PolarCoordinates {
    double r;
    double angle;
};


PolarCoordinates toPolarCoords(RectCoordinates rectCoords);

RectCoordinates toRectCoords(PolarCoordinates polarCoordinates);

void printCoordsData(PolarCoordinates polarCoordinates);

void printCoordsData(RectCoordinates rectCoordinates);

void menu();

void menuAction(char action, unsigned int count);


int main() {
    menu();
}

PolarCoordinates toPolarCoords(RectCoordinates rectCoords) {
    PolarCoordinates result{};
    double x = rectCoords.x;
    double y = rectCoords.y;
    result.r = std::sqrt(x * x + y * y);
    result.angle = std::atan(y / x) * 180 / M_PI;
    return result;
}

RectCoordinates toRectCoords(PolarCoordinates polarCoordinates) {
    RectCoordinates result{};
    double r = polarCoordinates.r;
    double angle = polarCoordinates.angle;
    result.x = r * std::cos(angle);
    result.y = r * std::sin(angle);
    return result;
}

void printCoordsData(PolarCoordinates polarCoordinates) {
    std::cout << "PolarCoords { r: " << polarCoordinates.r
              << ", angle: " << polarCoordinates.angle << "}"
              << std::endl;
}

void printCoordsData(RectCoordinates rectCoordinates) {
    std::cout << "RectCoords { x: " << rectCoordinates.x
              << ", y: " << rectCoordinates.y << "}"
              << std::endl;
}

void menu() {
    std::cout << "Choose r(rectangular) or p(polar) coordinate system" << std::endl;
    char choice;
    std::cin >> choice;

    unsigned int count;
    std::cout << "Enter how many vectors you will enter" << std::endl;
    std::cin >> count;
    menuAction(choice, count);
}

void menuAction(char action, unsigned int count) {
    if (action == 'r') {
        RectCoordinates *vectors = new RectCoordinates[count];
        for (int i = 0; i < count; ++i) {
            vectors[i] = {};
            std::cout << "Vector" << i << "{" << std::endl;
            std::cout << "X: ";
            std::cin >> vectors[i].x;
            std::cout << "Y: ";
            std::cin >> vectors[i].y;
            std::cout << "}" << std::endl;
        }
        for (int i = 0; i < count; ++i) {
            printCoordsData(toPolarCoords(vectors[i]));
        }
        delete[] vectors;
    } else if (action == 'p') {
        PolarCoordinates *vectors = new PolarCoordinates[count];
        for (int i = 0; i < count; ++i) {
            vectors[i] = {};
            std::cout << "Vector" << i << "{" << std::endl;
            std::cout << "R: ";
            std::cin >> vectors[i].r;
            std::cout << "Angle: ";
            std::cin >> vectors[i].angle;
            std::cout << "}" << std::endl;
        }
        for (int i = 0; i < count; ++i) {
            printCoordsData(toRectCoords(vectors[i]));
        }
        delete[]vectors;
    }
}