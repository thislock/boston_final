
#include "font.h"
#include "alphabet.h"

void FONT::letter(
  SDL_Renderer * renderer,
  SDL_Window * window,
  int x, int y,
  int width, int height,
  char let
) {

  clips[1] = 0;
  clips[2] = 5;
  clips[3] = 5;

  switch (let) {
  case 'a':
    clips[0] = 6 * a;
    break;
  case 'b':
    clips[0] = 6 * b;
    break;

  case 'c':
    clips[0] = 6 * c;
    break;

  case 'd':
    clips[0] = 6 * d;
    break;

  case 'e':
    clips[0] = 6 * e;
    break;

  case 'f':
    clips[0] = 6 * f;
    break;

  case 'g':
    clips[0] = 6 * g;
    break;

  case 'h':
    clips[0] = 6 * h;
    break;

  case 'i':
    clips[0] = 6 * i;
    break;

  case 'j':
    clips[0] = 6 * j;
    break;

  case 'k':
    clips[0] = 6 * k;
    break;

  case 'l':
    clips[0] = 6 * l;
    break;

  case 'm':
    clips[0] = 6 * m;
    break;

  case 'n':
    clips[0] = 6 * n;
    break;

  case 'o':
    clips[0] = 6 * o;
    break;

  case 'p':
    clips[0] = 6 * p;
    break;

  case 'q':
    clips[0] = 6 * q;
    break;

  case 'r':
    clips[0] = 6 * r;
    break;

  case 's':
    clips[0] = 6 * s;
    break;

  case 't':
    clips[0] = 6 * t;
    break;

  case 'u':
    clips[0] = 6 * u;
    break;

  case 'v':
    clips[0] = 6 * v;
    break;

  case 'w':
    clips[0] = 6 * w;
    break;

  case 'x':
    clips[0] = 6 * X;
    break;

  case 'y':
    clips[0] = 6 * Y;
    break;

  case 'z':
    clips[0] = 6 * z;
    break;

  case '*':
    clips[1] = 5;
    clips[0] = 6 * 17; 
    break;

  case ' ':
    clips[0] = 300;
    break;
  

  default:
    break;
  }
  

  renderCutResizedTexture(
    renderer,
    window,
    x, y,
    width, height,
    clips
  );

}

void FONT::letter_seq(
  SDL_Renderer * renderer,
  SDL_Window * window,
  int x, int y,
  int ww, int hh,
  std::string sent = "no text inputed"
) {
  for (int ii = 0; ii < sent.length(); ii++) {
    letter(
      renderer,
      window,
      x + (ww * ii) + (ii * 5), y,
      ww, hh,
      sent[ii]
    );
  }
}


void FONT::color_set(
  int set
) {
  switch (set) {
    // sets the color to yellow
    case 1:
      // if it isn't already the yellow font
      if (tex != font_yellow)
      tex = font_yellow;
      break;
    // by default, sets the color to white
    default:
      // if it isn't already the default font
      if (tex != font_default)
      tex = font_default;
      break;
  }
}