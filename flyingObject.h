#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"


// Put your FlyingObject class here
class FlyingObject
{
   protected:
      Point point;
      Velocity velocity;
      bool alive;
      float angle;
   public:
      FlyingObject() { point = 0.0, 0.0; velocity : 0.0, 0.0; alive = true; angle = 0.0; }
      virtual ~FlyingObject() { }
      FlyingObject(const FlyingObject & flyingObject) { }
      void setPoint(Point point) { this->point = point; }
      Point getPoint() { return point; }
      void setVelocity(Velocity velocity) { this->velocity = velocity; }
      Velocity getVelocity() { return velocity; }
      void setAngle(float angle) { this->angle = angle; }
      float getAngle() { return angle; }
      float randomAngle();
      bool isAlive() { return alive; }
      void kill() { alive = false; }
      virtual void advance();
      virtual void draw();
};

#endif /* flyingObject_h */
