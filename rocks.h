#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#define _USE_MATH_DEFINES

#include "flyingObject.h"
#include "uiDraw.h"
#include "math.h"


// Define the following classes here:
//   Rock
class Rock : public FlyingObject
{
   protected:
      bool collision;
      bool rotateLeft;
      int spin;
   public:
      Rock() { collision = false; spin = 0; rotateLeft = true; }
      ~Rock() { alive = false; }
      Rock(const Rock & rocks) { collision = false; spin = 0; rotateLeft = true; }
      Point getRandomPoint();
      bool isRotateLeft();
      void setRotateLeft();
      void setSpin(float spin) { this->spin = spin; }
      float getSpin() { return spin; }
      bool getCollision() { return collision; }
      void setCollision(bool collision) { this->collision = collision; }
      virtual void advance() = 0;
      virtual void draw() = 0;
};

//   BigRock
class BigRock : public Rock
{
   public:
      BigRock() { collision = false; spin = 0; rotateLeft = true; }
      ~BigRock() { alive = false; }
      BigRock(const BigRock & bigRock) { collision = false; spin = 0; rotateLeft = true; }
      void advance();
      void draw();
};
//   MediumRock
class MediumRock : public Rock
{
   public:
      MediumRock() { }
      ~MediumRock() { }
      MediumRock(const MediumRock & mediumRock) { }
      virtual void advance();
      virtual void draw();
};
//   SmallRock
class SmallRock : public Rock
{
   public:
      SmallRock() { }
      ~SmallRock() { }
      SmallRock(const SmallRock & smallRock) { }
      virtual void advance();
      virtual void draw();
};



#endif /* rocks_h */
