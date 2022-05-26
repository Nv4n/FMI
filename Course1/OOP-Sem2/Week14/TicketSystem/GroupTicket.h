//
// Created by Sybatron on 5/26/2022.
//

#ifndef RESTAURANT_GROUPTICKET_H
#define RESTAURANT_GROUPTICKET_H
#include "Ticket.h"
#include <iostream>

class GroupTicket:public Ticket{
private:
    size_t peopleCount;
public:
    GroupTicket();
    GroupTicket(const char* destination, double price,size_t peopleCount):Ticket(destination,price-peopleCount*2),peopleCount(peopleCount){};
    void print() override{
        std::cout<<destination<<" "<<price<<" "<<peopleCount<<std::endl;
    }
}
#endif //RESTAURANT_GROUPTICKET_H
