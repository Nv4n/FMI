// P02-Buildings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Buidling{
    char* buildName;
};

int main()
{
    std::cout << "Hello World!\n";
}

    //име, тип (изброимо множество), списък представляващ работници,
  // местоположение и височина


// Планираме да работим на строежи, като за целта ще реализираме база данни. За
// целта какви структури ще ни бъдат нужни? Един строеж ще се характеризира със
// следната информация: име, тип (изброимо множество), списък представляващ работници,
// местоположение и височина. Един работник ще се характеризира със следната информация:
// име, списък представляващ рейтинги от минали работодатели, ЕГН и пол (изброимо множество).
// Определете кои са правилните типове за полетата на тази структура. Напишете функция, 
// която инициализира структура от този тип. 
// Напишете функция, която отпечатва информация за всеки работник.
// Напишете функция, която за конкретен работник изкарва на стандартния изход какъв е
// неговият среден рейтинг.
// Напишете функция, която намира работника с най-висок рейтинг.


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
#include <cstring>
enum Division {
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

    char input[60];
    std::cin >> input;

    if (strcmp(input, "RANGE") == 0) {
        hero.combat = RANGE;
    }
    //...


    std::cin >> hero.name;

    std::cin >> hero.division;
    std::cin >> hero.combat;
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
    //...
}

void deleteHero(Hero& hero) {
    delete[] hero.name;
}

const int MAX_WORKERS = 3;

struct Worker {
    char* workerName;
    char egn[10];
    size_t ratingCount;
    double* rating;
    Gender gender;

    void init()
    {
        int size;
        std::cin >> size;
        workerName = new char[size];
        std::cin >> egn;
        std::cin >> ratingCount;
        rating = new double[ratingCount];
        if (strcmp(input, "MALE") == 0) {
            gender = MALE;
        }
        //..
    }
    double averageRating() {
        double avgSum = 0;

        for (size_t i = 0; i < ratingCount; ++i)
        {
            avgSum += this.rating[i];
        }


        return avgSum / ratingCount;
    }
};

struct Building {
    char* buildName;
    BuildType type;
    size_t height;
    Location location;
    Worker workersList[MAX_WORKERS];
};

struct Location {
    double x;
    double y;
};
enum BuildType {
    UNKNOWN = -1,
    HOUSE,
    HOTEL,
    OFFICE
};
enum Gender {
    MALE,
    FEMALE
};

void initBuilding(Building& building) {
    int nameSize;
    std::cin >> nameSize;
    building.buildname = new char[nameSize];

    std::cin >> building.location.x >> building.location.y;

    for (size_t i = 0; i < MAX_WORKERS; ++i)
    {
        building.workerslist[i].init();
    }
}


int main()
{

    Worker w;
    w.init();

    Worker* w2 = new Worker;
    w2->init();

    return 0;
}
// Планираме да работим на строежи, като за целта ще реализираме база данни. За
// целта какви структури ще ни бъдат нужни? Един строеж ще се характеризира със
// следната информация: име, тип (изброимо множество), списък представляващ работници,
// местоположение и височина. Един работник ще се характеризира със следната информация:
// име, списък представляващ рейтинги от минали работодатели, ЕГН и пол (изброимо множество).
// Определете кои са правилните типове за полетата на тази структура. Напишете функция, 
// която инициализира структура от този тип. 
// Напишете функция, която отпечатва информация за всеки работник.
// Напишете функция, която за конкретен работник изкарва на стандартния изход какъв е
// неговият среден рейтинг.
// Напишете функция, която намира работника с най-висок рейтинг.




































