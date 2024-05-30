#pragma once
#include "Gamemode.h"
#include "HighScores.h"
#include "Field.h"
#include <chrono>
#include <string>

class MysteryBoxGamemode
{
private:
	Field* mysteryBoxField;
	HighScores* mysteryBoxHighscore;
	Player* player1;
	static const int STARTING_SIZE = 3;
	int score = 0;
	bool startGame;
	char boxType = ' ';

	int toggleInverseControls;	//0 = normal controls; 1 = inverse controls
	chrono::high_resolution_clock::time_point startEffectTime;
public:
	MysteryBoxGamemode(Panel^ newDrawingPanel);
	~MysteryBoxGamemode();
	void initialize(int x, int y);
	void play(char m, Timer^ gameTimer);
	void updateScore();
	int getScore() { return score; }
	bool isGameOver(Timer^ gameTimer);
	//Purpose: used to slow down the snake on the instance it is a slowdown mystery box
	// and speed up the snake on the instance it is a speed up mystery box. Need a new play method that passes a timer.
	void mysteryBoxEffect(Timer^ snakeTimer);
	char getBoxType() { return boxType; }
};