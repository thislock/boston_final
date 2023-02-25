
#include "button.h"

#include <SDL.h>

#include <iostream>

void BUTTON::query_keys(SDL_Event & event, int turn) {

  // sets the button selected if it is your turn
  if (!turn)
  switch (event.key.keysym.sym){
  case SDLK_RIGHT:
    if (button_selected == 4)
      button_selected = 1;
    else 
      button_selected++;
    break;
  
  case SDLK_LEFT:
    if (button_selected == 1)
      button_selected = 4;
    else
      button_selected--;
    break;
  
  default:
    break;
  }

  fight_buffer = fight;
  act_buffer   = act;
  item_buffer  = item;
  mercy_buffer = mercy;

  // sets the right texture
  switch (button_selected) {
    case 1:
      fight_buffer = fight_sel;
      break;

    case 2:
      act_buffer = act_sel;
      break;

    case 3:
      item_buffer = item_sel;
      break;

    case 4:
      mercy_buffer = mercy_sel;
      break;

  }

}

void BUTTON::draw_buttons(
  SDL_Renderer * rend, 
  SDL_Window * win,
  // for dynamicly changing the button pos depending on how big the box is
  int box_y, int box_height
) {
  renderResizedInputedTexture(
    rend, win, act_buffer,
    -26, box_y - box_height, 50, 30
  );
  
  renderResizedInputedTexture(
    rend, win, fight_buffer,
    -76, box_y - box_height + 1, 50, 30
  );
  
  renderResizedInputedTexture(
    rend, win, item_buffer,
    26, box_y - box_height + 1, 50, 30
  );

  renderResizedInputedTexture(
    rend, win, mercy_buffer,
    76, box_y - box_height + 2, 50, 30
  );
}


BUTTON::BUTTON(SDL_Renderer * rend) {
  // loads all of the button textures
  std::cout << "setting button textures...";
  act       = returnTexture(rend, ASSETPATH"interactable/buttons/act/act.bmp");
  act_sel   = returnTexture(rend, ASSETPATH"interactable/buttons/act/selected_act.bmp");
  fight     = returnTexture(rend, ASSETPATH"interactable/buttons/fight/fight.bmp");
  fight_sel = returnTexture(rend, ASSETPATH"interactable/buttons/fight/selected_fight.bmp");
  item      = returnTexture(rend, ASSETPATH"interactable/buttons/item/item.bmp");
  item_sel  = returnTexture(rend, ASSETPATH"interactable/buttons/item/selected_item.bmp");
  mercy     = returnTexture(rend, ASSETPATH"interactable/buttons/mercy/mercy.bmp");
  mercy_sel = returnTexture(rend, ASSETPATH"interactable/buttons/mercy/selected_mercy.bmp");
  std::cout << " success\n";
  act_buffer   = act;
  fight_buffer = fight;
  item_buffer  = item;
  mercy_buffer = mercy;
}

BUTTON::~BUTTON() {
  std::cout << "destroying button textures... ";
  SDL_DestroyTexture(act);
  SDL_DestroyTexture(act_sel);
  SDL_DestroyTexture(fight);
  SDL_DestroyTexture(fight_sel);
  SDL_DestroyTexture(item);
  SDL_DestroyTexture(item_sel);
  SDL_DestroyTexture(mercy);
  SDL_DestroyTexture(mercy_sel);
  std::cout << " succes\n";
}