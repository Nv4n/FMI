#pragma once
class DictionaryWord
{
private:
	char* word_;
	char* explanation_;

public:
	DictionaryWord();
	DictionaryWord(char* word, char* explanation_);
	DictionaryWord(const DictionaryWord& dicWord);
	DictionaryWord& operator=(const DictionaryWord& dicWord);
	~DictionaryWord();

public:
	void setWord(const char* word) ;
	void setExplanation(const char* explanation);
	char* getWord() const;
	char* getExplanation() const;

private:
	void copy_(const DictionaryWord& dicWord);
};

