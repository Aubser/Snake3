#include "MultiplayerGamemode.h"


MultiplayerGamemode::MultiplayerGamemode(Panel^ p1Panel, Panel^ p2panel)
{
	// Create new fields for the multiplayer gamemode
	p1Game = new ClassicGamemode(p1Panel, true);
	p2Game = new ClassicGamemode(p2panel, true);
	p2Game->setisP2(true);
}

MultiplayerGamemode::~MultiplayerGamemode()
{
	delete p1Game;
	delete p2Game;
}

void MultiplayerGamemode::initialize(int x, int y)
{
	p1Game->initialize(5, 5);
	p2Game->initialize(5, 5);
}

//What would we need to include in the play method?
void MultiplayerGamemode::play(char m, char w)
{
	if (!p1Game->isGameOver())
	{
		p1Time++;
		p1Game->play(m);
	}

	if (!p2Game->isGameOver())
	{
		p2Time++;
		p2Game->play(w);
	}


}

// will need to change this one
bool MultiplayerGamemode::isGameOver()
{
	if (p1Game->isGameOver() && p2Game->isGameOver())
	{
		if (p1Game->getScore() > p2Game->getScore())
		{
			winningPlayer = 1;
			winningScore = p1Game->getScore();
		}
		else if (p2Game->getScore() > p1Game->getScore())
		{
			winningPlayer = 2;
			winningScore = p2Game->getScore();
		}
		else
		{
			if (p1Time > p2Time)
			{
				winningPlayer = 1;
			}
			else if (p2Time > p1Time)
			{
				winningPlayer = 2;
			}
			else
			{
				winningPlayer = 0;
			}
		}
		return true;
	}
	else
		return false;
}

