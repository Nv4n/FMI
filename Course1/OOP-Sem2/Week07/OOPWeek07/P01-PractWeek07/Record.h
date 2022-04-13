#ifndef RECORDH
#define RECORDH

class Record
{
private:
	char* word;
	char* meaning;

	void copy(const Record& other);
	void move(Record& other);
	void destroy();
public:

	Record();
	Record(const Record& other);
	Record(const char* word, const char* meaning);
	Record(Record&& other);
	Record& operator=(const Record& other);
	Record& operator=(Record&& other);
	~Record();

	void setWord(const char* word);
	void setMeaning(const char* meaning);

	char* getWord() const;
	char* getMeaning() const;

	void printWord();

	friend std::ostream& operator<<(std::ostream& os, const Record& rec);
	friend std::istream& operator>>(std::istream& is, const Record& rec);
};

#endif // !RECORDH