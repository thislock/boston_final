#include "heart.h"

#include <iostream>


HEART::HEART(SDL_Renderer * rend) {
  setTexture(rend, ASSETPATH"interactable/heart.bmp");
}

// draws and moves the undertale heart
void HEART::draw_heart(
  SDL_Renderer * rend,
  SDL_Window * win
) {
  // moves the heart in the direction needed
  // right
  if (heartvel_right)
    x += heart_vel;
  // left
  if (heartvel_left)
    x -= heart_vel;
  // up
  if (heartvel_up)
    y += heart_vel;
  // down
  if (heartvel_down)
    y -= heart_vel;

  renderResizedTexture(
    rend, win,
    x, y,
    4, 5
  );
}

// when any arrow key is relesed
void HEART::query_keys_up(SDL_Event & ev) {

  switch (ev.key.keysym.sym){
    
    case SDLK_RIGHT:
      heartvel_right = false;
      break;
    case SDLK_LEFT:
      heartvel_left = false;
      break;
    case SDLK_UP:
      heartvel_up = false;
      break;
    case SDLK_DOWN:
      heartvel_down = false;
      break;


    default:
      break;
  }

}

// when any arrow key is pressed down
void HEART::query_keys_down(SDL_Event & ev) {

  switch (ev.key.keysym.sym){

    case SDLK_RIGHT:
      heartvel_right = true;
      break;
    case SDLK_LEFT:
      heartvel_left = true;
      break;
    case SDLK_UP:
      heartvel_up = true;
      break;
    case SDLK_DOWN:
      heartvel_down = true;
      break;

    default:
      break;
  }

}
