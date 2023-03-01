#include "box.h"
#include "../../rendering/font/font.h"
#include <memory>
#include <string>

#include <time.h>
#include <stdlib.h>

using std::string;
using std::unique_ptr;

// text font
unique_ptr<FONT> font(new FONT());

// attack range damage thingy
unique_ptr<IMAGE> damage_bar(new IMAGE());
// the thing that moves along the attack damage thingy
unique_ptr<IMAGE> damage_bar_slider(new IMAGE());


// the buffer for the text drawn to the box
static string text_buffer1 = "";
static string text_buffer2 = "";

// for first time declaration
static bool init_bm = true;
// all of the approriet text draw to the screen when the buttons are pressed
// if you didn't know, the & on some of these means they are passed by referance, so you can modify the variable passed in and have the original var in main affected
void BOX::box_menu(
  SDL_Renderer * rend, 
  SDL_Window * win,
  // what button is pressed
  int pressed,
  // how deep you are in it
  int level,
  // for changing the scout's turn when needed
  bool & end_turn,
  // for when you attack
  bool & scout_dodge,
  // how many times you have attacked
  int & attacking_turns
) {
  // declares things that need the renderer
  if(init_bm) {
    font->init(rend);
    damage_bar->setTexture(rend, ASSETPATH"attacks/damage_bar.bmp");
    damage_bar_slider->setTexture(rend, ASSETPATH"attacks/damage_bar_slider.bmp");
    init_bm = false;
    srand(time(NULL));
  }
  // sets the text buffers to a blank value, there are multable for line breaks
  text_buffer1 = "";
  text_buffer2 = "";
  // sets the default color to white
  font->color_set(0);

  switch (pressed) {
    
    case 1:

      // turn over
      if (level == 2) {
        end_turn = true;
        scout_dodge = true;
        // adds to the amount of turns you have attacked
        attacking_turns++;
        // exit case 1
        break;
      }

      // if the z key is pressed during this
      if (level == 1) {
        // the attack thing
        damage_bar->renderCutResizedTexture(
          rend, win,
          box_x, box_y,
          box_width, box_height,
          attack_thing_clips
        );
        // the thing that moves across it
        damage_bar_slider->renderResizedTexture(
          rend, win,
          damage_bar_slider_x, box_y,
          7, 50
        );
        // depending on witch direction the damage bar is moving
        if (db_slider_direction) {
          // if it isn't beyond the box's size
          if (damage_bar_slider_x < 100)
            // add 5 in direction heading
            damage_bar_slider_x += 5;
          else
            // if it reaches the end, end the turn
            end_turn = true;
        } else {
          // if it reaches the end, end the turn
          if (damage_bar_slider_x > -100)
            // add 5 in direction heading
            damage_bar_slider_x -= 5;
          else
            end_turn = true;
        }
        break;
      }
      
      // set's the color to yellow
      font->color_set(1);
      // if the layer is 1, draw the text
      // 5% chance to say "son" instead of "scout" 
      if (rand() % 20 == 5) {
        // sets the color to white
        font->color_set(0);
        text_buffer1 = "* son"; 
      } else
        text_buffer1 = "* scout";
      break; // end of case 1
    
    case 2:
      
      // if it's the first time pressing z
      if (level == 0) {
        // sets color to yellow
        font->color_set(1);
        // 10% chance to say "son" instead of "scout" 
        if (rand() % 10 == 5) {
          // sets the color to white
          font->color_set(0);
          text_buffer1 = "* son"; 
        } else
          text_buffer1 = "* scout";
        break;
      }
      
      break; // end of case 2
    
    case 3:

      break;

  }

  // if the string isnt blank, draw it
  if (text_buffer1 != "")
  font->letter_seq(
    rend, win, 
    (box_x - box_width / 2) + 10, 
    box_y + box_height / 3,
    5, 8,
    text_buffer1
  );
  // if the string isnt blank, draw it
  if (text_buffer2 != "")
  font->letter_seq(
    rend, win, 
    (box_x - box_width / 2) + 10, 
    (box_y + box_height / 3) + 10,
    5, 8,
    text_buffer1
  );
}