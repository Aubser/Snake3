#include "Field.h"

Field::Field(Panel^ newDrawingPanel)
{
   rowLength = 12; //change later
   colLength = 22; //change later

   fruitCounter = 0;
   mysteryBoxCounter = 0;
   numToIncreaseSnake = 0;

   collidedWith = 'E';
   
   //initialize the field
   field = new Tile ** [rowLength];
   for (int i = 0; i < rowLength; i++)
   {
      field[i] = new Tile*[colLength];
   }

   drawingPanel = newDrawingPanel;

   //initialize a bitmap for double buffering
   doubleBuffer = gcnew Bitmap(drawingPanel->Width, drawingPanel->Height);
}

Field::Field(Panel^ newDrawingPanel, int rowSize, int colSize)
{
   rowLength = rowSize;
   colLength = colSize;

   drawingPanel = newDrawingPanel;

   //initialize a bitmap for double buffering
   doubleBuffer = gcnew Bitmap(drawingPanel->Width, drawingPanel->Height);

   field = new Tile * *[rowLength];
   for (int i = 0; i < rowLength; i++)
   {
       field[i] = new Tile * [colLength];
   }

   fruitCounter = 0;
   mysteryBoxCounter = 0;
   numToIncreaseSnake = 0;

   collidedWith = 'E';
}
Field::~Field()
{
   for (int i = 0; i < rowLength; i++)
   {
      //delete every tile
      for (int j = 0; j < colLength; j++)
      {
         delete field[i][j];
      }
      //delete each column
      delete field[i];
   }

   //delete final pointer
   delete field;
}
char Field::getCollidedWith()
{
   return collidedWith;
}
int Field::getRowLength()
{
   return rowLength;
}
void Field::setRowLength(int newRowLength)
{
   rowLength = newRowLength;
}
int Field::getColLength()
{
   return colLength;
}
void Field::setColLength(int newColLength)
{
   colLength = newColLength;
}

void Field::initializeField(int headXLocation, int headYLocation, int snakeLength)
{
   //initialize each tile to empty
   for (int i = 0; i < rowLength; i++)
   {
      for (int j = 0; j < colLength; j++)
      {
         field[i][j] = new EmptyTile();
      }
   }


   //initialize the snake vector and in the field
   //initialize the head
   SnakeHeadTile* snakeHead = new  SnakeHeadTile(headYLocation, headXLocation);
   field[headYLocation][headXLocation] = snakeHead;
   snake.push_back(snakeHead);
   //initialize each body part
   for (int i = 1; i < snakeLength - 1; i++)
   {
      SnakeBodyTile* snakeBody = new SnakeBodyTile(headYLocation, headXLocation - i);
      field[headYLocation][headXLocation - i] = snakeBody;
      snake.push_back(snakeBody);
   }
   //initialize the tail
   SnakeTailTile* snakeTail = new SnakeTailTile(headYLocation, headXLocation - (snakeLength - 1));
   field[headYLocation][headXLocation - (snakeLength - 1)] = snakeTail;
   snake.push_back(snakeTail);
}
void Field::drawField()
{
   int xLocation;
   int yLocation;

   for (int i = 0; i < rowLength; i++)
   {
      for (int j = 0; j < colLength; j++)
      {
         //find top left corner
         xLocation = 50 * i;
         yLocation = 50 * j;

         //use polymorphism to draw each tile
         field[i][j]->draw(doubleBuffer, yLocation, xLocation);   //switched these around; fix drawing
      }
   }
   //draw to the panel
   Graphics^ g = drawingPanel->CreateGraphics();
   g->DrawImageUnscaled(doubleBuffer, 0, 0);
}

