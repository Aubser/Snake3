#pragma once
#include "Tile.h"

class FruitTile : public Tile
{
public:
	FruitTile();
	~FruitTile();
	void draw(Bitmap^ doubleBuffer, int xLocation, int yLocation);
};