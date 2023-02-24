#ifndef FONT_H
#define FONT_H

#pragma once


#include "../rendering.h"
#include <SDL.h>

#include <string>

#define FONTPATH "../assets/font.bmp"

class FONT : private IMAGE {

public:

  FONT(SDL_Renderer * renderer) {setTexture(renderer, FONTPATH);}
  void init(SDL_Renderer * renderer) {setTexture(renderer, FONTPATH);}
  FONT() {}

  void letter(
    SDL_Renderer * renderer,
    SDL_Window * window,
    int x, int y,
    int width, int height,
    char letter
  );

  void letter_seq(
    SDL_Renderer * renderer,
    SDL_Window * window,
    int x, int y,
    int width, int height,
    std::string sentance
  );

private:

  int clips[4];

};


#endif // FONT_H