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
		void checkIfLetterInPhrase(std::string chosenPhrase, std::vector<char> foundCharIndexes);
		char validVowel(std::vector<char> foundCharIndexes, char letter);
		char validConsonant(std::vector<char> foundCharIndexes, char letter);
	};
}
