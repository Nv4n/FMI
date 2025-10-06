#include "Report.h"
#include <stdexcept>

Report::Report(char* authors[10], char* title, char* reporter, char id[4], unsigned duration):Article(authors,title)
{
    try {
        if (duration > 60) {
            throw std::invalid_argument("Duration of report can't be above 60 mins");
        }
        this->duration = duration;

        for (size_t i = 0; i < REPORT_ID_MAX_LENGTH; i++)
        {
            if (i < 3 && (id[i] < 'A' || id[i]>'Z')) {
                throw std::invalid_argument("Invalid report id format");
            }
            if (i == 3 && (id[i] < '0' || id[i]>'9')) {
                throw std::invalid_argument("Invalid report id format");
            }
            this->id[i] = id[i];
        }

        for (size_t i = 0; i < authorsCount; i++)
        {
            if (std::strcmp(authors[i], reporter) != 0) {
                if (i == authorsCount - 1) {
                    throw std::invalid_argument("Reporter is not an author");
                }
                continue;
            }
            
            this->reporter = new char[std::strlen(reporter) + 1];
            std::strcpy(this->reporter, reporter);
            break;
        }

   
    }
    catch (std::invalid_argument& e) {
        clearMem();
        throw e;
    }
}

Report::Report(const Report& other):Article(other)
{
    copy(other);
}

Report& Report::operator=(const Report& other)
{
    if (this!=&other) {
        Report temp(other);
        clearMem();
        std::swap(*this, temp);
}
    return *this;
}

Report::~Report()
{
    clearMem();
}

Article* Report::clone()
{
    return new Report(*this);
}

void Report::copy(const Report& other)
{
   reporter = new char[std::strlen(other.reporter) + 1];
    std::strcpy(reporter, other.reporter);
    for (size_t i = 0; i < REPORT_ID_MAX_LENGTH; i++)
    {
        id[i] = other.id[i];
    }
    duration = other.duration;
}

void Report::clearMem()
{
    Article::clearMem();
    delete[] reporter;
}
