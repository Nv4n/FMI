#ifndef DICTIONARYH
#define DICTIONARYH

#include "Record.h"

class Dictionary
{
private:
	Record* records;
	int size;
	int capacity;

	void copy(const Dictionary& other);
	void resize();
	void destroy();

public:

	Dictionary();
	Dictionary(const int capacity);
	Dictionary(const Dictionary& other);
	Dictionary& operator=(const Dictionary& other);
	~Dictionary();

	void addRecord(const char* word, const char* meaning);
	void print();

	int getSize() const;
	int getCapacity() const;

	const Record& find(const char* wordToFind) const;

	friend std::ostream& operator<<(std::ostream& os, const Record& dic);
	friend std::istream& operator>>(std::istream& is, const Record& dic);
};

#endif // !DICTIONARYH