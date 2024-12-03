/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "rocks.h"
#include "flyingObject.h"

#define OFF_SCREEN_BORDER_AMOUNT 5

class Game
{
   private:
      Point topLeft;
      Point bottomRight;
      std::vector<Rock*> rocks;
      Rock * rock = NULL;
   public:
      Game(Point tl, Point br);
      ~Game();  
      void advance();
      void advanceRocks(std::vector<Rock*> & rocks);
      void startAsteroids(std::vector<Rock*> &rocks);
      bool isOnScreen(const Point & point);
      void draw(const Interface & ui);
      void handleInput(const Interface & ui);    
};

#endif /* GAME_H */
