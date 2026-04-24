#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
class Shelf;

class Book
{

public:
	Book() = delete;
	Book(const char* name, const char* author, unsigned pages);
	~Book();
	Book(const Book&);
	Book& operator=(const Book&);
	void SetName(const char*);
	void SetAuthor(const char*);
	char* GetName() const;
	char* GetAuthor() const;
	unsigned GetPagest() const;
	char* GetID() const;

	friend std::ostream& operator<<(std::ostream& os, const Book& book);
	friend std::istream& operator>>(std::istream& is, Book& book);

private:
	static char* getNextId();

	static const unsigned ID_LENGTH;
	static const unsigned MAX_COUNT;
	static unsigned nextId;
	static unsigned count;

	char* name = nullptr;
	char* author = nullptr;
	unsigned pages = 0;
	// IS-INF-0000
	const char* ID;
};

std::ostream& operator<<(std::ostream& os, const Book& book);
std::istream& operator>>(std::istream& is, const Book& book);


