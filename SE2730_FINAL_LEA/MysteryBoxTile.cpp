#include "MysteryBoxTile.h"

MysteryBoxTile::MysteryBoxTile()
{
   type = 'M';
   tileImage = gcnew Bitmap("MysteryBox.bmp");
}
MysteryBoxTile::~MysteryBoxTile() {}
//have this been under the snake class so it can directly affect the snake
void MysteryBoxTile::mysteryBoxEffect()
{

}
void MysteryBoxTile::draw(Bitmap^ doubleBuffer, int xLocation, int yLocation)
{
   Graphics^ g = Graphics::FromImage(doubleBuffer);
   g->DrawImage(tileImage, xLocation, yLocation, 50, 50);
}