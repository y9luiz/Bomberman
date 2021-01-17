#ifndef __MAP_READER__
#define __MAP_READER__
#include <fstream>
#include <exception>
#include <string>
#include <vector>
#include <Scenario/map.hpp>
#include <Scenario/defs.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include  <Scenario/ground_block.hpp>


Map  readMap(const char * filename)
{
    std::ifstream f(filename);
    if(!f.is_open())
    {
        throw std::ios_base::failure(filename);
    }
    std::vector<std::string> lines(1);
    Map m;
    while(f>>lines.back())
    {

        lines.push_back(std::string());
    }

    m.data = new char*[lines.size()];
    m.w = lines[0].length();
    m.h =lines.size();
    for(int i=0;i<lines.size();i++)
    {
        m.data[i] = new char[lines[i].length()];
        for(int j=0;j<lines[i].length();j++)
        {   
            m.data[i][j] = lines[i][j];
        }
    }


    return m;
}



void  initializeMapObjectDict(Map & m,std::map<char,SDL_Texture*> &texture_dict) 
{
   
   int size_x = 640/32;
   int size_y = 480/16;
    size_x = size_y;
    for(int i =0;i<m.h;i++)
    {
        for(int j=0;j<m.w;j++)
        {
            int pos_x = j*size_x;
            int pos_y = i*size_y;
            if (m.data[i][j] == BLOCK_GROUND)
            {
                SDL_Texture * texture = texture_dict[BLOCK_GROUND];
                
                WallBlock *b = new WallBlock (pos_x,pos_y,size_y,size_x,texture);

                m.dict_texture.insert(std::pair<int,WallBlock>(i*m.w+j,*b));
            }
            else if (m.data[i][j] == BLOCK_WALL)
            {
                SDL_Texture * texture = texture_dict[BLOCK_WALL];
                
                GroundBlock *b = new GroundBlock (pos_x,pos_y,size_y,size_x,texture);
                
                m.dict_texture.insert(std::pair<int,GroundBlock>(i*m.w+j,*b));
            }
            
            /*if( m.data[i][j] == PLAYER)
            {
                SDL_Texture * texture = texture_dict[PLAYER];
                
                Character *b = new Character (pos_x,pos_y,size_y,size_x,texture);
                b->is_player = true;
                m.dict_texture.insert(std::pair<int,Character>(i*m.w+j,*b));
            }*/
            
        }
    }
    


}
#endif