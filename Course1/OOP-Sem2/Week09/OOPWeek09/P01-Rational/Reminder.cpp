#include <iostream>
#include <cstring>
#include <fstream>
#include "Reminder.h"

Reminder::Reminder(char date[10], const char* title, size_t priority) {

}
Reminder::Reminder(const Reminder& other) {

}
Reminder::Reminder(const Reminder&& other) {

}
Reminder& Reminder::operator=(const Reminder& other) {

}
Reminder& Reminder::operator=(const Reminder&& other) {

}
Reminder::~Reminder() {
	destroy();
}

bool Reminder::operator>(const Reminder& other)const {

}
bool Reminder::operator>=(const Reminder& other)const {

}
bool Reminder::operator<(const Reminder& other)const {

}
bool Reminder::operator<=(const Reminder& other)const {

}
bool Reminder::operator==(const Reminder& other)const {

}

void operator>>(const std::istream& is, const Reminder& other) {

}
void operator<<(const std::ostream& os, const Reminder& other) {

}

void Reminder::addNotes(const char* note) {

}

#pragma region PrivateMethods
void Reminder::resize() {
	capacity *= 2;
	char** tempNotes = new char* [capacity];

	for (size_t i = 0; i < size; i++) {
		size_t size_ = std::strlen(notes[i]) + 1;
		tempNotes[i] = new char[size_];
		strcpy_s(tempNotes[i], size_, notes[i]);
	}

	for (int i = 0; i < size; i++) {
		delete[] notes[i];
	}
	delete[] notes;
	notes = new char* [capacity];
}

void Reminder::copy(const Reminder& other) {
	for (size_t i = 0; i < 10; i++) {
		date[i] = other.date[i];
	}
	size_t size_ = std::strlen(other.title) + 1;
	title = new char[size_];
	strcpy_s(title, size, other.title);
	priority = other.priority;

	size = other.size;
	capacity = other.capacity;
	notes = new char* [capacity];
	for (size_t i = 0; i < size; i++) {
		size_ = std::strlen(other.notes[i]) + 1;
		notes[i] = new char[size_];
		strcpy_s(notes[i], size_, other.notes[i]);
	}
}

void Reminder::destroy() {
	delete[] title;
	for (int i = 0; i < size; i++) {
		delete[] notes[i];
	}
	delete[] notes;
}
#pragma endregion