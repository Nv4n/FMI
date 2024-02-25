//
// Created by Sybatron on 2/25/2024.
//
#include <iostream>

const double LIGHT_SPEED = 299792;

struct Planet {
    char *name;
    double distanceFromSun;
    double diameter;
    double mass;

};

Planet createPlanet();

void printPlanetData(Planet planet);

double getLightTime(Planet planet);

Planet *createPlanets(size_t size);

void printPlanets(const Planet *&planets, size_t size);

void printBiggestPlanet(const Planet *&planets, size_t size);

int main() {

}

void printBiggestPlanet(const Planet *&planets, size_t size) {
    size_t bigPlanetInd = 0;
    for (int i = 1; i < size; ++i) {
        if (planets[i].diameter > planets[bigPlanetInd].diameter) {
            bigPlanetInd = i;
        }
    }
    printPlanetData(planets[bigPlanetInd]);
}

void printPlanets(const Planet *&planets, size_t size) {
    for (int i = 0; i < size; ++i) {
        printPlanetData(planets[i]);
    }
}

Planet *createPlanets(size_t size) {
    Planet *planets = new Planet[size];
    for (int i = 0; i < size; ++i) {
        planets[i] = createPlanet();
    }
    return planets;
}

double getLightTime(Planet planet) {
    return planet.distanceFromSun / LIGHT_SPEED;
}

Planet createPlanet() {
    Planet planet{};
    size_t nameSize;
    std::cout << "NameSize: ";
    std::cin >> nameSize;
    planet.name = new char[nameSize + 1];
    std::cout << "Name: ";
    std::cin.ignore();
    std::cin.getline(planet.name, nameSize);
    std::cout << "Distance from Sun: ";
    std::cin >> planet.distanceFromSun;
    std::cout << "Diameter: ";
    std::cin >> planet.diameter;
    std::cout << "Mass: ";
    std::cin >> planet.mass;
}

void printPlanetData(Planet planet) {
    std::cout << "Planet{ " << "name: " << planet.name
              << ", distance: " << planet.distanceFromSun
              << ", diameter: " << planet.diameter
              << ", mass: " << planet.mass << "}" << std::endl;
}
