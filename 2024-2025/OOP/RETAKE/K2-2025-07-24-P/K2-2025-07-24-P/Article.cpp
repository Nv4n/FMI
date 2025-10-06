#include "Article.h"
#include "cstring"
#include <stdexcept>

Article::Article(char** authors, char* title)
{
	try {
		this->title = new char[std::strlen(title) + 1];
		std::strcpy(this->title, title);
		authorsCount = 0;
		char** tempAuthors = authors;
		while (tempAuthors != nullptr) {
			this->authors[authorsCount] = new char[std::strlen(*tempAuthors) + 1];
			std::strcpy(this->authors[authorsCount], *tempAuthors);
			authorsCount++;
			tempAuthors++;
		}
	}
	catch (std::invalid_argument& e) {
		clearMem();
		throw e;
	}

}


Article::~Article()
{
	clearMem();
}

Article::Article(const Article& other)
{
	copy(other);
}

Article& Article::operator=(const Article& other)
{
	if (this != &other) {
		clearMem();
		copy(other);
	}
	return *this;
}

void Article::clearMem()
{
	delete[] title;
	for (size_t i = 0; i < authorsCount; i++)
	{
		delete[] authors[i];
	}
}

void Article::copy(const Article& other)
{
	title = new char[std::strlen(other.title)+1];
	std::strcpy(title,other.title);
	authorsCount = other.authorsCount;
	for (size_t i = 0; i < authorsCount; i++)
	{
		authors[i] = new char[std::strlen(other.authors[i]) + 1];	
		
		std::strcpy(authors[i], other.authors[i]);
	}
}
