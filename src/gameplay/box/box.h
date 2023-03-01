
#ifndef BOX_H
#define BOX_H

#include "../../rendering/rendering.h"

class BOX : public IMAGE {

  SDL_Texture * black_cover = nullptr;

  int cover_clips[4] = {0, 0, 1, 1};
  int attack_thing_clips[4] {10, 5, 170, 50};

public:

  // data that can be modified to make the game more interesting
  int box_x=0, box_y=-50;
  int box_width=200, box_height=50;

  // for setting the preset box texture
  BOX(SDL_Renderer * renderer);

  // do i really need to explain what this does?
  void draw_box(
    SDL_Renderer * renderer,
    SDL_Window * window
  );

  // the thing that moves across the damage bar pos
  int damage_bar_slider_x;
  // the direction it goes in, true for right, and false for left
  bool db_slider_direction;

  // draws all menu related text/texures
  void box_menu(
    SDL_Renderer * renderer,
    SDL_Window * window,
    int button_pressed,
    int layers_of_pressing,
    // for ending the turn when needed
    bool & end_turn, 
    // for when you attack
    bool & scout_dodge,
    // how many times you have attacked
    int & attacking_turns
  );

};


#endif // BOX_H