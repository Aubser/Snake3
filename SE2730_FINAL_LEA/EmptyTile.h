#pragma once
#include "Tile.h"

class EmptyTile : public Tile
{
public:
	EmptyTile();
	~EmptyTile();
	void draw(Bitmap^ doubleBuffer, int xLocation, int yLocation);
};
