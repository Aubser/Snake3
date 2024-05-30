#pragma once
#include "Gamemode.h"
#include "HighScores.h"
#include "Field.h"
#include "Player.h"

class ClassicGamemode
{
private:
	Field* classicField;
	HighScores* highscore;
	Player* player1;
	static const int STARTING_SIZE = 3;
	int score = 0;
	bool startGame;
	bool isP2 = false;
public:
	ClassicGamemode(Panel^ newDrawingPanel, bool isM);
	~ClassicGamemode();
	void initialize(int x, int y);
	void play(char m);
	void updateScore();
	int getScore() { return score; }
	bool isGameOver();
	void setisP2(bool in) { isP2 = in; }
};