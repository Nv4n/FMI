#include "Record.h"
#include <iostream>
#include <cstring>

#pragma warning(disable: 4996)// for strcpy

void Record::copy(const Record& other) {
	setWord(other.word);
	setMeaning(other.meaning);
}

void Record::destroy() {
	delete[] word;
	delete[] meaning;
}

void Record::move(Record& other) {
	word = other.word;
	meaning = other.meaning;
	other.word = nullptr;
	other.meaning = nullptr;
}


#pragma region Ctors


Record::Record() {
	word = nullptr;
	meaning = nullptr;
}
Record::Record(const char* word, const char* meaning) {
	setWord(word);
	setMeaning(meaning);
}

Record::Record(const Record& other) {
	copy(other);
}
Record::Record(Record&& other) {
	move(other);
}

Record& Record::operator=(const Record& other) {
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}
Record& Record::operator=(Record&& other) {
	if (this != &other)
	{
		move(other);
	}

	return *this;
}

Record::~Record() {
	destroy();
}
#pragma endregion


#pragma region Functions
void Record::setWord(const char* word) {
	if (word != nullptr)
	{
		if (this->word != nullptr)
		{
			delete[] this->word;
		}

		int size = strlen(word);

		if (size < 100)
		{
			this->word = new char[size + 1];
			strcpy(this->word, word);
		}
	}
}

void Record::setMeaning(const char* meaning) {
	if (meaning != nullptr)
	{
		if (this->meaning != nullptr)
		{
			delete[] meaning;
		}

		int size = strlen(meaning);

		if (size < 500)
		{
			this->meaning = new char[size + 1];
			strcpy(this->meaning, meaning);
		}
	}
}

char* Record::getWord() const {
	return this->word;
}

char* Record::getMeaning() const {
	return this->meaning;
}

void Record::printWord() {
	std::cout << "Word is: " << word << std::endl;
	std::cout << "Meaning is: " << meaning << std::endl;
}
#pragma endregion

#pragma region Operators
std::ostream& operator<<(std::ostream& os, const Record& rec) {
	os << "Word is:: " << rec.word << "Meaning is:: " << rec.meaning << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, const Record& rec) {
	is >> rec.word >> rec.meaning;
	return is;
}


#pragma endregion
