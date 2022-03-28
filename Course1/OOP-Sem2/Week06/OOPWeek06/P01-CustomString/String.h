#ifndef STRING_STRING_N
#define STRING_STRING_N

#include <cstdlib>
#include <fstream>

class String
{
private:
	char* string_{};
	size_t size_{};
	void copy(const String source) {};
	//String& move(String&& source) {};
	void clear() {};

public:
	String() = default;
	String(const char* string);
	String(const String& string) /* :String(string.string_) */ {};
	String(String&& string) {};
	String& operator=(const String& string) {};
	String& operator=(String&& string) {};

	bool operator==(const String& string);

	~String() {};

	const char* c_str() const;
	char* data() const;

	friend std::ostream& operator<<(std::ostream& out, const String& string);
	friend std::istream& operator>>(std::istream& in, String& string);
	
	friend bool operator==(const String& string, const String& stringSource);
};

#endif // STRING_STRING_N