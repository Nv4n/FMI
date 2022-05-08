#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#pragma once
class Employee
{
protected:
	char* name;
	size_t experience;
public:
	Employee() = delete;
	Employee(const char* name, const size_t experience);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	~Employee();

	void setName(const char* name);
	void setExperience(const size_t experience);

	const char* getName()const;
	size_t getExperinece();
protected:
	void copy(const Employee& other);
	void destroy();
};

#endif // !EMPLOYEE_H
