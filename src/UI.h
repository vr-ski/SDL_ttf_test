#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "Window.h"


class UI {
public:
  UI () {
    GameWindow = Window::getInstance();
  }
  bool HandleEvent( const SDL_Event& Event) {
    bool shouldQuit {false};
    switch (Event.type)
      {
      case SDL_MOUSEMOTION:
        HandleMotion(Event.motion, GameWindow->get_Width(), GameWindow->get_Height());
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

      return shouldQuit; 
  }
  void HandleMotion(const SDL_MouseMotionEvent& E, const short& WindowWidth, const short& WindowHeight) {
    int DistanceFromLeft{E.x};
    int DistanceFromTop{E.y};
    
    int DistanceFromRight{WindowWidth - E.x};
    int DistanceFromBottom{WindowHeight - E.y};
  }

  void HandleButton(const SDL_MouseButtonEvent& E) {  
    if (E.button == SDL_BUTTON_LEFT) {
      std::cout << "Left Button\n";
    } else if (E.button == SDL_BUTTON_RIGHT) {
      std::cout << "Right Button\n";
    }
    
    int DistanceFromLeft{E.x};
    int DistanceFromTop{E.y};

    // ...
  }

  void HandleWindowEvent(const SDL_WindowEvent& E) {  
    if (E.event == SDL_WINDOWEVENT_ENTER) {
      std::cout << "Mouse Entered Window\n";
    }
    if (E.event == SDL_WINDOWEVENT_LEAVE) {
      std::cout << "Mouse Left Window\n";
    }
  }

  void Render(SDL_Surface* Surface) {
    // ...
  }

private:
  Window* GameWindow;
};