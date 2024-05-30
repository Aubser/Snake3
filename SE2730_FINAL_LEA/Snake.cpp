#include "Snake.h"

// constructor
Snake::Snake()
{
   length = 1; // starting length of the snake
   headRow = 5; // starting position values, can be changed
   headCol = 5; // starting position values, can be changed
   direction = RIGHT; // starting direction moving right
   speed = 1; // default speed value
}

// destructor
Snake::~Snake()
{
   length = 0;
   headRow = 0;
   headCol = 0;
   direction = RIGHT;
   speed = 0;
}

// increases the length of the snake by one
void Snake::increaseLength(int increase)
{
   length += increase;
}

// returns true if the snake
bool Snake::changeDirection(char input)
{
   // Makes sure the snake isn't already going in the same direction as
   // the proposed change as well as making sure that the snake doesn't 
   // perform a 180 degree turn. If these conditions are met, the 
   // function returns true, otherwise returns false.

   cin >> input;
   if ((input == 'w' || input == 'W') && direction != UP && direction != DOWN)
   {
      direction = UP;
      return true;
   }
   else if ((input == 'a' || input == 'A') && direction != LEFT && direction != RIGHT)
   {
      direction = LEFT;
      return true;
   }
   else if ((input == 's' || input == 'S') && direction != UP && direction != DOWN)
   {
      direction = DOWN;
      return true;
   }
   else if ((input == 'd' || input == 'D') && direction != LEFT && direction != RIGHT)
   {
      direction = RIGHT;
      return true;
   }
   else
      return false;
}

bool Snake::p2ChangeDirection(char input)
{
    // Makes sure the snake isn't already going in the same direction as
    // the proposed change as well as making sure that the snake doesn't 
    // perform a 180 degree turn. If these conditions are met, the 
    // function returns true, otherwise returns false.

    cin >> input;
    if ((input == 'i' || input == 'I') && direction != UP && direction != DOWN)
    {
        direction = UP;
        return true;
    }
    else if ((input == 'j' || input == 'J') && direction != LEFT && direction != RIGHT)
    {
        direction = LEFT;
        return true;
    }
    else if ((input == 'k' || input == 'K') && direction != UP && direction != DOWN)
    {
        direction = DOWN;
        return true;
    }
    else if ((input == 'l' || input == 'L') && direction != LEFT && direction != RIGHT)
    {
        direction = RIGHT;
        return true;
    }
    else
        return false;
}

bool Snake::inverseChangeDirection(char input)
{
   cin >> input;
   if ((input == 'w' || input == 'W') && direction != UP && direction != DOWN)
   {
      direction = DOWN;
      return true;
   }
   else if ((input == 'a' || input == 'A') && direction != LEFT && direction != RIGHT)
   {
      direction = RIGHT;
      return true;
   }
   else if ((input == 's' || input == 'S') && direction != UP && direction != DOWN)
   {
      direction = UP;
      return true;
   }
   else if ((input == 'd' || input == 'D') && direction != LEFT && direction != RIGHT)
   {
      direction = LEFT;
      return true;
   }
   else
      return false;
}

// changes the speed of the snake when the snake gets the speed up 
// power up / debuff
void Snake::changeSpeed(int speedChange)
{
   speed += speedChange;
}


// updates the location of the snakes head when it moves
void Snake::move()
{

   if (direction == UP)
   {
      headCol--;
   }
   else if (direction == DOWN)
   {
      headCol++;
   }
   else if (direction == RIGHT)
   {
      headRow++;
   }
   else if (direction == LEFT)
   {
      headRow--;
   }
}
