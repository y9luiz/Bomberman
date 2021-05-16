#include "char.hpp"

Character::Character()
{

}

Character::Character(int x,int y, int h,int w, DirectionTextures & direction_textures)
{
    setX(x);
    setY(y);
    setHeight(h);
    setWidgth(w);

    this->direction_textures_.down = direction_textures.down.copy();
    this->direction_textures_.rigth = direction_textures.rigth.copy();
    this->direction_textures_.left = direction_textures.left.copy();
    this->direction_textures_.up = direction_textures.up.copy();
    
    setTexture(direction_textures_.down.getHead()->getData());
}
Character::~Character()
{

}
int move_counter = 0;
void Character::move(int key)
{
    if(move_counter>5)
    {
            move_counter =0;
    }
    int speed = 2;
    /*if(last_key != key)
    {
        last_key = key;
        move_counter=0;
    }*/
    switch (key)
    {   
         case SDLK_UP:
            setY(getY()-speed);
            
            setTexture(direction_textures_.up.getNextData());
            move_counter++;
            break;
        case SDLK_DOWN:
            /* code */
            setY(getY()+speed);
            setTexture(direction_textures_.down.getNextData());
            move_counter++;
            break;
        case SDLK_RIGHT:
            setX(getX()+speed);
            SDL_Texture * ptr;
            ptr = direction_textures_.rigth.getNextData();
            std::cout<<ptr<<"\n";
            setTexture(ptr);
            move_counter++;
            break;
        case SDLK_LEFT:
            setX(getX()-speed);
            setTexture(direction_textures_.left.getNextData());
            move_counter++;
            break;
        default:
            break;
    }

}

