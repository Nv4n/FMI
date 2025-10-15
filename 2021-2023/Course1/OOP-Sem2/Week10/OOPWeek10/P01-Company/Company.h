#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h"

#pragma once
class Company
{
private:
	Employee** employees;
	size_t size;
	size_t capacity;
public:
	Company();
	Company(const Company& other);
	Company& operator=(const Company& other);
	~Company();

	void addEmployee( Employee* const emp);
	void sort(bool(*comparator)(const Employee*, const Employee*));

private:
	void resize();
	void destroy();
	void copy(const Company& other);
};

#endif // !COMPANY_H
