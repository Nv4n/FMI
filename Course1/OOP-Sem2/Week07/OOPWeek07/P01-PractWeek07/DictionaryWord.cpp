#include <cstring>

#include "DictionaryWord.h"

DictionaryWord::DictionaryWord() {
	word_ = new char[1];
	explanation_ = new char[1];

	word_[0] = '\0';
	explanation_[0] = '\0';
}
DictionaryWord::DictionaryWord(char* word, char* explanation) {
	setWord(word);
	setExplanation(explanation);
}
DictionaryWord::DictionaryWord(const DictionaryWord& dicWord) {
	copy_(dicWord);
}
DictionaryWord& DictionaryWord::operator=(const DictionaryWord& dicWord) {
	if (this != &dicWord) {
		copy_(dicWord);
	}

	return *this;
}

DictionaryWord::~DictionaryWord() {
	delete[] word_;
	delete[] explanation_;
}

void DictionaryWord::setWord(const char* word) {
	if (std::strlen(word) > 100) {
		throw "Input exceeds max length";
	}

	if (word_ != nullptr) {
		delete[] word_;
	}
	word_ = new char[std::strlen(word) + 1];
	std::strcpy(word_, word);
}

void DictionaryWord::setExplanation(const char* explanation) {
	if (std::strlen(explanation) > 500) {
		throw "Input exceeds max length";
	}

	if (explanation_ != nullptr) {
		delete[] explanation_;
	}
	explanation_ = new char[std::strlen(explanation) + 1];
	std::strcpy(explanation_, explanation);
}

char* DictionaryWord::getWord() const {
	return word_;
}

char* DictionaryWord::getExplanation() const {
	return explanation_;
}

void DictionaryWord::copy_(const DictionaryWord& dicWord) {
	delete[] word_;
	delete[] explanation_;

	setWord(dicWord.word_);
	setExplanation(dicWord.explanation_);
}