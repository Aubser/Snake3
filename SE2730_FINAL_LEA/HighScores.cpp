#include "HighScores.h"

using namespace std;

HighScores::HighScores()
{
   readHighScores.open("HighScores.txt");
   if (readHighScores.is_open())
   {
      int score = 0;
      string initial;
      while (!readHighScores.fail())
      {
         readHighScores >> initial;
         readHighScores >> score;

         if(score > 0)
            scoresAndInitials.insert(pair <int, string>(score, initial));
      }
      readHighScores.close();
   }
}
HighScores::~HighScores()
{
   scoresAndInitials.clear();
}
bool HighScores::checkIfAdd(int score)
{
   multimap<int, string>::iterator it;
   // compare each element int to the score,
   // if higher, return true, if not, return false
   for (it = scoresAndInitials.begin(); it != scoresAndInitials.end(); it++)
   {
      if (score > it->first)
      {
         return true;
      }
   }
   return false;
}

void HighScores::addScore(int score, string initial)
{
   if(scoresAndInitials.size() < MAX_HIGH_SCORES)
   { 
       scoresAndInitials.insert(pair <int, string>(score, initial));
       return;
   }
   multimap<int, string>::iterator it;
   // compare each element and insert the score if applicable, then break
   for (it = scoresAndInitials.begin(); it != scoresAndInitials.end(); it++)
   {
      if (score > it->first)
      {
         scoresAndInitials.insert(pair <int, string>(score, initial));
         break;
      }
   }

   // delete the lowest score(s) till there are only 5 scores left
   while (scoresAndInitials.size() > MAX_HIGH_SCORES)
   {
      it = --scoresAndInitials.end();
      scoresAndInitials.erase(it);
   }
}
void HighScores::updateFile()
{
   //this opens the file and deletes the contents inside (I think)
   writeHighScores.open("HighScores.txt", ofstream::out | ofstream::trunc);

   //heading
   writeHighScores << "High Scores:\n";

   //write each score and initial
   multimap<int, string>::iterator it;
   for (it = scoresAndInitials.begin(); it != scoresAndInitials.end(); it++)
   {
      writeHighScores << it->first << "  " << it->second << endl;
   }
   writeHighScores.close();
}