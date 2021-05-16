#include "map.hpp"

Map::Map()
{

}

Character* Map::getPlayer()
{
    for(int i =0;i<h;i++)
    {
        for(int j =0 ;j<w;j++)
        {
            if(data [i][j]== PLAYER)
            {
                return (Character*)&dict_texture[i*w+j];
            }
        }
    }

}

void Map::initializePlayer(Character  player){

    int i = player.getY();
    int j = player.getX();
    //data[i][j] = PLAYER;
    //dict_texture[i*w+j] = player;

}
void Map::update()
{   
    Character * player = getPlayer();
    std::cout<<player->getX()<<" : "<<player->getY()<<"\n";
    data[640/player->getY()][480/player->getX()] = PLAYER;
    /*for(int i =0;i<h;i++)
    {
        for(int j =0 ;j<w;j++)
        {
            

        }

    }*/
}