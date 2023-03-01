#include "attack.h"

void ATTACK::draw_attack(
  SDL_Renderer * rend, 
  SDL_Window * win
) {
  renderResizedTexture(
    rend, win,
    x, y,
    width, height
  );
}

void ATTACK::init(SDL_Renderer * renderer, const std::string asset_path) {
  setTexture(renderer, asset_path);
}