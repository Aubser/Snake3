#pragma once
#include <vcclr.h>  //included for gcroot definition

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class Tile
{
protected:
	gcroot<Drawing::Bitmap^> tileImage;
	char type;	//distinquishes between different tile types;
					//E = Empty, F = Fruit, M = MysteryBox, S = SnakeTile
					//H = SnakeHeadTile, T = SnakeTailTile, W = wall
public:
	virtual void draw(Bitmap^ doubleBuffer, int xLocation, int yLocation) = 0;
	virtual char getType() { return type; }
	virtual void setDirection(char newDirection) {}; //probably bad programming; see if better way later
};
