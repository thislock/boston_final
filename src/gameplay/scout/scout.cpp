
#include "scout.h"
#include <iostream>



void SCOUT::draw_scout(SDL_Renderer * rend, SDL_Window * win) {

  renderResizedInputedTexture(
    // rendering surfaces
    rend, win, 
    // texture to render
    head,
    // pos and scale
    x + head_x, y + head_y,
    32, 40
  );
  
  renderResizedInputedTexture(
    // rendering surfaces
    rend, win, 
    // texture to render
    torso,
    // pos and scale
    x + torso_x, y + torso_y,
    50, 55
  );
  
  renderResizedInputedTexture(
    // rendering surfaces
    rend, win, 
    // texture to render
    legs,
    // pos and scale
    x + legs_x, y + legs_y,
    38, 60
  );


}

SCOUT::SCOUT(SDL_Renderer * rend) {
  head =  returnTexture(rend, ASSETPATH"scout/head.bmp");
  torso = returnTexture(rend, ASSETPATH"scout/torso.bmp");
  legs =  returnTexture(rend, ASSETPATH"scout/legs.bmp");
}
SCOUT::~SCOUT() {
  std::cout << "destroying scout elements... ";
  SDL_DestroyTexture(head);
  SDL_DestroyTexture(torso);
  SDL_DestroyTexture(legs);
  std::cout << "success\n";
}