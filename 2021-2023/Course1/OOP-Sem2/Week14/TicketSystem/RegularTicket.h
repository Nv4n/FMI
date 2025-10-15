//
// Created by Sybatron on 5/26/2022.
//

#ifndef RESTAURANT_REGULARTICKET_H
#define RESTAURANT_REGULARTICKET_H
#include "Ticket.h"
#include <iostream>

class RegularTicket:public Ticket{
public:
    RegularTicket(const char* destination,double price):Ticket(destination,price){};
    void print() override{
        std::cout<<destination<<" "<<price<<std::endl;
    }
};
#endif //RESTAURANT_REGULARTICKET_H
