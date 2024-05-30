#pragma once
#include "SnakeTile.h"

class SnakeTailTile : public SnakeTile
{
public:
   SnakeTailTile(int row, int col);
   ~SnakeTailTile();
   void draw(Bitmap^ doubleBuffer, int xLocation, int yLocation);
};