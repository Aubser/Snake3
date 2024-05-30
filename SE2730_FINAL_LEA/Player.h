#pragma once
#include "Snake.h"
#include "SnakeHeadTile.h"
#include "Field.h"
#include "FruitTile.h"

#include <cstddef>

class Player
{
private:
	// int for the time in a multiplayer game
	int currentTime;


	// int for a players score
	int currentScore;

	// Snake snake;

public:

	Snake* snake; 	// a snake object
	Player();// default constructor
	~Player();// destructor
	int getCurrentScore() { return currentScore; } // get method for currentScore
	int getCurrentTime() { return currentTime; } // get method for currentTime
	void setCurrentScore(int x) { currentScore = x; } // set method for currentScore
	void setCurrentTime(int x) { currentTime = x; } // set method for currentTime
	void increaseScore(int increase); // method to increase the score of a player
	void stopTime(); // method to stop the time in a multiplayer game for a player
	void startTime(); // mehtod to start the time in a multiplayer game for a player





};
