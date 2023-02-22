
#ifndef SCOUT_H
#define SCOUT_H

// for image class
#include "../../rendering/rendering.h"
#include <SDL.h>

class SCOUT : public IMAGE {

public:

  SDL_Texture * head;
  SDL_Texture * torso;
  SDL_Texture * legs;


  // when class is out of scope
  ~SCOUT();
  // when the class is created
  SCOUT(SDL_Renderer * renderer);

  int x=0, y=0;

  void draw_scout(SDL_Renderer * renderer, SDL_Window * window);

};

#endif // SCOUT_H