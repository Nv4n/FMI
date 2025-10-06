#ifndef ARTICLE_H
#define ARTICLE_H

#define _CRT_SECURE_NO_WARNINGS

#pragma once
class Article
{
protected:
	char* authors[10];
	unsigned authorsCount;
	char* title;
public:
	Article(char** authors,char* title );
	virtual ~Article();
	Article(const Article& other);
	Article& operator=(const Article& other);
	virtual Article* clone()=0;
private:
	void copy(const Article& other);
protected:
	virtual	void clearMem();
};


#endif // !ARTICLE_H