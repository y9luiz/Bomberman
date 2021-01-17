#pragma once
#include "block.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class WallBlock :  public Block{
    private:
        static SDL_Texture * texture;
    public:
        explicit WallBlock(int x,int y, int h,int w, SDL_Texture * texture);
        explicit WallBlock(SDL_Rect r, SDL_Texture * texture);
        ~WallBlock();

};