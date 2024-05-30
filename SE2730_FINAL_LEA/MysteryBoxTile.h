#pragma once
#include "Tile.h"

class MysteryBoxTile : public Tile
{
public:
   MysteryBoxTile();
   ~MysteryBoxTile();
   void mysteryBoxEffect();
   void draw(Bitmap^ doubleBuffer, int xLocation, int yLocation);

};
