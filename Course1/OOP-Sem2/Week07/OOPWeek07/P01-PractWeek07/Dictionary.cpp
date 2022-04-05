#include "Dictionary.h"
Dictionary::Dictionary() {
	wordsCount_ = 0
};
Dictionary::Dictionary(DictionaryWord* words) {
	delete[] words_;
	wordsCount_ = sizeof(words) / sizeof(words[0]);
	words_ = new DictionaryWord[wordsCount_ + 1]; 
}
Dictionary(const Dictionary& dictionary);
Dictionary& operator=(const Dictionary& dictionary);
~Dictionary();