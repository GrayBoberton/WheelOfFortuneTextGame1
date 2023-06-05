// WheelOfFortuneTextGame1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "CategoriesAndPhrases.h"
#include "Wheel.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <mmsystem.h>
#include <vector>
#pragma comment(lib, "winmm.lib")

using namespace cat;
//using namespace wheel;
using namespace std;

bool solved = false;

struct Player {
	string name;
	int money;
	bool hasMillion = false;
};

int main()
{
	const int NUM_ROUNDS = 5;
	int roundNum = 1;

	// Initializes a random seed for the game
	srand(time(NULL));

	cout << "Welcome to WHEEL OF FORTUNE!" << endl;

	/*
	cout << "How many people are playing? (1-3) ";
	int numPlayers = 0;
	cin >> numPlayers;
	*/

	Player one;
	one.money = 500;
	cout << "Please enter a name for your player! ";
	cin >> one.name;

	const int NUM_CATEGORIES = 3;
	category cat;

	wheel::Wheel wheel;

	string categoryName = "";
	string phrase = "";

	
	while (roundNum <= NUM_ROUNDS) {

		solved = false;

		categoryName = cat.pickCategory(NUM_CATEGORIES);
		phrase = cat.pickPhrase(categoryName);
		
		if (phrase != "") {
			cout << categoryName << endl;
			cout << phrase << endl << endl;
			Sleep(1000);
		}
		else {
			categoryName = cat.pickCategory(NUM_CATEGORIES);
			phrase = cat.pickPhrase(categoryName);
		}
		
		vector<char> foundCharIndexes {};

		int roundMoney = 0;

		while (solved == false) {

			char playerLetterInput;
			int playerInput = 0;

			cout << "Money: " << one.money << endl;
			cout << "1. Spin Wheel\n"
				<< "2. Buy Vowel\n"
				<< "3. Solve Puzzle" << endl;
			cin >> playerInput;

			if (playerInput == 1) {
				playerInput = 0;
				system("cls");
				string wedge = wheel.spinWheel(roundNum);

				system("cls");

				if (wedge == "ONE MILLION") {
					wedge = "ONE MILLION";
					cout << wedge << endl << endl;
					one.hasMillion = true;
				}
				else if (wedge == "BANKRUPT") {
					wedge = "BANKRUPT";
					cout << wedge;
					PlaySound(TEXT("bankrupt.wav"), NULL, SND_FILENAME);
					roundMoney = 0;
				}
				else if (wedge == "LOSE A TURN") {
					wedge = "LOSE A TURN";
					cout << wedge << endl << endl;

				}
				else {
					int wedgeInt = stoi(wedge);
					cout << wedgeInt << endl;
				}
				Sleep(1000);


			}
			else if (playerInput == 2) {
				playerInput = 0;
				if (one.money < 250) {
					cout << "You don't have enough money" << endl;
				}
				else {
					cout << "Choose a vowel! (A, E, I, O , U) ";
					cin >> playerLetterInput;

					playerLetterInput = toupper(playerLetterInput);
					foundCharIndexes.push_back(cat.validVowel(foundCharIndexes, playerLetterInput));
					for (int i = 0; i < foundCharIndexes.size(); i++)
					{
						cout << foundCharIndexes.at(i) << " ";
					}
				}
			}
			else if (playerInput == 3) {
				playerInput = 0;
				string solveGuess = "";
				cout << "Please input your guess! ";
				cin >> solveGuess;

				toupper(solveGuess);

				if (solveGuess == phrase) 
				{
					solved = true;
					roundNum++;
				}
				else
				{
					cout << "Sorry that is incorrect." << endl;
					Sleep(5000);
					//continue;
				}
			}
		}
		//roundNum++;
	}
	
}
