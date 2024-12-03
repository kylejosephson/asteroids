#ifndef VELOCITY_H
#define VELOCITY_H


// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project
class Velocity
{
   protected:
      float dx;
      float dy;
   public:
      Velocity() : dx(0.0), dy(0.0) { }
      ~Velocity() { dx = 0.0, dy = 0.0; }
      Velocity(const Velocity & velocity) { }
      Velocity(float dx, float dy);
      void setDx(float dx);
      float getDx();
      void setDy(float dy);
      float getDy();
};


#endif /* velocity_h */
