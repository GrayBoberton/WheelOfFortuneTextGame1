#pragma once
#include <iostream>
#include <vector>

namespace cat
{
	class category
	{
	public:
		std::string pickCategory(int numCategories);
		std::string pickPhrase(std::string categoryName);
		void checkIfLetterInPhrase(char chosenLetter, std::string chosenPhrase, std::vector<char> foundCharIndexes);
		void validVowel(std::vector<char> foundCharIndexes, char letter);
		void validConsonant(char letter);
	};
}
