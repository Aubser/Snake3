#pragma once
#include "SnakeHeadTile.h"
#include <iostream>
using namespace std;
class Snake
{
private: 
   // constant characters for direction
   enum Direction : char { UP = 'U', DOWN = 'D', LEFT = 'L' , RIGHT = 'R' };
   char direction;

   
   int length; // length of the snake
   int headRow; // row the head of the snake is in
   int headCol; // column the head of the snake is in
   int speed; // speed of the snake


public:
   Snake();
   ~Snake(); 
   int getLength() { return length; } // getter for length
   int getHeadRow() { return headRow; } // getter for headRow
   int getHeadCol() { return headCol; } // getter for headCol
   char getDirection() { return direction; } // getter for direction
   int getSpeed() { return speed; } // getter for speed

   void setLength(int x) { length = x; } // setter for length
   void setHeadRow(int x) { headRow = x; } // setter for headRow
   void setHeadCol(int x) { headCol = x; } // setter for headCol
   void setDirection(char c) { direction = c; } // setter for direction
   void setSpeed(int x) { speed = x; } // setter for speed

   bool p2ChangeDirection(char input);
   void move(); // method to move a player's snake
   void increaseLength(int increase); // increases the length of the player
   bool changeDirection(char input); // method for when the snake changes direction
   bool inverseChangeDirection(char input); //inverses the snake's control; for mysteryBoxGamemode
   void changeSpeed(int speedChange); // method for changing the snakes speed
};
