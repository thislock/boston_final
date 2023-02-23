#ifndef HEART_H
#define HEART_H

#include "../../rendering/rendering.h"
#include <string>

#define heart_vel 3

class HEART : public IMAGE {

  bool heartvel_up    = false;
  bool heartvel_down  = false;
  bool heartvel_left  = false;
  bool heartvel_right = false;

public:
  
  // for setting the initial default texture
  HEART(SDL_Renderer * renderer);

  int x=0, y=-50;
  int width=4, height=5;

  void draw_heart(
    SDL_Renderer * renderer,
    SDL_Window * window,
    int box_x, int box_y,
    int box_width, int box_height
  );

  void query_keys_up(SDL_Event & event);
  void query_keys_down(SDL_Event & event);

};

#endif // HEART_H