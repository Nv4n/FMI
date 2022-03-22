#include <cstdlib>

#pragma once
class String {
	/*
	ctor no args
	ctor(char*)
	dtor
	-char*
	-int size
	-int capacity
	c_str()
	-append char
	*/
public:
	String();
	String(char* string);
	const char* c_str();
	void Append(const char* str);
	//void Append(const char chr);
	~String();

private:
	char* string = nullptr;
	size_t capacity{};
	size_t size{};
};
