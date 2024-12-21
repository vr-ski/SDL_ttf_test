#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Text
{
public:
  Text(std::string Content) : Font{TTF_OpenFont("resources/HussarMilosc-lO6e.otf", 50)}
  {
    if (!Font)
    {
      std::cout << "Error loading font: " << SDL_GetError();
    }
    CreateSurface(Content);
  }

  void Render(SDL_Surface *DestinationSurface)
  {
    SDL_BlitSurface(
        TextSurface, nullptr,
        DestinationSurface, nullptr);
  }

  ~Text()
  {
    if (TTF_WasInit())
    {
      TTF_CloseFont(Font);
    }
  }

  Text(const Text &) = delete;

  Text &operator=(const Text &) = delete;

private:
  void CreateSurface(std::string Content)
  {
    SDL_Surface *newSurface =
        TTF_RenderUTF8_Blended(Font, Content.c_str(), {255, 255, 255});
    if (newSurface)
    {
      SDL_FreeSurface(TextSurface);
      TextSurface = newSurface;
    }
    else
    {
      std::cout << "Error creating TextSurface: " << SDL_GetError() << '\n';
    }
  }

  TTF_Font *Font{nullptr};
  SDL_Surface *TextSurface{nullptr};
};