#include "wall_block.hpp"


WallBlock::WallBlock(int x,int y, int h,int w, SDL_Texture * texture)
{
    setIsIndestructible(true);
    setX(x);
    setY(y);
    setHeight(h);
    setWidgth(w);
    setTexture(texture);
}   
WallBlock::WallBlock(SDL_Rect r, SDL_Texture * texture)
{
    setIsIndestructible(true);
    setRect(r);
    setTexture(texture);
}
WallBlock::~WallBlock()
{
   //clearTexture(); 
}