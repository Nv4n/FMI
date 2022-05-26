//
// Created by Sybatron on 5/26/2022.
//

#ifndef RESTAURANT_STUDENTTICKET_H
#define RESTAURANT_STUDENTTICKET_H
#include "RegularTicket.h"
class StudentTicket:public RegularTicket{
private:
    char* document;
public:
    virtual ~StudentTicket(){delete[] document;};
    StudentTicket(const char* destination,double price,const char* document): RegularTicket(destination,price/2),document(std::strcpy(new char[std::strlen(document)],document)){};
};
#endif //RESTAURANT_STUDENTTICKET_H
