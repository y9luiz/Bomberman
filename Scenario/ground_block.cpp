#include "ground_block.hpp"


GroundBlock::GroundBlock(int x,int y, int h,int w, SDL_Texture * texture)
{
    setIsIndestructible(true);
    setX(x);
    setY(y);
    setHeight(h);
    setWidgth(w);
    setTexture(texture);
}   
GroundBlock::GroundBlock(SDL_Rect r, SDL_Texture * texture)
{
    setIsIndestructible(true);
    setRect(r);
    setTexture(texture);
}
GroundBlock::~GroundBlock()
{
   //clearTexture(); 
}