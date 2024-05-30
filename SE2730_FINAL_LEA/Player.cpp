#include "Player.h"


// default constructor
Player::Player()
{
	currentScore = 0;
	currentTime = 0;
}

// destructor
Player::~Player()
{
	currentScore = 0;
	currentTime = 0;
}

void Player::increaseScore( int increase)
{
	currentScore++;
}


void Player::stopTime()
{
	/*
	currentTime stops incrementing
	
	
	*/
}

void Player::startTime()
{
	currentTime++;
}


