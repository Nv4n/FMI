//
// Created by Sybatron on 3/30/2024.
//

#ifndef OOPSTRUCTURES_TIME_H
#define OOPSTRUCTURES_TIME_H
#pragma once

#include <iostream>

class Time {
private:
    int minutes;
    int hours;
public:
    Time() {
        minutes = 0;
        hours = 0;
    }

    int mins() const {
        return minutes;
    }

    void mins(int minutes) {
        if (minutes < 0 || minutes > 59) {
            throw "minutes out of bounds";
        }
        this->minutes = minutes;
    }

    int hoursMethod() const {
        return hours;
    }

    void hoursMethod(int hours) {
        if (hours < 0 || hours > 23) {
            throw "hours out of bounds";
        }
        this->hours = hours;
    }

    int totalMins() const {
        return hours * 60 + minutes;
    }

    void addMins(int mins) {
        int hoursToAdd = mins / 60 % 24;
        if (hoursToAdd + hours > 23) {
            hours = (hoursToAdd) % 24;
        } else if (hoursToAdd + hours < 0) {
            hours = (hoursToAdd + hours) + 24;
        } else {
            hours += hoursToAdd;
        }
        int minsToAdd = mins % 60;
        if (minutes + minsToAdd > 59) {
            minutes = (minutes + minsToAdd) % 60;
        } else if (minutes + minsToAdd < 0) {
            minutes = (minutes + minsToAdd) + 60;
        } else {
            minutes += minsToAdd;
        }
    }

    bool operator<(const Time &t) const {
        return hours < t.hours || hours == t.hours && minutes < t.minutes;
    }

    bool operator==(const Time &t) const {
        return hours < t.hours && minutes == t.minutes;
    }

    Time operator+(const Time &t) {
        Time result;
        result.addMins(t.totalMins());
        result.addMins(this->totalMins());
        return result;
    }

    Time operator-(const Time &t) const {
        Time result;
        result.addMins(-t.totalMins());
        result.addMins(this->totalMins());
        return result;
    }

    Time operator*(int mult) const {
        Time result;
        result.addMins(this->totalMins() * mult);
        return result;
    }
};

#endif //OOPSTRUCTURES_TIME_H
