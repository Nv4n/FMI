#ifndef REPORT_H
#define REPORT_H


#include "Article.h"
#pragma once
class Report:public Article
{
private:
	static const unsigned REPORT_ID_MAX_LENGTH=4;
protected:
	char* reporter;
	char id[REPORT_ID_MAX_LENGTH];
	unsigned duration;
public:
	Report(char** authors, char* title, char* reporter, char id[4], unsigned duration);
	Report(const Report& other);
	Report& operator=(const Report& other);
	virtual ~Report();
	Article* clone() override;

private:
	void copy(const Report& other);
protected:
	void clearMem() override;
};

#endif // !REPORT_H
