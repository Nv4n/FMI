//
// Created by Sybatron on 5/26/2022.
//

#ifndef RESTAURANT_TICKET_H
#define RESTAURANT_TICKET_H
#include <cstring>

class Ticket{
protected:
    char* destination;
    double price;
public:
    Ticket():destination(std::strcpy(new char[1],"")),price(0){};
    virtual ~Ticket(){delete[] destination;};
    Ticket(const char* destination,double price):destination(std::strcpy(new char[std::strlen(destination)],destination)),price(price){};
    virtual void print()=0;
};
#endif //RESTAURANT_TICKET_H
