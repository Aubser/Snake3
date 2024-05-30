#pragma once
#include <vector>
#include <vcclr.h>
#include "Tile.h"
#include "FruitTile.h" //for spawning fruit; might be bad design
#include "MysteryBoxTile.h" //for spawning mystery boxes
#include "EmptyTile.h" //for initializing the field
#include "SnakeHeadTile.h" //for initializing the snake
#include "SnakeTailTile.h"
#include "SnakeBodyTile.h"
#include "SnakeTile.h"
#include <random>

using namespace std;

class Field
{
private:
   static const int MAX_FRUIT_TILES = 1; //only one fruit spawns at a time
   int fruitCounter;

   static const int MAX_MYSTERY_TILES = 2;   //only 5 mystery boxes on the field at once
   int mysteryBoxCounter;

   int numToIncreaseSnake;       //number of snake tiles to insert

   char collidedWith;      //this tracks what the snake collides with; default is empty tile

   int rowLength;
   int colLength;
   Tile*** field;
   vector<SnakeTile*> snake;
   gcroot<Panel^> drawingPanel;
   gcroot<Bitmap^> doubleBuffer; //for double buffering, aka smoother animation
public:
   Field(Panel^ newDrawingPanel);   //still need to initialize it after creating it
   Field(Panel^ newDrawingPanel, int rowSize, int colSize);    //still need to initialize it after creating it
   ~Field();
   void increaseNumToIncreaseSnake(int newNumToIncreaseSnake) { numToIncreaseSnake += newNumToIncreaseSnake; }

   char getCollidedWith();

   int getRowLength();
   void setRowLength(int newRowLength);
   int getColLength();
   void setColLength(int newColLength);

   void initializeField(int headXLocation, int headYLocation, int snakeLength);
   void drawField();
   void updateSnake(int headXlocation, int headYlocation, char headDirection); 
   void spawnFruit();            //moved from the tile classes themselves
   void spawnMysteryBoxTile();
};
