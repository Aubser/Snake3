#pragma once
#include <vcclr.h>      //for gcroot declaration
#include "Tile.h"
#include "EmptyTile.h"  //needed for moving the snake

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class SnakeTile : public Tile
{
protected:
   static const int MAX_SNAKE_TILES;  //make equal to max number of tiles available

   //directions for readability...possibly change to a char enum
   static const char UP = 'U';
   static const char DOWN = 'D';
   static const char LEFT = 'L';
   static const char RIGHT = 'R';

   char direction;

   int row;
   int col;
public:
   char getDirection();
   void setDirection(char newDirection);
   int getRow() { return row; }
   void setRow(int newRow) { row = newRow; }
   int getCol() { return col; }
   void setCol(int newCol) { col = newCol; }
   virtual void draw(Bitmap^ doubleBuffer, int xLocation, int yLocation) = 0;
};