#pragma once
#include <iostream>
#include <SDL2/SDL.h>

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