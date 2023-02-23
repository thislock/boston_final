
#ifndef BOX_H
#define BOX_H

#include "../../rendering/rendering.h"

class BOX : public IMAGE {

public:

  // data that can be modified to make the game more interesting
  int box_x=0, box_y=-50;
  int box_width=100, box_height=50;

  // for setting the preset box texture
  BOX(SDL_Renderer * renderer);

  // do i really need to explain what this does?
  void draw_box(
    SDL_Renderer * renderer,
    SDL_Window * window
  );

};


#endif // BOX_H