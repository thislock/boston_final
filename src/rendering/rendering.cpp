
#include <SDL.h>
#include <iostream>

using std::cout;
using std::endl;

#include "rendering.h"

// same as renderResizedTexture but you input the texture
void renderResizedInputedTexture(
  SDL_Renderer * rend, 
  SDL_Window * win,
  SDL_Texture * tex,
  int x, int y,
  int w, int h
) {
	// gets whatever the current width and height of the window are
	int resized_width;
	int resized_height;
	SDL_GetWindowSize(win, &resized_width, &resized_height);

	// fixes the y being weird
	y *= -1;

	// resizes the width and height to window size for code simplicity
	w = (w * 1000) / (ASPECT_RATIO_HORAZONTAL / resized_width);
	h = (h * 1000) / (ASPECT_RATIO_VERTICAL   / resized_height);

	// renders the texture but in a 400 by 300 consistant gragh
	renderScaledInputedTexture(
		rend, tex,
		// math to generalize the positions\/     				     math for a centered 0, 0\/
		(x * 1000) / (ASPECT_RATIO_HORAZONTAL / resized_width) + (resized_width/2)  - (w / 2), 
		(y * 1000) / (ASPECT_RATIO_VERTICAL   / resized_height)+ (resized_height/2) - (h / 2),
		w, h
	);

}

void IMAGE::renderResizedTexture(
	SDL_Renderer * rend,
	// takes in window for the window size
	SDL_Window * win,
	// position
	int x, int y,
	// scale
	int w, int h
) {
	// just uses prior function for code size
	renderResizedInputedTexture(
		rend, win, tex,
		x, y, 
		w, h
	);
}


void butFix(
	SDL_Renderer * renderer, 
	SDL_Texture * tex,
  int x, int y,
	int width, int height,
	SDL_Rect *clip = nullptr
) {

	SDL_Rect dst;

	dst.x = x;
	dst.y = y;

	if (clip != nullptr){
		dst.w = width;
		dst.h = height;
	} else {
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	}

	SDL_RenderCopy(renderer, tex, clip, &dst);
}


void IMAGE::renderCutResizedTexture(
	SDL_Renderer * renderer, 
	SDL_Window * win,
  int x, int y,
	int width, int height,
	int clippings[4]
) {

	SDL_Rect clip;

	int resized_width, resized_height;
	SDL_GetWindowSize(win, &resized_width, &resized_height);
	
	clip.x = clippings[0];
	clip.y = clippings[1];
	clip.w = clippings[2];
	clip.h = clippings[3];
	
	y *= -1;

	// centers the rendering point
	width = (width * 1000) / (ASPECT_RATIO_HORAZONTAL / resized_width);
	height = (height * 1000) / (ASPECT_RATIO_VERTICAL   / resized_height);

	// math to convert the position into a 400 by 300 graph
	x = (x * 1000) / (ASPECT_RATIO_HORAZONTAL / resized_width) + (resized_width/2)  - (width / 2);
	y = (y * 1000) / (ASPECT_RATIO_VERTICAL   / resized_height)+ (resized_height/2) - (height / 2);
	
	butFix(
		renderer, tex,
		x, y,
		width, height,
		&clip
	);
}

void IMAGE::renderCutTexture(
	SDL_Renderer * renderer, 
  int x, int y,
	int width, int height,
	int clippings[4]
) {

	SDL_Rect clip;
	
	clip.x = clippings[0];
	clip.y = clippings[1];
	clip.w = clippings[2];
	clip.h = clippings[3];

	butFix(
		renderer, 
		tex, 
		x, y, 
		width, height,
		&clip
	);
}


void IMAGE::renderTexture(SDL_Renderer * ren, int x, int y){
	//Setup the destination rectangle to be at the position we want

	SDL_Rect dst;
	dst.x = x; dst.y = y;

	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}


void renderScaledInputedTexture(
	SDL_Renderer *ren, 
	SDL_Texture * tex, 
	int x, int y, 
	int w, int h
){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void IMAGE::renderScaledTexture(
	SDL_Renderer *ren, 
	int x, int y, 
	int w, int h
){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

IMAGE::IMAGE(SDL_Renderer * renderer, const std::string & file) {

	// sets the filename for error handling
	filename = file;

	// Load the image
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	
	// If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr) {
		tex = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (tex == nullptr) {
			cout << "failed to create texture from surface, unknown cause.\n";
		}
	}
	else {
		cout << "failed to load " << filename << ", check filename and try again.\n";
  }
}

void IMAGE::setTexture(SDL_Renderer * renderer, const std::string &file) {

	// sets the filename for error handling
	filename = file;

	// Load the image
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	
	// If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr) {
		tex = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (tex == nullptr) {
			cout << "failed to create texture from surface, unknown cause.\n";
		}
	}
	else {
		cout << "failed to load " << filename << ", check filename and try again.\n";
  }
}

SDL_Texture * returnTexture(SDL_Renderer * renderer, const std::string & file) {

	SDL_Texture * texture;

	// Load the image
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	
	// If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (texture == nullptr) {
			cout << "failed to create texture from surface, unknown cause.\n";
		}
	}
	else {
		cout << "failed to load " << file << ", check filename and try again.\n";
  }
	return texture;
}

IMAGE::IMAGE() {
	// pointless processing
	int xxxxxxxxxxxxxxxxxxxxxxx;
}

IMAGE::~IMAGE() {
	// makes sure the texture was accually set/works
	if (tex != nullptr) {
		SDL_DestroyTexture(tex);
		cout << "destroyed texture, " << filename << endl;
	}
}
