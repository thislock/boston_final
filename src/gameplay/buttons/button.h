
#ifndef BUTTON_H
#define BUTTON_H

#include "../../rendering/rendering.h"

class BUTTON : private IMAGE {

  // all buttons selected/unselected
  SDL_Texture * act   = nullptr;
  SDL_Texture * fight = nullptr;
  SDL_Texture * item  = nullptr;
  SDL_Texture * mercy = nullptr;
  SDL_Texture * act_sel   = nullptr;
  SDL_Texture * fight_sel = nullptr;
  SDL_Texture * item_sel  = nullptr;
  SDL_Texture * mercy_sel = nullptr;
  
  // buffers for simpler code
  SDL_Texture * act_buffer   = nullptr;
  SDL_Texture * fight_buffer = nullptr;
  SDL_Texture * item_buffer  = nullptr;
  SDL_Texture * mercy_buffer = nullptr;

public:

  int button_selected=0;

  BUTTON(SDL_Renderer * renderer);
  ~BUTTON();

  void query_keys(SDL_Event & events, int scout_turn);

  void draw_buttons(
    SDL_Renderer * renderer, 
    SDL_Window * window,
    int box_y, int box_height
  );

};

#endif // BUTTON_H