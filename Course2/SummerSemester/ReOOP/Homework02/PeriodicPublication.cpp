//
// Created by Sybatron on 5/26/2023.
//

#include "PeriodicPublication.h"

PeriodicPublication::PeriodicPublication() = default;

PeriodicPublication::~PeriodicPublication() = default;

PeriodicPublication::PeriodicPublication(const MinString &_title, const MinString &_shortDescr,
                                         const size_t &_libraryId,
                                         unsigned short _publishYear, PeriodicPeriod _period,
                                         unsigned int _issue)
        : Item(_title, _shortDescr, _libraryId, _publishYear) {
    setPeriod(_period);
    setIssue(_issue);
    type = ItemType::PERIODIC_PUBLICATION;
}

PeriodicPublication::PeriodicPublication(const PeriodicPublication &other) : Item(other) {
    copy(other);
}

PeriodicPublication &PeriodicPublication::operator=(const PeriodicPublication &other) {
    if (this != &other) {
        copy(other);
        Item::operator=(other);
    }
    return *this;
}

Item *PeriodicPublication::clone() const {
    return new PeriodicPublication(*this);
}


// Getters and Setters
unsigned int PeriodicPublication::getIssue() const {
    return issue;
}

PeriodicPeriod PeriodicPublication::getPeriod() const {
    return period;
}

void PeriodicPublication::setPeriod(PeriodicPeriod _period) {
    PeriodicPublication::period = _period;
}

void PeriodicPublication::setIssue(unsigned int _issue) {
    PeriodicPublication::issue = _issue;
}


void PeriodicPublication::copy(const PeriodicPublication &other) {
    period = other.period;
    issue = other.issue;
}


