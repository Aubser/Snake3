#pragma once
#include "SnakeTile.h"

class SnakeHeadTile : public SnakeTile
{
public:
   SnakeHeadTile(int row, int col);
   ~SnakeHeadTile();
   void draw(Bitmap^ doubleBuffer, int xLocation, int yLocation);
};