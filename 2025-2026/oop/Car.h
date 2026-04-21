#pragma once

class Car
{
private:
    /* data */
    enum class Type
    {
        SEDAN,
        HATCHBACK,
        KOMBI
    } char *make;
    Date date;

public:
    Car(/* args */);
    ~Car();
};
