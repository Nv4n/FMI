#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"

#pragma once
class Manager :public Employee {
private:
	size_t mngdEmplsCount;
public:
	Manager(const Manager& other);
	Manager& operator=(const Manager& other);
	Employee* clone() const;

	void setMngdEmployeesCount(size_t mngdEmplsCount);
	size_t getMngdEmployeesCount();

private:
	void copy(const Manager& other);
};
#endif // !MANAGER_H

