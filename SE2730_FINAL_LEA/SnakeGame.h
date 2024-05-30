#pragma once
#include "ClassicGamemode.h"
#include "MysteryBoxGamemode.h"
#include "MultiplayerGamemode.h"
#include "Player.h"
#include "HighScores.h"

class SnakeGame
{
private:
	ClassicGamemode* cGame;		//we should be using polymorphism with this I think since gamemode is an interface
	MysteryBoxGamemode* bGame;
	MultiplayerGamemode* mGame;
	bool gameOver = false;
	Player player;
	char selectedGamemode;
	static const int SOLO_START = 5;

public:
	SnakeGame(char newSelectedGamemode, Panel^ gamePanel);

	SnakeGame(char newselectedGamemode, Panel^ p1Panel, Panel^ p2Panel);

	~SnakeGame();

	bool getGameOver() { return gameOver; }

	void setGameOver(bool in) { gameOver = in; }

	void play(char m, char w, Timer^ snakeTimer);

	bool isGameOver();

	void initializeGame();
	
	void addHighScore(string name);

	int getCScore() { return cGame->getScore(); }//Change This

	int getBScore() { return bGame->getScore(); }

	int getWinner() { return mGame->getWinner(); }

	int getWinningScore() { return mGame->getWinningScore(); }

	int getP2Score() { return mGame->getP2Score(); }

	int getP1Score() { return mGame->getP1Score(); }

	char getBoxType() { return bGame->getBoxType(); }
};

