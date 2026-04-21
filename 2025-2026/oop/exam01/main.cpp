//
// Created by Sybatron on 4/21/2026.
//

#include "Date.h"

int main() {
    Date date("11/02/2021");
    Date date2("11/12/1970\0");

    date.Print(std::cout);
}
