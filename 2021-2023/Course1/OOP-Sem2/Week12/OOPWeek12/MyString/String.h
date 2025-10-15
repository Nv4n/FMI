#ifndef STRING_H
#define STRING_H

#pragma once
#pragma warning (disable:4996)
class String
{
private:
	char* _data;
	size_t _size;
	size_t _capacity;
public:
	String();
	String(const String& other);
	String& operator=(const String& other);
	~String();

	void append(const String& other);
	void append(const char* other);
	void append(char other);
	size_t length();

	void splitBy(const char symbol);

	const char& operator[](size_t)const;
	char& operator[](size_t);

	friend bool operator==(const String& lvalue, const String& rvalue);
	friend bool operator!=(const String& lvalue, const String& rvalue);

	friend void operator<<(std::ostream& os, const String& str);
	friend void operator>>(std::istream& is, String& str);

private:
	void resize();
	void copy(const String& other);
	void destroy();
};
#endif // !STRING_H

