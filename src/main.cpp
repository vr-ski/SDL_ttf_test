#include <iostream>
#include "Window.h"
#include "Text.h"
#include "UI.h"


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

  UI GameUI; 

  SDL_Event Event;
  bool shouldQuit{false};

  Window* GameWindow = Window::getInstance();
  Text TextExample{"Hello, World", 100};

  while (!shouldQuit)
  {
    while (SDL_PollEvent(&Event))
    {
      shouldQuit = GameUI.HandleEvent(Event);
    }

    GameWindow->Render();
    TextExample.Render(GameWindow->GetSurface());
    GameWindow->Update();
  }

  TTF_Quit();
  SDL_Quit();
  return 0;
}