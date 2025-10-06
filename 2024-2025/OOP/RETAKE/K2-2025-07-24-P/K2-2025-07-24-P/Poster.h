#pragma once
#include "Article.h"
class Poster : public Article
{
protected:
	static const unsigned POSTER_FORMAT_LENGTH = 3;
	static const unsigned POSTER_DATE_LENGTH = 8;
	bool format[POSTER_FORMAT_LENGTH];
	char date[POSTER_DATE_LENGTH];
public:
	Poster(char** authors, char* title,bool format[POSTER_FORMAT_LENGTH],char date[POSTER_DATE_LENGTH]);
	Poster(const Poster& other);
	Poster& operator=(const Poster& other);
	Article* clone() override;

private:
	void copy(const Poster& other);
};

