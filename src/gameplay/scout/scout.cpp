
#include "scout.h"
#include <iostream>



void SCOUT::draw_scout(SDL_Renderer * rend, SDL_Window * win) {

  renderResizedInputedTexture(
    // rendering surfaces
    rend, win, 
    // texture to render
    head,
    // pos and scale
    x, y + 2,
    30, 30
  );
  
  renderResizedInputedTexture(
    // rendering surfaces
    rend, win, 
    // texture to render
    torso,
    // pos and scale
    x, y,
    50, 55
  );
  
  renderResizedInputedTexture(
    // rendering surfaces
    rend, win, 
    // texture to render
    legs,
    // pos and scale
    x, y,
    20, 30
  );


}



SCOUT::SCOUT(SDL_Renderer * rend) {
  head =  returnTexture(rend, ASSETPATH"scout/head.bmp");
  torso = returnTexture(rend, ASSETPATH"scout/torso.bmp");
  legs =  returnTexture(rend, ASSETPATH"scout/legs.bmp");
}
SCOUT::~SCOUT() {
  std::cout << "destroyed scout elements\n";
  SDL_DestroyTexture(head);
  SDL_DestroyTexture(torso);
  SDL_DestroyTexture(legs);
}