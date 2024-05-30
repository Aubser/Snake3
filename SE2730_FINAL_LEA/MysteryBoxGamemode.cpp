#include "MysteryBoxGamemode.h"

MysteryBoxGamemode::MysteryBoxGamemode(Panel^ newDrawingPanel)
{
   // create a field and a player
   mysteryBoxField = new Field(newDrawingPanel);
   player1 = new Player();
   toggleInverseControls = 0;
   //start the timer and decrement it by 5 seconds
   startEffectTime = chrono::high_resolution_clock::now();
   startEffectTime -= 5s;
}

MysteryBoxGamemode::~MysteryBoxGamemode()
{
   delete mysteryBoxField;
}

void MysteryBoxGamemode::initialize(int x, int y)
{
   mysteryBoxField->initializeField(x, y, STARTING_SIZE);
   mysteryBoxField->drawField();
   player1->snake = new Snake();
   player1->snake->setHeadRow(x);
   player1->snake->setHeadCol(y);
}

void MysteryBoxGamemode::play(char m, Timer^ gameTimer)
{
   chrono::high_resolution_clock::time_point currentEffectTime = chrono::high_resolution_clock::now();
   chrono::duration<double> elapsed = currentEffectTime - startEffectTime;
   if (elapsed.count() < 5.00 && toggleInverseControls == 1)
   {
      player1->snake->inverseChangeDirection(m);
   }
   else if (elapsed.count() > 5.00)
   {
      toggleInverseControls = 0;
      gameTimer->Interval = 200;
      player1->snake->changeDirection(m); // allows the snake to change direction
   }
   else
   {
      player1->snake->changeDirection(m); // allows the snake to change direction
   }
   player1->snake->move(); // move function for the snake
   mysteryBoxField->updateSnake(player1->snake->getHeadRow(), player1->snake->getHeadCol(), player1->snake->getDirection()); 
   if (mysteryBoxField->getCollidedWith() == 'M')
      mysteryBoxEffect(gameTimer);
   updateScore(); // updates the score
   mysteryBoxField->spawnFruit(); // spawns fruit on the map
   mysteryBoxField->spawnMysteryBoxTile(); // spawns mystery boxes 
   mysteryBoxField->drawField(); 
}


void MysteryBoxGamemode::updateScore()
{
   // if the snake collides with the fruit update the score
   if (mysteryBoxField->getCollidedWith() == 'F')
   {
      score++;
   }

   // also need to add functionality for mega fruit power up

}


bool MysteryBoxGamemode::isGameOver(Timer^ gameTimer)
{
   if (mysteryBoxField != nullptr &&
      (mysteryBoxField->getCollidedWith() == 'S'
         || mysteryBoxField->getCollidedWith() == 'W'
         || mysteryBoxField->getCollidedWith() == 'T'))
   {
      //set it to the right for the beginning of the next round
      player1->snake->setDirection('R');
      gameTimer->Interval = 200;
      return true;
   }
   else
   {
      return false;
   }
}

void MysteryBoxGamemode::mysteryBoxEffect(Timer^ snakeTimer)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 3);
    int mysteryBoxType = distribution(gen);
    //0 = MegaFruit, 1 = Slow Down, 2 = Speed Up, 3 = Inverse Controls(handled in play method)
    if (mysteryBoxType == 0)
    {
       mysteryBoxField->increaseNumToIncreaseSnake(5);
       score += 5;
       boxType = 'M';
    }
    else if (mysteryBoxType == 1)
    {
       snakeTimer->Interval = 400;
       boxType = 'S';
    }
    else if (mysteryBoxType == 2)
    {
       snakeTimer->Interval = 100;
       boxType = 'F';
    }
    else
    {
       toggleInverseControls = 1;
       boxType = 'I';
    }
    //start the timer essentially
    startEffectTime = chrono::high_resolution_clock::now();
}
