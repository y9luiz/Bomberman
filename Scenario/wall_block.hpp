#pragma once
#include "block.hpp"

class WallBlock : public Block {
 private:
  static SDL_Texture* texture;

 public:
  explicit WallBlock(int x, int y, int h, int w, SDL_Texture* texture);
  explicit WallBlock(SDL_Rect r, SDL_Texture* texture);
  ~WallBlock();
};