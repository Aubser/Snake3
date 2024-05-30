#include "EmptyTile.h"

EmptyTile::EmptyTile()
{
   type = 'E';
   tileImage = gcnew Bitmap("EmptyTile.bmp");
}
EmptyTile::~EmptyTile() {}
void EmptyTile::draw(Bitmap^ doubleBuffer, int xLocation, int yLocation)
{
   Graphics^ g = Graphics::FromImage(doubleBuffer);
   g->DrawImageUnscaled(tileImage, xLocation, yLocation);
	
}