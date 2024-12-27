#include <iostream>
#include "Window.h"
#include "Text.h"


int main(int argc, char **argv)
{
  SDL_Init(SDL_INIT_VIDEO);
  if (TTF_Init() < 0)
  {
    std::cout << "Error initializing SDL_ttf: " << SDL_GetError();
    exit(1);
  }

  SDL_Event Event;
  bool shouldQuit{false};

  Window GameWindow;
  Text TextExample{"Hello, World", 100};

  while (!shouldQuit)
  {
    while (SDL_PollEvent(&Event))
    {
      if (Event.type == SDL_QUIT)
      {
        shouldQuit = true;
      }
    }
    GameWindow.Render();
    // std::cout << "Hello, World!" << std::endl;
    TextExample.Render(GameWindow.GetSurface());
    GameWindow.Update();
  }

  TTF_Quit();
  SDL_Quit();
  return 0;
}