#include "SnakeGame.h"

SnakeGame::SnakeGame(char newselectedGamemode, Panel^ gamePanel)
{
	selectedGamemode = newselectedGamemode;
	if (newselectedGamemode == 'C')
	{
		cGame = new ClassicGamemode(gamePanel, false);
	}
	else if (newselectedGamemode == 'B')
	{
		bGame = new MysteryBoxGamemode(gamePanel);
	}
}

SnakeGame::SnakeGame(char newselectedGamemode, Panel^ p1Panel, Panel^ p2Panel)
{
	selectedGamemode = newselectedGamemode;
	mGame = new MultiplayerGamemode(p1Panel, p2Panel);
}

SnakeGame::~SnakeGame()
{
	if (selectedGamemode == 'C')
	{
		delete cGame;
	}
	else if (selectedGamemode == 'M')
	{
		delete mGame;
	}
	else if (selectedGamemode == 'B')
	{
		delete bGame;
	}
}

void SnakeGame::initializeGame()
{
	if (selectedGamemode == 'C')
	{
		cGame->initialize(SOLO_START, SOLO_START);
	}
	else if (selectedGamemode == 'M')
	{
		mGame->initialize(SOLO_START, SOLO_START);
	}
	else if (selectedGamemode == 'B')
	{
		bGame->initialize(SOLO_START, SOLO_START);
	}
}

void SnakeGame::play(char m, char w, Timer^ gameTimer)
{
	if (selectedGamemode == 'C' && !cGame->isGameOver())
	{
		cGame->play(m);
	}
	else if (selectedGamemode == 'M' && !mGame->isGameOver())
	{
		mGame->play(m, w);
	}
	else if (selectedGamemode == 'B' && !bGame->isGameOver(gameTimer))
	{
		bGame->play(m, gameTimer);
	}
	else
	{
		gameOver = true;
	}
}

bool SnakeGame::isGameOver()
{
	return gameOver;
}

void SnakeGame::addHighScore(string name)
{
	HighScores highscores;

	if (selectedGamemode == 'C')
	{

		highscores.addScore(cGame->getScore(), name);

	}
	else if (selectedGamemode == 'B')
	{

	}
	else
	{
		return;
	}

	highscores.updateFile();
}

