/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

Game::Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
{
   rock = NULL;
}

Game::~Game()
{
  delete rock;
  rock = NULL;
}

void Game::advance()
{
   if (rock == NULL)
   {
      startAsteroids(rocks);
   }
   advanceRocks(rocks);
}

void Game::advanceRocks(vector<Rock*> &rocks)
{
   for (vector<Rock*> :: iterator rockIt = rocks.begin(); rockIt != rocks.end(); rockIt++)
   {
      if ((*rockIt)->isAlive())
      {
         (*rockIt)->advance();
      }
   }
}

void Game::startAsteroids(vector<Rock*> &rocks)
{
   for (int i = 0; i < 5; i++)
   {
      Rock * pRock = new BigRock;
      int x = random(-200, 200);
      int y = random(-200, 200);
      Point tmpPoint(x, y);
      pRock->setPoint(tmpPoint);
      float tmpAngle = random(1, 360);
      pRock->setAngle(tmpAngle);
      pRock->setSpin(0);
      pRock->setRotateLeft();
      rocks.push_back(pRock);
      delete pRock;
      pRock = NULL;
   }
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game::isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}


void Game::draw(const Interface & ui)
{
   for (int i = 0; i < rocks.size(); i++)
   {
      if (rocks[i]->isAlive())
      {
         rocks[i]->draw();
      }
   }
}

void Game::handleInput(const Interface & ui)
{

}



// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
/*
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}
*/

