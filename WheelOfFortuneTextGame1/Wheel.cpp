#include "Wheel.h"
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

const int NUM_WEDGES = 24;
const string BANKRUPT_OR_MILL = "bankmill";
const string BANKRUPT = "BANKRUPT";
const string LOSE_TURN = "LOSE A TURN";

vector<string> wheelWedges{ "2500", "500", "600", "700", "600", "650", "500", "700", BANKRUPT_OR_MILL, "600", "550", "500", "600", BANKRUPT, "650", "500", "700", LOSE_TURN, "800", "500", "650", "500", "900", BANKRUPT };

string wheel::Wheel::spinWheel(int roundNum) {
	if (roundNum == 1) {
		wheelWedges[0] = "2500";
	}
	else if (roundNum == 2 || roundNum == 3) {
		wheelWedges[0] = "3500";
	}
	else {
		wheelWedges[0] = "5000";
	}

	int spinStrength = rand() % (3 * NUM_WEDGES) + NUM_WEDGES;
	int slowSpin = 50;
	string chosenWedge = "";

	for (int i = 0; i < spinStrength; i++) {
		chosenWedge = wheelWedges[i % NUM_WEDGES];
		if (chosenWedge == BANKRUPT_OR_MILL) {
			int bankmillChance = rand() % 3 + 1;
			if (bankmillChance == 2) {
				chosenWedge = "ONE MILLION";
			}
			else {
				chosenWedge = "BANKRUPT";
			}
		}
		Sleep(slowSpin);
		system("cls");
		slowSpin += (i * 2);
		if (slowSpin > 200) {
			slowSpin = 200;
		}
		cout << chosenWedge << endl;
	}
	return chosenWedge;
}

std::string wheel::Wheel::spinFinalWheel()
{
	return std::string();
}
