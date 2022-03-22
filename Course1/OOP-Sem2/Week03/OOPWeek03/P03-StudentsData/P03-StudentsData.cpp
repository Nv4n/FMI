// P03-StudentsData.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>

#define MAX_SIZE 256

struct Student {
	char facultyNumber[MAX_SIZE];
	char name[MAX_SIZE];
	double averageSum;

	void write(std::ostream& writeStream) {
		writeStream << this->name << '\n'
			<< this->facultyNumber << '\n'
			<< this->averageSum << "\n";
	}

	void read(std::istream& readStream) {
		readStream >> this->name >> this->facultyNumber >> this->averageSum;
	}
};

void writeStudents(std::ostream& writeStream, const Student* student, int size);

int main()
{
	Student firstStudent;
	strcpy_s(firstStudent.name, "Dimitur");
	strcpy_s(firstStudent.facultyNumber, "123456");
	firstStudent.averageSum = 4.5;

	Student secondStudent;
	strcpy_s(secondStudent.name, "Pencho");
	strcpy_s(secondStudent.facultyNumber, "123457");
	secondStudent.averageSum = 4;

	int size = 2;
	Student listOfStudents[2] = { firstStudent,secondStudent };

	std::ofstream readStream;
	readStream.open("test.txt");
	if (!readStream.is_open()) {
		std::cout << "ERROR!";
		return -1;
	}

	writeStudents(readStream, listOfStudents, size);
	readStream.close();

	std::ifstream writeStream;
	writeStream.open("readFile.txt");
	if (!writeStream.is_open()) {
		std::cout << "ERROR!" << std::endl;
		return -1;
	}

	readStudents(writeStream, listOfStudents, size);
	writeStream.close();
	writeStudents
}

void writeStudents(std::ostream& writeStream, Student* students, int size) {
	for (int studentIndex = 0; studentIndex < size; studentIndex++) {
		students[studentIndex].write(writeStream);
	}
}

void readStudents(std::istream& writeStream, Student* students, int size) {
	for (int studentIndex = 0; studentIndex < size; studentIndex++) {
		students[studentIndex].read(writeStream);
	}
}