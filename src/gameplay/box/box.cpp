
#include "box.h"


BOX::BOX(SDL_Renderer * rend) {
  setTexture(rend, ASSETPATH"box.bmp");
}

// the undertale "fighting box" if you will
void BOX::draw_box(
  SDL_Renderer * rend, 
  SDL_Window * win
) {
  renderResizedTexture(
    rend, win,
    box_x, box_y,
    box_width, box_height
  );
}