void Field::updateSnake(int headXlocation, int headYlocation, char headDirection)  //pass head coordinates
{
   //add a condition to see if the field location for the new head is a snake
   if (headXlocation < colLength && headXlocation >= 0
      && headYlocation < rowLength && headYlocation >= 0)
   {
      //find what it collided with
      collidedWith = field[headYlocation][headXlocation]->getType();
      if (collidedWith == 'S' || collidedWith == 'T')
      {
         return;
      }

      int snakeSize = snake.size();

      //capture the coordinates of the head
      int newrow = snake[0]->getRow();
      int newcol = snake[0]->getCol();
      char newdirection = snake[0]->getDirection();

      //move the head by setting its row and col to the head coordinates;
      //in whatever gamemode, flip the order and update head coordinates then updateSnake
      snake[0]->setRow(headYlocation);
      snake[0]->setCol(headXlocation);
      snake[0]->setDirection(headDirection);

      int currentrow;
      int currentcol;
      char currentDirection;
      for (int i = 1; i < snakeSize - 1; i++)
      {
         //capture the current snake parts' coordinates
         currentrow = snake[i]->getRow();
         currentcol = snake[i]->getCol();
         currentDirection = snake[i]->getDirection();
         //update the current snake parts coordinates to the new location
         snake[i]->setRow(newrow);
         snake[i]->setCol(newcol);
         snake[i]->setDirection(newdirection);
         //put the variables for the next snake's new location equal to the captured current snake's previous coordinates
         newrow = currentrow;
         newcol = currentcol;
         //this way the tail will be facing the body no matter what
         if (i != snakeSize - 2)
            newdirection = currentDirection;
      }

      //capture the current snake parts' coordinates
      currentrow = snake[snakeSize - 1]->getRow();
      currentcol = snake[snakeSize - 1]->getCol();
      if (numToIncreaseSnake == 0)
      {
         //update the current snake parts coordinates to the new location
         snake[snakeSize - 1]->setRow(newrow);
         snake[snakeSize - 1]->setCol(newcol);
         snake[snakeSize - 1]->setDirection(newdirection);

         //newrow and newcol hold the tails previous coordinates
         //set that location in field to an empty tile
         field[currentrow][currentcol] = new EmptyTile();
      }
      else
      {
         //insert a new body tile into the snake and don't move the tail
         std::vector<SnakeTile*>::iterator it = snake.end() - 1;
         SnakeTile* newSnakeBodyPart = new SnakeBodyTile(newrow, newcol);
         it = snake.insert(it, newSnakeBodyPart);
         numToIncreaseSnake--;
      }

      
      //reset counters if necessary
      if (collidedWith == 'F')
      {
         fruitCounter -= 1;
         numToIncreaseSnake++;
      }
      if (collidedWith == 'M')
         mysteryBoxCounter -= 1;
      //delete the thing the snake collided with and set that pointer equal to the head
      delete field[headYlocation][headXlocation];
      field[headYlocation][headXlocation] = snake[0];

      //change the field pointers of the body and tail
      for (int i = 1; i < snakeSize; i++)
      {
         //find where in the field to put it
         int rowToSet = snake[i]->getRow();
         int colToSet = snake[i]->getCol();
         field[rowToSet][colToSet] = snake[i];
      }
   }
   else
   {
      collidedWith = 'W';
   }
}
void Field::spawnFruit()
{
   if (fruitCounter < MAX_FRUIT_TILES)
   {
      bool fruitSpawned = false;
      while (!fruitSpawned)   //need to check for max tiles otherwise infinite loop!
      {
         //random number generator; much better than rand
         std::random_device rd;
         std::mt19937 gen(rd());
         std::uniform_int_distribution<int> distribution(0, rowLength - 1);
         //make a random y
         int newRow = distribution(gen);

         //reset the gen
         std::random_device rand;
         std::mt19937 generator(rand());
         std::uniform_int_distribution<int> newDistribution(0, colLength - 1);

         //make a random x
         int newCol = newDistribution(generator);

         //check if tile is empty, if so make a fruit tile
         if (field[newRow][newCol]->getType() == 'E')
         {
            field[newRow][newCol] = new FruitTile();
            fruitSpawned = true;
            fruitCounter++;
         }
      }
   }
}
void Field::spawnMysteryBoxTile()
{
   if (mysteryBoxCounter < MAX_MYSTERY_TILES)
   {
      //do it until a mystery box is spawned
      bool mysteryBoxSpawned = false;
      while (!mysteryBoxSpawned) //need to check for max tiles otherwise infinite loop!
      {
         //random number generator; much better than rand
         std::random_device rd;
         std::mt19937 gen(rd());
         std::uniform_int_distribution<int> distribution(0, rowLength - 1);
         //make a random y
         int newRow = distribution(gen);

         //reset the gen
         std::random_device rand;
         std::mt19937 generator(rand());
         std::uniform_int_distribution<int> newDistribution(0, colLength - 1);

         //make a random x
         int newCol = newDistribution(generator);

         if (field[newRow][newCol]->getType() == 'E')
         {
            field[newRow][newCol] = new MysteryBoxTile();
            mysteryBoxSpawned = true;
            mysteryBoxCounter++;
         }
      }
   }
}