#include "DictionaryWord.h"

#pragma once
class Dictionary
{
private:
	DictionaryWord* words_;
	size_t wordsCount_;
public:
	Dictionary();
	Dictionary(DictionaryWord* words);
	Dictionary(const Dictionary& dictionary);
	Dictionary& operator=(const Dictionary& dictionary);
	~Dictionary();

	void appendWord(DictionaryWord word);
	DictionaryWord getAllWords();
	DictionaryWord getWordExplanation();
};

