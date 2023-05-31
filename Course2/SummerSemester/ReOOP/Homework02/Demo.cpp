//
// Created by Sybatron on 5/27/2023.
//
#include <fstream>
#include "Library.h"
#include "Menu.h"

int main() {
    //TODO
    //  MAKE NOT MENU DEMO
    Library library;
    std::ifstream is("library.txt");
    if (is.is_open()) {
        is >> library;
    }
    is.close();
    Genre genre(Character::CRIME, Type::DRAMA, Audience::TEEN);
    Item *item = (new Book("THEBOOK",
                           "description",
                           132,
                           1990,
                           "Georgi",
                           "Ciela",
                           genre))->clone();

    library.addItem(item, 10);

//    Item *item2 = (new PeriodicPublication("Jargon",
//                                           "magazine",
//                                           132,
//                                           2000,
//                                           PeriodicPeriod::WEEKLY,
//                                           10))->clone();
//    library.addItem(item2, 5);
    std::ofstream os("library.txt", std::ios::trunc);
    if (os.is_open()) {
        os << library;
    }
    os.close();
//    Menu menu;
}