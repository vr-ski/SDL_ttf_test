#pragma once
// Uncomment me to add error logging:
// #define ERROR_LOGGING
#include <iostream>
#include <SDL2/SDL.h>

void  CheckSDLError(const std::string& Action) {
  const char* error = SDL_GetError();
  if (*error != '\0') {
    std::cerr << Action << " Error: "
      << error << std::endl;;
    SDL_ClearError();
  }
}