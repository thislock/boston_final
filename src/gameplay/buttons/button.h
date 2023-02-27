
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

  // the button that is being hovered over
  int button_selected=1;
  // the button that is currently pressed
  int button_pressed=0;

  // the selected thing in a submenu, a menu displayed when a button is pressed
  // up/down
  int submenu_selected_vert=1;
  // left/right
  int submenu_selected_hor=1;

  // the layer you are in the buttons
  int button_layer = 0;
  // if you are in a button menu
  bool in_menu = false;

  // init and exit
  BUTTON(SDL_Renderer * renderer);
  ~BUTTON();

  // key handling
  void query_keys(
    SDL_Event & events, bool scout_turn,
    int & damage_bar_slider_x,
    bool & db_slider_direction
  );

  // draws the buttons and handles texture changes
  void draw_buttons(
    SDL_Renderer * renderer, 
    SDL_Window * window,
    int box_y, int box_height
  );

};

#endif // BUTTON_H