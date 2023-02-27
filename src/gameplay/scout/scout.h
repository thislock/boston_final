
#ifndef SCOUT_H
#define SCOUT_H

// for image class
#include "../../rendering/rendering.h"
#include <SDL.h>

class SCOUT : public IMAGE {

  // scout dodge vars
  int dodge_vel=0;
  int dodge_cycle=0;

  // default positions of the individual body parts
  int head_x=0, head_y=127;
  int torso_x=5, torso_y=80;
  int legs_x=2, legs_y=37;

  int animation_cycle;

  int animate_type = 1;

  int head_state = 0;

  int animate_speed=0;

  bool twos;
  int twos_counter;

  SDL_Texture * head_closed_eyes = nullptr;

public:

  SDL_Texture * head  = nullptr;
  SDL_Texture * torso = nullptr;
  SDL_Texture * legs  = nullptr;

  // when class is out of scope
  ~SCOUT();
  // when the class is created
  SCOUT(SDL_Renderer * renderer);

  // default general pos's
  int x=-4, y=-5;

  // true for attacking, and false for your move, like items, or mercy ect.
  // starts off attacking
  bool scout_turn = false;

  // for when the player attacks, so he can dodge
  bool scout_dodge = false;

  void animate();
  void draw_scout(SDL_Renderer * renderer, SDL_Window * window);

};

#endif // SCOUT_H