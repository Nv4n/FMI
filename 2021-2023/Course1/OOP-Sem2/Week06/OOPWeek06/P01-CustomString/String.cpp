#include <cstring>
#include "String.h"

String::String(const char* string) {
	this->size_ = strlen(string);
	this->string_ = new char[this->size_ + 1];
	std::strcpy(this->string_, string);
}

String::String(const String& string) {
	copy(string);
}

String::String(String&& string) noexcept {
	delete[] string_;
	size_ = string.size_;
	string_ = string.string_;
	string.clear();
}

String& String::operator=(const String& string) {
	if (this != &string) {
		copy(string);
	}

	return *this;
}

String& String::operator=(String&& string) noexcept {
	if (this != &string) {
		delete[] string_;
		size_ = string.size_;
		string_ = string.string_;
		string.clear();
	}

	return *this;
}

bool String::operator==(const String& string) {
	return !strcmp(string_, string.string_);
}

bool String::operator!=(const String& string) {
	return !(string == *this);
	//return !this->operator==(string);
}

bool operator==(const String& string, const String& stringSource) {
	if (!string.string_ && !stringSource.string_) return true;
	if (!string.string_ || !stringSource.string_) return false;

	return !strcmp(string.string_, stringSource.string_);
}

String::~String() {
	clear();
}

const char* String::c_str() const {
	return string_;
}

char* String::data() const {
	return string_;
}

std::ostream& operator<<(std::ostream& out, const String& string) {
	out << string.c_str();
	return out;
}

std::istream& operator>>(std::istream& in, String& string) {
	const size_t MAX_STR = 512;
	char buffer[MAX_STR];
	in >> buffer;
	String temp = String(buffer);
	string = temp;
	return in;
};


//String& String::move(String&& source)noexcept {
//	delete[] string_;
//	size_ = source.size_;
//	string_ = source.string_;
//	source.clear();
//}

void String::copy(const String source) {
	delete[] string_;
	size_ = source.size_;
	string_ = new char[size_ + 1];
	std::strcpy(string_, source.string_);
}

void String::clear() {
	delete[] string_;
	size_ = 0;
}