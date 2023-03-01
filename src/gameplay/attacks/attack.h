
#ifndef ATTACK_H 
#define ATTACK_H

#include "../../rendering/rendering.h"

#include <string>

class ATTACK : private IMAGE {

public:

  // pos of the attack
  int x, y;
  // size of the attack
  int width, height;

  // the begining code
  void init(
    SDL_Renderer * renderer, 
    const std::string asset_path
  );
  
  // drawing the attack out
  void draw_attack(
    SDL_Renderer * renderer, 
    SDL_Window * window
  );

};

// attack script file
void attacks(
  // drawing surfaces
  SDL_Renderer *renderer, 
  SDL_Window * window,
  // heart's pos and size
  int heart_x, int heart_y,
  int heart_width, int heart_height,
  // how many turns have passed 
  int turn_cycle, 
  // if it's scout's turn
  bool & scout_turn,
  // the players remaining HP
  int & HEART_HP
);

#endif // ATTACK_H
