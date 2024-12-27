#pragma once
#include <SDL2/SDL.h>

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
                 SDL_MapRGB(GetSurface()->format, 255, 128, 0));
  }

  void Update() { SDL_UpdateWindowSurface(SDLWindow); }

  SDL_Surface *GetSurface() { return SDL_GetWindowSurface(SDLWindow); }

  ~Window() { SDL_DestroyWindow(SDLWindow); }

  Window(const Window &) = delete;
  Window &operator=(const Window &) = delete;

private:
  SDL_Window *SDLWindow;
};