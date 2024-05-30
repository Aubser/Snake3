#include "SnakeBodyTile.h"

SnakeBodyTile::SnakeBodyTile(int row, int col)
{
   this->row = row;
   this->col = col;
   type = 'S';
   direction = RIGHT;
   tileImage = gcnew Drawing::Bitmap("SnakeBody.bmp");
}
SnakeBodyTile::~SnakeBodyTile() {}
void SnakeBodyTile::draw(Bitmap^ doubleBuffer, int xLocation, int yLocation)
{
	this->getDirection();
	
   Graphics^ g = Graphics::FromImage(doubleBuffer);
   g->DrawImageUnscaled(tileImage, xLocation, yLocation);
}