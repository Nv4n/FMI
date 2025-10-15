//Създайте следните:

// Стурктура Hero със следните полета:

// Name
// Division
// Combat
// Имаме следните типове 'Division':

// ASSASSIN
// MEDIC
// MAGE
// TANK
// Имаме следните типове 'Combat':

// UNKNOWN = -1
// RANGE
// MELEE
// BOTH
// Направете реализация на следните функции:
// инициализира полетата на подадения Hero
// принтира на стандартния изход информацията за подадения hero
// освобождава паметта заета от данните на Hero

#include <iostream>

enum Division {
    UNKNOWN = -1,
    ASSASSIN,
    MEDIC,
    MAGE,
    TANK,
    DIVISION_COUNT
};

enum Combat {
    UNKNOWN = -1,
    RANGE,
    MELEE,
    BOTH
};

struct Hero {
    char* name;
    Division division;
    Combat combat;
};

void initialize(Hero& hero) {
    int sizeName;
    std::cin >> sizeName;
    hero.name = new char[sizeName];

    // char input[60];
    // std::cin >> input;


    std::cin >> hero.name;

    //std::cin >> hero.division;
    //std::cin >> hero.combat;
}

void printHero(const Hero& hero) {
    std::cout << "Name: " << hero.name << std::endl;
    std::cout << "Division: ";
    switch (hero.division) {
    case Division::ASSASSIN:
        std::cout << "Assasin" << std::endl;
        break;
    case Division::MEDIC:
        std::cout << "Medic" << std::endl;
        break;
    }
}

void deleteHero(Hero& hero) {
    delete[] hero.name;
}

int main() {

}