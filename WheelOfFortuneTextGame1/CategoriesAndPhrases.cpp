#include "CategoriesAndPhrases.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace cat;
using namespace std;

string category::pickCategory(int numCategories) {
	int categoryNum = rand() % numCategories + 1;
	string categoryName = "";
	if (categoryNum == 1) {
		categoryName = "Food & Drink";
	}
	else if (categoryNum == 2) {
		categoryName = "People";
	}
	else if (categoryNum == 3) {
		categoryName = "Phrases";
	}
	else {
		categoryName = "Bob";
	}
	return categoryName;
}

vector<string> phraseFoodDrink{ "A BOWL OF WARM BUSCIUTS", "A BOWL OF FRESH BERRIES", "A GLASS OF SODA", "A SLICE OF PIE", "A DOLLOP OF YOGURT" };
vector<string> phrasePhrases{ "LAST ONE IN IS A ROTTEN EGG", "LIVE LAUGH LOVE", "BANG FOR YOUR BUCK", "A CHUNK OF CHANGE", "ZERO TO SIXTY" };
vector<string> phrasePeople{ "WORDSMITHS", "WRECKING CREW", "ACTORS", "WEDDING CRASHERS", "ACCORDIONIST" };
vector<string> phraseOther{ "ERROR" };

string category::pickPhrase(string categoryName) {
	string chosenPhrase = "";

	if (categoryName == "Food & Drink") {
		if (phraseFoodDrink.size() != 0) {
			int chooseRandomPhrase = rand() % phraseFoodDrink.size();
			chosenPhrase = phraseFoodDrink[chooseRandomPhrase];
			phraseFoodDrink.erase(phraseFoodDrink.begin() + chooseRandomPhrase);
		}
	}
	else if (categoryName == "Phrases") {
		if (phrasePhrases.size() != 0) {
			int chooseRandomPhrase = rand() % phrasePhrases.size();
			chosenPhrase = phrasePhrases[chooseRandomPhrase];
			phrasePhrases.erase(phrasePhrases.begin() + chooseRandomPhrase);
		}
	}
	else if (categoryName == "People") {
		if (phrasePeople.size() != 0) {
			int chooseRandomPhrase = rand() % phrasePeople.size();
			chosenPhrase = phrasePeople[chooseRandomPhrase];
			phrasePeople.erase(phrasePeople.begin() + chooseRandomPhrase);
		}
	}
	else {		
		int chooseRandomPhrase = rand() % phraseOther.size();
		chosenPhrase = phraseOther[chooseRandomPhrase];
	}
	return chosenPhrase;
}

string category::checkIfLetterInPhrase(char chosenLetter, std::string chosenPhrase, std::vector<char> foundCharIndexes)
{
	for (int i = 0; i < chosenPhrase.length(); ++i)
	{
		// if the vector contains this characters index
		if (std::find(foundCharIndexes.begin(), foundCharIndexes.end(), i) != foundCharIndexes.end())
		{
			// it has been found
			std::cout << chosenPhrase[i] << " "; // so print the char
			//foundCount++; // and add one to the count
		}
		else
		{
			// it hasn't been found
			std::cout << "_ ";
		}
	}
	return 0;
}

void cat::category::validVowel(std::vector<char> foundCharIndexes)
{
	vector<char> Vowels{'A', 'E', 'I', 'O', 'U'};

	while (true)
	{
		for (int i = 0; i < Vowels.size(); ++i)
		{
			if (std::find(Vowels.begin(), Vowels.end(), i) != foundCharIndexes.end()) {
				cout << "Please choose a vowel" << endl;
				foundCharIndexes.erase(foundCharIndexes.end());
				continue;
			}
			else
			{
				break;
			}
		}

	}


	
}

void cat::category::validConsonant(char letter)
{

}


