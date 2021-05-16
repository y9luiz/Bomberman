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
#endif