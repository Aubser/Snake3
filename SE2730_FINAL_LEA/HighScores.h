#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//----------------------------------
// Format of the text file:
//		scores    initials
//----------------------------------


class HighScores
{
private:
	static const int MAX_HIGH_SCORES = 5;

	ifstream readHighScores;
	ofstream writeHighScores;

	multimap<int, string> scoresAndInitials;
public:
	HighScores(); // default constructor
	~HighScores(); // default destructor

	bool checkIfAdd(int score);
	void addScore(int score, string initial);
	void updateFile();
};
