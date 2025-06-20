#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-loop-convert"
//
// Created by Sybatron on 6/20/2025.
//

#include <iostream>
#include <fstream>
#include "stdexcept"
#include "GameConfig.h"

void GameConfig::loadFromFile(const std::string &path) {

    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open config file: " + path);
    }

    std::string line, currentLine;

    while (std::getline(file, line)) {
        trim(line);
        if (line.empty() || line[0] == '#') {
            continue;
        }

        if (line.front() == '[' && line.back() == ']') {
            currentLine = line;
            continue;
        }

        std::size_t eq = line.find('=');
        if (eq == std::string::npos) {
            continue;
        }

        std::string key = line.substr(0, eq);
        std::string value = line.substr(eq + 1);
        trim(key);
        trim(value);

        if (currentLine.empty()) {
            if (key == "max_units") {
                maxUnits = std::atoi(value.c_str());
            } else if (key == "start_living_gold") {
                startLivingGold = std::atoi(value.c_str());
            } else if (key == "start_undead_gold") {
                startUndeadGold = std::atoi(value.c_str());
            }
        } else if (currentLine == "[living_leaders]") {
            LivingSpecies species = getLivingSpecies(key);
            if (species == LivingSpecies::UNKNOWN) {
                throw std::runtime_error("Unknown living species: " + key);
            }

            int idx = static_cast<int>(species);
            if (livingSpeciesCounts[idx] >= 7) {
                throw std::runtime_error("Too many leaders for living species: " + key);
            }

            livingSpeciesCounts[idx]++;
            livingLeaders.push_back({value, species});
        } else if (currentLine == "[undead_leaders]") {
            UndeadSpecies species = getUndeadSpecies(key);
            if (species == UndeadSpecies::UNKNOWN) {
                throw std::runtime_error("Unknown undead species: " + key);
            }

            int idx = static_cast<int>(species);
            if (undeadSpeciesCounts[idx] >= 7) {
                throw std::runtime_error("Too many leaders for undead species: " + key);
            }

            undeadSpeciesCounts[idx]++;
            undeadLeaders.push_back({value, species});
        }
    }
}

void GameConfig::print() const {
    std::cout << "Max Units: " << maxUnits << std::endl;
    std::cout << "Start Living Gold: " << startLivingGold << std::endl;
    std::cout << "Start Undead Gold: " << startUndeadGold << std::endl;

    std::cout << std::endl << "Living Leaders:" << std::endl;
    for (size_t i = 0; i < livingLeaders.size(); ++i) {
        std::cout << "  " << livingLeaders[i].name << " (" << livingSpeciesToString(livingLeaders[i].specie)
                  << ")" << std::endl;
    }

    std::cout << std::endl << "Undead Leaders:" << std::endl;
    for (size_t i = 0; i < undeadLeaders.size(); ++i) {
        std::cout << "  " << undeadLeaders[i].name << " (" << undeadSpeciesToString(undeadLeaders[i].specie)
                  << ")" << std::endl;
    }
}

void GameConfig::trim(std::string &s) {

    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos) {
        s.clear();
    } else {
        s = s.substr(start, end - start + 1);
    }
}

LivingSpecies GameConfig::getLivingSpecies(const std::string &name) const {
    if (name == "Ловец на немъртви") {
        return LivingSpecies::UNDEAD_HUNTER;
    }
    if (name == "Танцуващ с остриета") {
        return LivingSpecies::BLADE_DANCER;
    }
    if (name == "Паладин") {
        return LivingSpecies::PALADIN;
    }
    return LivingSpecies::UNKNOWN;

}

UndeadSpecies GameConfig::getUndeadSpecies(const std::string &name) const {
    if (name == "Лич") {
        return UndeadSpecies::LICH;
    }
    if (name == "Повелител на ужаса") {
        return UndeadSpecies::DREAD_LORD;
    }
    if (name == "Мъртъв рицар") {
        return UndeadSpecies::DEATH_KNIGHT;
    }
    return UndeadSpecies::UNKNOWN;
}

std::string GameConfig::livingSpeciesToString(LivingSpecies s) const {
    switch (s) {
        case LivingSpecies::UNDEAD_HUNTER:
            return "Ловец на немъртви";
        case LivingSpecies::BLADE_DANCER:
            return "Танцуващ с остриета";
        case LivingSpecies::PALADIN:
            return "Паладин";
        default:
            return "Unknown";
    }
}

std::string GameConfig::undeadSpeciesToString(UndeadSpecies s) const {
    switch (s) {
        case UndeadSpecies::LICH:
            return "Лич";
        case UndeadSpecies::DREAD_LORD:
            return "Повелител на ужаса";
        case UndeadSpecies::DEATH_KNIGHT:
            return "Мъртъв рицар";
        default:
            return "Unknown";
    }
}

#pragma clang diagnostic pop