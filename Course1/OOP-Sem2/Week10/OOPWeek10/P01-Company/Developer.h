#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

#pragma once
class Developer :public Employee
{
private:
	bool isCppKnown;
	bool isCsharpKnown;
public:
	Developer() = delete;
	Developer(const Developer& other);
	Developer& operator=(const Developer& other);

	void setCppKnown(bool isCppKnown);
	void setCsharpKnown(bool isCsharpKnown);

	bool getCppKnown();
	bool getCsharpKnown();
private:

};

#endif // !DEVELOPER_H
