#include <memory>
#pragma once

struct SDL_Deleter
{
	  void operator()(SDL_Window *p) const { SDL_DestroyWindow(p); }
	  void operator()(SDL_Renderer *p) const { SDL_DestroyRenderer(p); }
          void operator()(SDL_Texture *p) const { SDL_DestroyTexture(p); }
};
