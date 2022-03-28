#pragma once
class Employee
{
private:
	char* name;
	unsigned int age;
	unsigned int wage;
public:
	Employee() {};
	Employee(const char* name, const unsigned int age, const unsigned int wage) {};
	Employee(const Employee& empl) :Employee(empl.name, empl.age, empl.wage) {};
	Employee operator=(Employee const& empl) {};
	~Employee() {};

	char* getName() {};
	unsigned int getAge() {};
	unsigned int getWage() {};

	void setName(const char* name) {};
	void setAge(const unsigned int age) {};
	void setWage(const unsigned int wage) {};
};
