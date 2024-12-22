#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Text
{
public:
  Text(std::string Content, int Size = 25) : Font{TTF_OpenFont("resources/HussarMilosc-lO6e.otf", Size)}
  {
    if (!Font)
    {
      std::cout << "Error loading font: " << SDL_GetError();
    }
    CreateSurface(Content);
  }

  void SetFontSize(int NewSize)
  {
    TTF_SetFontSize(Font, NewSize);
  }

  void Render(SDL_Surface *DestinationSurface)
  {
    SDL_BlitSurface(
        TextSurface, &SourceRectangle,
        DestinationSurface, &DestinationRectangle);
    if (DestinationRectangle.w < TextSurface->w)
    {
      std::cout << "Clipped horizontally\n";
    }
    if (DestinationRectangle.h < TextSurface->h)
    {
      std::cout << "Clipped vertically\n";
    }
  }

  ~Text()
  {
    SDL_FreeSurface(TextSurface);
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
        TTF_RenderUTF8_Blended(Font, Content.c_str(), {0, 77, 128});
    if (newSurface)
    {
      SDL_FreeSurface(TextSurface);
      TextSurface = newSurface;
    }
    else
    {
      std::cout << "Error creating TextSurface: " << SDL_GetError() << '\n';
    }

    SourceRectangle.w = TextSurface->w - 0;
    SourceRectangle.h = TextSurface->h - 0;

    DestinationRectangle.w = TextSurface->w * 4;
    DestinationRectangle.h = TextSurface->h * 4;
  }

  TTF_Font *Font{nullptr};
  SDL_Surface *TextSurface{nullptr};
  SDL_Rect SourceRectangle{0, 0, 0, 0};
  SDL_Rect DestinationRectangle{50, 50, 0, 0};
};