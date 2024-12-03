#include "velocity.h"


// Put your velocity methods here
Velocity::Velocity(float dx, float dy)
{
   this->dx = dx;
   this->dy = dy;
}

void Velocity::setDx(float dx)
{
   this->dx = dx;
}

float Velocity::getDx()
{
   return dx;
}

void Velocity::setDy(float dy)
{
   this->dy - dy;
}

float Velocity::getDy()
{
   return dy;
}
