#include "Employee.h"

#pragma once
class Company
{
private:
	Employee* employees;
	unsigned int employeesCount;
	unsigned int capacity;
public:
	Company() {};
	Company(const Company& comp) {};
	Company(Employee* empls, const unsigned int capacity) {};
	Company operator=(Company const& comp) {};
	~Company() {};

	void saveWorkers(const char* fileName) {};
	const Employee& getMostPaid() const {};
	void addEmployee(const Employee& newEmployee) {};
};

