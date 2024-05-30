#include "SnakeHeadTile.h"

SnakeHeadTile::SnakeHeadTile(int row, int col)
{
   this->row = row;
   this->col = col;
   direction = RIGHT;
   type = 'H';
   tileImage = gcnew Bitmap("SnakeHead.bmp");
}
SnakeHeadTile::~SnakeHeadTile() {}
void SnakeHeadTile::draw(Bitmap^ doubleBuffer, int xLocation, int yLocation)
{
   Graphics^ g = Graphics::FromImage(doubleBuffer);
   if (direction == UP)
   {
      tileImage->RotateFlip(RotateFlipType::Rotate270FlipNone);
      g->DrawImageUnscaled(tileImage, xLocation, yLocation);
      tileImage->RotateFlip(RotateFlipType::Rotate90FlipNone);

   }
   else if (direction == DOWN)
   {
      tileImage->RotateFlip(RotateFlipType::Rotate90FlipNone);
      g->DrawImageUnscaled(tileImage, xLocation, yLocation);
      tileImage->RotateFlip(RotateFlipType::Rotate270FlipNone);
   }
   else if (direction == LEFT)
   {
      tileImage->RotateFlip(RotateFlipType::RotateNoneFlipX);
      g->DrawImageUnscaled(tileImage, xLocation, yLocation);
      tileImage->RotateFlip(RotateFlipType::RotateNoneFlipX);
   }
   else
      g->DrawImageUnscaled(tileImage, xLocation, yLocation);

}