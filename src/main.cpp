#include <iostream>
#include "Window.h"
#include "Text.h"
#include "Events.h"


int main(int argc, char **argv)
{
  SDL_Init(SDL_INIT_VIDEO);
  #ifdef ERROR_LOGGING
  CheckSDLError("SDL_Init");
  #endif

  TTF_Init();
  #ifdef ERROR_LOGGING
  CheckSDLError("TTF_Init");
  #endif

  SDL_Event Event;
  bool shouldQuit{false};

  Window GameWindow;
  Text TextExample{"Hello, World", 100};

  while (!shouldQuit)
  {
    while (SDL_PollEvent(&Event))
    {
      switch (Event.type)
      {
      case SDL_MOUSEMOTION:
        HandleMotion(Event.motion, GameWindow.get_Width(), GameWindow.get_Height());
        break;
      
      case SDL_MOUSEBUTTONDOWN:
      case SDL_MOUSEBUTTONUP:
        HandleButton(Event.button);
        break;

      case SDL_WINDOWEVENT: [[unlikely]]
        HandleWindowEvent(Event.window);
        break;
      
      case SDL_QUIT: [[unlikely]]
        shouldQuit = true;
        break;
      
      default:
        break;
      } 
    }

    GameWindow.Render();
    TextExample.Render(GameWindow.GetSurface());
    GameWindow.Update();
  }

  TTF_Quit();
  SDL_Quit();
  return 0;
}