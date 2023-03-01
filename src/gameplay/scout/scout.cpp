
#include "scout.h"
#include <iostream>

void SCOUT::animate() {

  // code for the scout dodge animation
  if (scout_dodge) {
    
    dodge_cycle++;

    // velocity changes
    if (dodge_cycle == 1)
      dodge_vel = -1;

    if (dodge_cycle == 5)
      dodge_vel = -2;
    
    if (dodge_cycle == 10)
      dodge_vel = -3;
    
    if (dodge_cycle == 21)
      dodge_vel = 3;

    if (dodge_cycle == 35)
      dodge_vel = 1;
    
    // pos change
    x -= dodge_vel;

    // end code
    if (x == -4) {
      scout_dodge=false;
      dodge_cycle=0;
    }
    
  } // end dodge animation

  twos_counter++;

  // lower numbers = faster
  // breathing tjing
  if (animate_type == 0)
    animate_speed = 9;
  // normal - used most commonly
  if (animate_type == 1)
    animate_speed = 3;
  
  
  // for skipping frames for slower or faster animations
  if (twos_counter >= animate_speed) {
    twos = true;
    twos_counter = 0;
  }

  // skippes every other frame
  if (twos) {
    animation_cycle++;

    // the normal u-shaped animation
    if (animate_type == 1) {
    switch (animation_cycle){

      case 1:
        torso_x++;
        head_x++;
        break;
      
      case 2:
        torso_y++;
        head_y++;
        break;
        
      case 3:
        torso_y++;
        head_y++;
        break;

      case 4:
        torso_y--;
        head_y--;
        break;
      
      case 5:
        torso_x--;
        head_x--;
        break;

      case 6:
        torso_x--;
        torso_y--;
        head_x--;
        head_y--;
        break;
      
      case 7:
        torso_x--;
        head_x--;
        break;
      
      case 8:
        torso_y++;
        head_y++;
        break;
        
      case 9:
        torso_y++;
        head_y++;
        break;

      case 10:
        torso_y--;
        head_y--;
        break;
      
      case 11:
        torso_x++;
        head_x++;
        break;
      
			default:
        torso_x++;
        torso_y--;
        head_x++;
        head_y--;
        animation_cycle = 0;
				break;

    }}// end of animation 1

    // the just up/down animation, for the start, or just staning there
    if (animate_type == 0)
    switch (animation_cycle){
      
      case 1:
        torso_y++;
      break;

      case 2:
        torso_y++;
      break;

      case 3:
        head_y++;
        torso_y++;
      break;

      case 4:
        head_y++;
      break;
      
      case 5:
        torso_y--;
      break;

      case 6:
        torso_y--;
        head_y--;
      break;

      case 7:
        torso_y--;
      break;

      case 8:
        head_y--;
      break;

      case 9:
        torso_y--;
        head_y--;
      break;

      case 10: break;

      case 11:
        head_y = 128;
        torso_y = 78;
      break;

      default:
        animation_cycle=0;
      break;
    }
  }

  twos = false;

}

void SCOUT::draw_scout(SDL_Renderer * rend, SDL_Window * win) {

  
  renderResizedInputedTexture(
    // rendering surfaces
    rend, win, 
    // texture to render
    legs,
    // pos and scale
    x + legs_x, y + legs_y,
    38, legs_height
  );
  
  renderResizedInputedTexture(
    // rendering surfaces
    rend, win, 
    // texture to render
    torso,
    // pos and scale
    x + torso_x, y + torso_y,
    50, 55
  );

  if (head_state == 0)
  renderResizedInputedTexture(
    // rendering surfaces
    rend, win, 
    // texture to render
    head,
    // pos and scale
    x + head_x, y + head_y,
    32, 40
  );
  if (head_state == 1)
  renderResizedInputedTexture(
    // rendering surfaces
    rend, win, 
    // texture to render
    head_closed_eyes,
    // pos and scale
    x + head_x, y + head_y,
    32, 40
  );

}

SCOUT::SCOUT(SDL_Renderer * rend) {
  // default
  head =  returnTexture(rend, ASSETPATH"scout/head.bmp");
  torso = returnTexture(rend, ASSETPATH"scout/torso.bmp");
  legs =  returnTexture(rend, ASSETPATH"scout/legs.bmp");
  // alternate states
  head_closed_eyes = returnTexture(rend, ASSETPATH"scout/alternate_parts/head_eyes_closed.bmp");
}

SCOUT::~SCOUT() {
  std::cout << "destroying scout elements... ";
  // main
  SDL_DestroyTexture(head);
  SDL_DestroyTexture(torso);
  SDL_DestroyTexture(legs);
  // alt
  SDL_DestroyTexture(head_closed_eyes);
  std::cout << "success\n";
}