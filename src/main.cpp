#include "Text.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Window
{
public:
  Window()
  {
    SDLWindow = SDL_CreateWindow("My Pimped Program", SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED, 600, 300, 0);
  }

  void Render()
  {
    SDL_FillRect(GetSurface(), nullptr,
                 SDL_MapRGB(GetSurface()->format, 50, 50, 50));
  }

  void Update() { SDL_UpdateWindowSurface(SDLWindow); }

  SDL_Surface *GetSurface() { return SDL_GetWindowSurface(SDLWindow); }

  ~Window() { SDL_DestroyWindow(SDLWindow); }

  Window(const Window &) = delete;
  Window &operator=(const Window &) = delete;

private:
  SDL_Window *SDLWindow;
};

int main(int argc, char **argv)
{
  SDL_Init(SDL_INIT_VIDEO);
  if (TTF_Init() < 0)
  {
    std::cout << "Error initializing SDL_ttf: " << SDL_GetError();
  }
  
  SDL_Event Event;
  bool shouldQuit{false};

  Window GameWindow;
  Text TextExample{"Hello, World"};

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
    std::cout << "Hello, World!" << std::endl;
    TextExample.Render(GameWindow.GetSurface());
    GameWindow.Update();
  }

  TTF_Quit();
  SDL_Quit();
  return 0;
}