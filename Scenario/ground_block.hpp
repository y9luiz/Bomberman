#pragma once
#include "block.hpp"


class GroundBlock :  public Block{
    private:
        static SDL_Texture * texture;
    public:
        explicit GroundBlock(int x,int y, int h,int w, SDL_Texture * texture);
        explicit GroundBlock(SDL_Rect r, SDL_Texture * texture);
        ~GroundBlock();

};