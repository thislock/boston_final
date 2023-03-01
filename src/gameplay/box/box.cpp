
#include "box.h"
#include <memory>

BOX::BOX(SDL_Renderer * rend) {
  setTexture(rend, ASSETPATH"box.bmp");
  black_cover = returnTexture(rend, ASSETPATH "font.bmp");
}

// the undertale "fighting box" if you will
void BOX::draw_box(
  SDL_Renderer * rend, 
  SDL_Window * win
) {
  // box outline
  renderResizedTexture(
    rend, win,
    box_x, box_y,
    box_width, box_height
  );

  // draws only the black part for better box scaling
  renderCutResizedInputedTexture(
    rend, win,
    black_cover,
    box_x, box_y,
    box_width - 5, box_height - 5,
    cover_clips
  );
  
}