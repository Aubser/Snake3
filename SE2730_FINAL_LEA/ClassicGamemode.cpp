#include "ClassicGamemode.h"
#include "HighScores.h"

ClassicGamemode::ClassicGamemode(Panel^ newDrawingPanel, bool isM)
{
	//Create new field for the classic gamemode
	if (isM)
		classicField = new Field(newDrawingPanel, 10, 10);
	else
		classicField = new Field(newDrawingPanel);
	player1 = new Player();
	//classicField->initializeField(7, 7, STARTING_SIZE);
}

ClassicGamemode::~ClassicGamemode()
{
	delete classicField;
}

void ClassicGamemode::initialize(int x, int y)
{
	classicField->initializeField(x, y, STARTING_SIZE);
	classicField->drawField();
	player1->snake = new Snake();
	player1->snake->setHeadRow(x);
	player1->snake->setHeadCol(y);
}

//What would we need to include in the play method?
void ClassicGamemode::play(char m)
{
	if (!isP2)
		player1->snake->changeDirection(m);
	else
		player1->snake->p2ChangeDirection(m);
	player1->snake->move();
	classicField->updateSnake(player1->snake->getHeadRow(), player1->snake->getHeadCol(), player1->snake->getDirection());
	updateScore();
	classicField->spawnFruit();
	classicField->drawField();
	// Include the number of fruits (maybe a maximum of 5 on the map at once?) and proper location as the condition.
	//Will add more once we finalize other classes.
}

void ClassicGamemode::updateScore()
{
	if (classicField->getCollidedWith() == 'F')
	{
		score++;
	}

}

bool ClassicGamemode::isGameOver()
{

	if (classicField != nullptr && 
		(classicField->getCollidedWith() == 'S'
		|| classicField->getCollidedWith() == 'W'
		|| classicField->getCollidedWith() == 'T'))
	{

		return true;
		//set it to the right for the beginning of the next round
		player1->snake->setDirection('R');
	}
	else
	{
		return false;
	}
}

