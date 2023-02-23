
#include <iostream>
#include <memory>

// my shitty code
#include "src/rendering/rendering.h"
#include "src/gameplay/heart/heart.h"
#include "src/gameplay/scout/scout.h"
#include "src/gameplay/box/box.h"

using std::unique_ptr;

int main(int, char**) {
  

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

  SDL_Renderer * rend = SDL_CreateRenderer(
    win, -1, 
    SDL_RENDERER_ACCELERATED
  );

	unique_ptr<SCOUT> scout(new SCOUT(rend));
  
	// creates the undertale heart
	unique_ptr<HEART> heart(new HEART(rend));
	// creates the fighting box thing
	unique_ptr<BOX> box(new BOX(rend));

  while(!quit) {

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
					default:
						break;
				}
			}
			
			if (event.type == SDL_KEYUP) {
				// handles all of the hearts key events
				heart->query_keys_up(event);
			}

    } // end of event checking

		// clears all textures stored on the buffer
		SDL_RenderClear(rend);

		// draws out new things to the buffer
		scout->draw_scout(rend, win);
		heart->draw_heart(rend, win);
		box->draw_box(rend, win);


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
