#include <Date.h>
Date::Date(unsigned day, unsigned month, unsigned year) : day(day), month(month), year(year)
{
    Validate(day, month, year);
}

Date::~Date()
{
}

Date::Date(const char *date)
{
}

void Date::Validate(unsigned day, unsigned month, unsigned year)
{
    if (year < 1970 || year > 2033 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        throw std::invalid_argument("Wrong date");
    }
    // TODO: Correct day validation
}

int Date::ParseInt(const char *num)
{
    int result = 0;
    while (num != nullptr && *num != '\0' && *num != '/')
    {
        result *= 10;
        result += *num - '0';
    }
    return result;
}

void Date::Print(std::ostream &out) const
{
    std::ostream << day << " " << month << " " << year;
}
