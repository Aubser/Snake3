#include "FruitTile.h"

FruitTile::FruitTile()
{
	type = 'F';
	tileImage = gcnew Bitmap("Fruit.bmp");
}
FruitTile::~FruitTile() {}
void FruitTile::draw(Bitmap^ doubleBuffer, int xLocation, int yLocation)
{
	Graphics^ g = Graphics::FromImage(doubleBuffer);
	g->DrawImageUnscaled(tileImage, xLocation, yLocation);
}