
// include i guess
#include <iostream>
#include <memory>
#include <SDL.h>

// my shitty code
#include "src/rendering/rendering.h"
#include "src/gameplay/heart/heart.h"
#include "src/gameplay/scout/scout.h"
#include "src/gameplay/box/box.h"
#include "src/features/collide.h"
#include "src/rendering/font/font.h"
#include "src/gameplay/buttons/button.h"
#include "src/gameplay/attacks/attack.h"


// usings
using std::unique_ptr;

// main
int main() {
	// for when any quit type is called
  bool quit = false;
  SDL_Event event;

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window * win = SDL_CreateWindow(
    "spies purgitory", 
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    900, 550,
    SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
  );

	// fixes the issue where it crashes when the window gets too smol
	SDL_SetWindowMinimumSize(win, 400, 300);

	// rendering surface
  SDL_Renderer * rend = SDL_CreateRenderer(
    win, -1,
    SDL_RENDERER_ACCELERATED
  );

	// scout class creation
	unique_ptr<SCOUT> scout(new SCOUT(rend));
  
	// creates the undertale heart
	unique_ptr<HEART> heart(new HEART(rend));

	// creates the fighting box thing
	unique_ptr<BOX> box(new BOX(rend));

	// creates the button instance
	unique_ptr<BUTTON> buttons(new BUTTON(rend));
	
	// fonting
	unique_ptr<FONT> font(new FONT(rend));

	// when any turn is ended
	bool end_turn = false;

	// how many turns have passed
	int turn_counter = 1;
	// how many of those turns you have attacked
	int turns_attacked = 0;

	int hp = 90;

  while(!quit) {

		std::cout << hp << '\n';
		
    // loops through all of the events until there are none left
		for (; SDL_PollEvent(&event);) {
			
			// if window is closed, or you press escape, it closes out of the while loop
			if (
				// if the exit button thing is pressed, or ended by the task manager
				event.type == SDL_QUIT
				// or
				||
				// if the ESCAPE key is pressed
				event.key.keysym.sym == SDLK_ESCAPE
			) {
				quit = true;
			}

			if (event.type == SDL_KEYDOWN) {

				// handles all of the hearts key events
				heart->query_keys_down(event);
			
				switch (event.key.keysym.sym){
					case SDLK_a:
						box->box_width--;
						break;

					case SDLK_d:
						box->box_width++;
						break;

					default:
						break;
				}
			}
			
			if (event.type == SDL_KEYUP) {

				// buttons keys processing
				buttons->query_keys(
					event, 
					scout->scout_turn,
					box->damage_bar_slider_x, 
					box->db_slider_direction
				);

				// fullscreen
				switch (event.key.keysym.sym){
					case SDLK_F4:
						SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN_DESKTOP);
				
					default:
						break;
				}

				// handles all of the hearts key events
				heart->query_keys_up(event);
			}

    } // end of event checking

		// when any turn ends
		if (end_turn) {
			buttons->button_layer = 0;
			// reverses the turn
			if (scout->scout_turn) {
				// adds to the amount of full turns that have passed
				turn_counter++;
				scout->scout_turn = false;
			} else
				// changes it to scouts turn
				scout->scout_turn = true;
			// end 
			end_turn = false;
		}

		// handles all of the scout animations
		scout->animate();

		// clears all textures stored on the buffer
		SDL_RenderClear(rend);
		
		// draws the standard undertale-like attack box
		box->draw_box(rend, win);

		// draws the buttons
		buttons->draw_buttons(
			rend, win,
			box->box_y, box->box_height
		);

		// draws the box text and submenu's if it's your turn
		if (!scout->scout_turn)
		box->box_menu(
			rend, win, 
			buttons->button_pressed, 
			buttons->button_layer,
			end_turn,
			scout->scout_dodge,
			turns_attacked
		);

		// draws out new things to the buffer
		scout->draw_scout(rend, win);

		// if it's not your turn, draw and animate the heart
		if (scout->scout_turn)
		heart->draw_heart(
			// drawing surfaces
			rend, win,
			// for checking if your touching the edge of the box
			box->box_x, box->box_y,
  		box->box_width, box->box_height
		);

		attacks(
			rend, win, 
			heart->x, heart->y, 
			heart->width, heart->height, 
			turn_counter,
			scout->scout_turn, 
			hp
		);

		// make sure the renderer's backround is black
		SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
		// swap
		SDL_RenderPresent(rend);
		// wait
		SDL_Delay(1000 / 30);

		// repeat
  }
	// tells you when the loop is out of order, for seperating runtime errors from closing errors
	std::cout << "\nLOOP CLOSED\n\n";

	// stops sdl2 backround tasks
	std::cout << "haulting sdl2...";
	SDL_Quit();
	std::cout << " success\n";

	// destroys window drawing surface
	std::cout << "destroying window renderer... ";
	SDL_DestroyRenderer(rend);
	std::cout << "success\n";

	// destroys window and notify's you if it didnt work
	std::cout << "destroying window... ";
	SDL_DestroyWindow(win);
	std::cout << "success\n";

	
}