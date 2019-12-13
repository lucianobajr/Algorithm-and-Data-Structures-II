#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include <stdio.h>

int main()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  SDL_WM_SetCaption("teste", NULL);

  SDL_SetVideoMode(600, 400, 32, SDL_OPENGL);

  glClearColor(1, 1, 1, 1);

  glViewport(0, 0, 600, 400);
  glShadeModel(GL_SMOOTH);
  glMatrixMode(GL_PROJECTION);
  glDisable(GL_DEPTH_TEST);

  glClear(GL_COLOR_BUFFER_BIT);
  printf("\nExecutando\n");
  SDL_Delay(5000);
  SDL_Quit();
  return 0;
}
