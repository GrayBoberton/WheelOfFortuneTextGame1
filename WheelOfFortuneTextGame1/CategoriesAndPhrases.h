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
		std::string checkLetter(std::string chosenLetter, std::string chosenPhrase, std::vector<char> foundCharIndexes);
	};
}
