#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"

#pragma once
class Manager :public Employee {
private:
	size_t mngdEmplsCount;
public:
	void setMngdEmployeesCount(size_t mngdEmplsCount);
	size_t getMngdEmployeesCount();
};
#endif // !MANAGER_H

