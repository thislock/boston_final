#ifndef FONT_H
#define FONT_H

#pragma once


#include "../rendering.h"
#include <SDL.h>

#include <string>

#define FONTPATH "../assets/font.bmp"
#define FONTPATH_YELLOW "../assets/font_yellow.bmp"

class FONT : private IMAGE {

  SDL_Texture * font_yellow = nullptr;
  SDL_Texture * font_default = nullptr;

public:

  FONT(SDL_Renderer * renderer) {
    // declares the different font types
    font_default = returnTexture(renderer, FONTPATH);
    font_yellow = returnTexture(renderer, FONTPATH_YELLOW);
    // sets the font to the default value
    tex = font_default;
  }
  void init(SDL_Renderer * renderer) {
    // declares the different font types
    font_default = returnTexture(renderer, FONTPATH);
    font_yellow = returnTexture(renderer, FONTPATH_YELLOW);
    // sets the font to the default value
    tex = font_default;
  }
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

  // sets the color of the font, 0: white, 1: yellow
  void color_set(int set_to);

private:

  int clips[4];

};

#endif // FONT_H