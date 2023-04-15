#pragma once
#include "Common/renderable_object.hpp"

#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

class Block : public RenderableObject {
 private:
  bool is_indestructible;

 protected:
 public:
  inline bool getIsIndestructible() { return is_indestructible; };
  inline void setIsIndestructible(bool is_indestructible) {
    this->is_indestructible = true;
  };
};