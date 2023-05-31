//
// Created by Sybatron on 5/27/2023.
//
#include <fstream>
#include "Library.h"
#include "Menu.h"


bool isEmpty(std::ifstream &isFile) {
    return isFile.peek() == std::ifstream::traits_type::eof();
}

int main() {
    //TODO
    //  MAKE NOT MENU DEMO
    std::cout << "Demo Library" << std::endl;
    Library library;
//    std::ifstream is("library.txt", std::ios::in);
//    if (is.is_open() && !isEmpty(is)) {
//        is >> library;
//    }
//    is.close();
    Genre genre(Character::CRIME, Type::DRAMA, Audience::TEEN);
    Book book("THEBOOK",
              "description",
              132,
              1990,
              "Georgi",
              "Ciela",
              genre);
    Item *item = book.clone();

    library.addItem(item, 10);
    PeriodicPublication publication("Jargon",
                                    "magazine",
                                    42,
                                    2000,
                                    PeriodicPeriod::WEEKLY,
                                    10);
    Item *item2 = publication.clone();
    library.addItem(item2, 5);
    std::ofstream os("library.txt", std::ios::out | std::ios::trunc);
    if (os.is_open()) {
        os << library;
    }
    os.close();
//    Menu menu;
}
