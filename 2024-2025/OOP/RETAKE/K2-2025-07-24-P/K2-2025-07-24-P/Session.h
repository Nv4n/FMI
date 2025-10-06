#ifndef SESSION_H


#pragma once
#include "Article.h"
class Session
{
private:
	static const unsigned NAME_LENGTH = 3;
	static const unsigned DATE_LENGTH = 3;
	char name[NAME_LENGTH];
	char date[DATE_LENGTH];
	Article** materials;
	unsigned materialsLength;
	unsigned materialsCapacity;
	unsigned duration;

public:

	Session(char name[3], char date[8], Article** materials, unsigned duration);
		
	Session(const Session& other);

	Session& operator=(const Session& other);
	virtual ~Session();

private:
	void copy(const Session& other);
	void clearMem();
	void extendMaterialsMem();
};

#endif // !SESSION_H
