#pragma once
#include "SnakeTile.h"

class SnakeBodyTile : public SnakeTile
{
public:
   SnakeBodyTile(int row, int col);
   ~SnakeBodyTile();
   void draw(Bitmap^ doubleBuffer, int xLocation, int yLocation);
};
