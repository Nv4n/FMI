#include "Book.h"
#include "Utils.h"
const unsigned Book::ID_LENGTH = 12;
const unsigned Book::MAX_COUNT = 500;
unsigned Book::count = 0;
unsigned Book::nextId = 0;

Book::Book(const char* name, const char* author, unsigned pages) :pages(pages), ID(getNextId())
{
	try {
		if (pages < 1) {
			throw std::invalid_argument("Pages can't be 0");
		}
		if (count >= 500) {
			throw std::runtime_error("Reached max concurrent book count");
		}

		SetName(name);
		SetAuthor(author);
		++count;
	}
	catch (...) {
		delete[] name;
		delete[] author;
		delete[] ID;
		--nextId;
		throw;
	}
}

Book::~Book()
{
	delete[] author;
	delete[] name;
	delete[] ID;
	author = nullptr;
	name = nullptr;
	--Book::count;
}

Book::Book(const Book& other) :Book(other.name, other.author, other.pages)
{
}

Book& Book::operator=(const Book& other)
{
	if (this != &other) {
		Book temp(other);
		std::swap(author, temp.author);
		std::swap(name, temp.name);
		std::swap(pages, temp.pages);
	}
	return *this;
}

void Book::SetName(const char* newName)
{
	std::size_t len = std::strlen(newName);
	if (len < 1 || newName == nullptr) {
		throw std::invalid_argument("Name can't be empty");
	}
	char* temp = new char[len + 1];
	std::strcpy(temp, newName);
	delete[] name;
	name = temp;
}

void Book::SetAuthor(const char* newAuthor)
{
	std::size_t len = std::strlen(newAuthor);
	if (len < 1 || newAuthor == nullptr) {
		throw std::invalid_argument("Name can't be empty");
	}
	char* temp = new char[len + 1];
	std::strcpy(temp, newAuthor);
	delete[] author;
	author = temp;
}

char* Book::GetName() const
{
	char* temp = new char[std::strlen(name) + 1];
	std::strcpy(temp, name);

	return temp;
}

char* Book::GetAuthor() const
{
	char* temp = new char[std::strlen(author) + 1];
	std::strcpy(temp, author);

	return temp;
}


unsigned Book::GetPagest() const
{
	return pages;
}

char* Book::GetID() const
{
	char* temp = new char[std::strlen(ID) + 1];
	std::strcpy(temp, ID);
	return temp;
}



// Name Author Pages ID
std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.name << " " << book.author << " " << book.pages << " " << book.ID;
	return os;
}

// Name Author 100 ID_TO_DELETE
std::istream& operator>>(std::istream& is, Book& book)
{
	char* name = nullptr;
	char* author = nullptr;
	char* toDelete = nullptr;
	try {
		std::size_t len = Utils::GetBufferLen(is);
		name = new char[len + 1];
		is >> name;

		len = Utils::GetBufferLen(is);
		char* author = new char[len + 1];
		is >> author;

		unsigned pages = 0;
		is >> pages;

		len = Utils::GetBufferLen(is);
		toDelete = new char[len + 1];
		is >> toDelete;

		Book temp(name, author, pages);
		std::swap(book.author, temp.author);
		std::swap(book.name, temp.name);
		std::swap(book.pages, temp.pages);
	}
	catch (...) {
		delete[] name;
		delete[] author;
		delete[] toDelete;
		throw;
	}

	delete[] name;
	delete[] author;
	delete[] toDelete;

	return is;
}

char* Book::getNextId()
{
	if (nextId >= 9999) {
		throw std::logic_error("Id reached max value");
	}

	char* newId = new char[ID_LENGTH];

	std::strcpy(newId, "IS-INF-0000");

	unsigned copyNumId = nextId++;
	unsigned index = ID_LENGTH - 1;

	while (copyNumId > 0) {
		--index;
		newId[index] = (copyNumId % 10) + '0';
		copyNumId /= 10;
	}

	return newId;
}