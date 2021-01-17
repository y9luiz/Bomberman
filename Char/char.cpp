#include "char.hpp"

Character::Character()
{

}

Character::Character(int x,int y, int h,int w, std::vector<SDL_Texture*> walk_textures[4])
{
    setX(x);
    setY(y);
    setHeight(h);
    setWidgth(w);
    this->walk_textures[0] = walk_textures[0];
    this->walk_textures[1] = walk_textures[1];

    setTexture(walk_textures[0].back());
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
        
        case SDLK_DOWN:
            /* code */
            setY(getY()+speed);
            std::cout<<"down\n"<<move_counter<<"\n";
            setTexture(walk_textures[0][move_counter]);
            move_counter++;
            break;
        case SDLK_UP:
            setY(getY()-speed);
            std::cout<<"up\n";
            setTexture(walk_textures[1][move_counter]);
            move_counter++;
            break;
        case SDLK_RIGHT:
            setX(getX()+speed);
            setTexture(walk_textures[2][move_counter]);
            move_counter++;
            break;
        case SDLK_LEFT:
            setX(getX()-speed);
            setTexture(walk_textures[3][move_counter]);
            move_counter++;
            break;
        default:
            break;
    }

}

