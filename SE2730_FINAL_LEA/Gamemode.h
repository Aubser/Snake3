#pragma once
#include "Player.h"
class Gamemode
{
protected:
	bool startGame;
	Player* player1;
	Player* player2;
	const static int STARTING_SIZE = 3;
	int score = 0;
	int score2 = 0;
public:
	bool getStart() { return startGame; }
	void setStart(bool newStart) { startGame = newStart; }
	virtual void initialize(int x, int y) = 0;
	virtual void play(char m) = 0;
	virtual void updateScore() = 0;
	virtual bool isGameOver() = 0;
	int getScore() { return score; }
};
