
#ifndef SCOUT_H
#define SCOUT_H

// for image class
#include "../../rendering/rendering.h"
#include <SDL.h>

class SCOUT : public IMAGE {

  // default positions of the individual body parts
  int head_x=0, head_y=130;
  int torso_x=5, torso_y=81;
  int legs_x=2, legs_y=37;

public:

  SDL_Texture * head  = nullptr;
  SDL_Texture * torso = nullptr;
  SDL_Texture * legs  = nullptr;

  // when class is out of scope
  ~SCOUT();
  // when the class is created
  SCOUT(SDL_Renderer * renderer);

  // default general pos's
  int x=-4, y=0;

  void draw_scout(SDL_Renderer * renderer, SDL_Window * window);

};

#endif // SCOUT_H