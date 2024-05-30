#pragma once
#include "Gamemode.h"
#include "HighScores.h"
#include "Field.h"
#include "ClassicGamemode.h"

class MultiplayerGamemode
{
private:
	ClassicGamemode* p1Game;
	ClassicGamemode* p2Game;
	int winningScore = 0;
	int p1Time = 0;
	int p2Time = 0;
	int winningPlayer = 0;

public:
	MultiplayerGamemode(Panel^ p1Panel, Panel^ p2Panel);
	~MultiplayerGamemode();
	void initialize(int x, int y);
	void play(char m, char w);
	bool isGameOver();
	int getWinner() { return winningPlayer; }
	int getP2Score() { return p2Game->getScore(); }
	int getP1Score() { return p1Game->getScore(); }
	int getWinningScore() { return winningScore; }
};