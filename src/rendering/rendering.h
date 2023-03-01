
#ifndef RENDERING_H
#define RENDERING_H

#pragma once

#include <SDL.h>
#include <iostream>

#include<string>

#define ASPECT_RATIO_HORAZONTAL 400'000
#define ASPECT_RATIO_VERTICAL   300'000

#define ASSETPATH "../assets/"

using std::string;

using std::cout;


class IMAGE {

  string filename;

public:

  IMAGE();
	
  IMAGE(
    SDL_Renderer * renderer, 
    const std::string &file
  );

  ~IMAGE();
  SDL_Texture * tex = nullptr;
  

  void setTexture(
    SDL_Renderer * renderer, 
    const std::string &file
  );

  void renderTexture(
    SDL_Renderer *ren, 
    int x, int y
  );

  void renderScaledTexture(
    SDL_Renderer * renderer, 
    int x, int y, 
    int w, int h
  );

  void renderCutTexture(
    SDL_Renderer *renderer, 
    int x, int y,
    int width, int height,
    int clippings[4]
  );
  
  void renderCutResizedTexture(
    SDL_Renderer *renderer, 
    SDL_Window * window,
    int x, int y,
    int width, int height,
    int clippings[4]
  );
  
  void renderResizedTexture(
    SDL_Renderer * renderer,
    // takes in window for the window size
	  SDL_Window * window,
	  // position
	  int x, int y,
	  // scale
	  int width, int height
  );

};

// creates and returns a texture
SDL_Texture * returnTexture(SDL_Renderer * renderer, const std::string &file);

void renderResizedInputedTexture(
  SDL_Renderer * renderer, 
  SDL_Window * window,
  SDL_Texture * tex,
  int x, int y,
  int width, int height
);

void renderCutResizedInputedTexture(
	SDL_Renderer * renderer, 
	SDL_Window * win,
	SDL_Texture * tex,
  int x, int y,
	int width, int height,
	int clippings[4]
);

void renderScaledInputedTexture(
  SDL_Renderer *renderer, 
  SDL_Texture * texture, 
  int x, int y, 
  int width, int height
);

#endif // RENDERING_H