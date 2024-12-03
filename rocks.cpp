#include "rocks.h"

// Put your Rock methods here
bool Rock::isRotateLeft()
{
   return rotateLeft;
}

Point Rock::getRandomPoint()
{
   int x = random(-200, 200);
   int y = random(-200, 200);
   Point tmpPoint(x, y);
   return tmpPoint;
}

void Rock::setRotateLeft()
{
   float left;
   left = random(0,2);
   if (left < 1)
   {
      rotateLeft = false;
   }
   else
   {
      rotateLeft = true;
   }
}


void BigRock::advance()
{
   if (isAlive())
   {
      if (isRotateLeft())
      {
         int temp =  (getSpin() + BIG_ROCK_SPIN) * -1;
         setSpin(temp);
         if (getSpin() < 0)
         {
            setSpin(getSpin() + 360);
         }
      }
      else
      {
         int temp = getSpin() + BIG_ROCK_SPIN;
         setSpin(temp);
         if (getSpin() > 360)
         {
            setSpin( getSpin() - 360);
         }
      }
      velocity.setDx(-cos(M_PI / 180.0 * getAngle()));
      velocity.setDy(sin(M_PI / 180.0 * getAngle()));
      point.addX(velocity.getDx());
      point.addY(velocity.getDy());
   }
}

void BigRock::draw()
{
   drawLargeAsteroid(getPoint(), getSpin());
}

void MediumRock::advance()
{
   if (isAlive())
   {
      if (isRotateLeft())
      {
         int temp = (getSpin() + MEDIUM_ROCK_SPIN) * -1;
         setSpin(temp);
         if (getSpin() < 0)
         {
            setSpin(getSpin() + 360);
         }
      }
      else
      {
         int temp = getSpin() + MEDIUM_ROCK_SPIN;
         setSpin(temp);
         if (getSpin() > 360)
         {
            setSpin(getSpin() - 360);
         }
      }
      velocity.setDx(-cos(M_PI / 180.0 * getAngle()));
      velocity.setDy(sin(M_PI / 180.0 * getAngle()));
      point.addX(velocity.getDx());
      point.addY(velocity.getDy());
   }
}

void MediumRock::draw()
{
   drawMediumAsteroid(getPoint(), getSpin());
}
 
void SmallRock::advance()
{

}

void SmallRock::draw()
{

}
