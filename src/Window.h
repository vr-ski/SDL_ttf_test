#pragma once
#include <SDL2/SDL.h>

class Window
{
public:
  short get_Width(){
    return this->Width;
  }

  short get_Height(){
    return this->Height;
  }

  Window()
  {
    SDLWindow = SDL_CreateWindow("My Pimped Program", SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED, Width, Height, 0);
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
  short Width {1024};
  short Height {768};
  SDL_Window *SDLWindow;
};