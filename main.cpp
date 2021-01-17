#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <thread>

#include <Renderer/renderer_window.hpp>
#include <Scenario/wall_block.hpp>
#include <Scenario/map.hpp>
#include "IO/map_reader.hpp"
#include <Char/char.hpp>
#include <unistd.h>
using namespace std;

SDL_Renderer *  RendererWindow::renderer = NULL;

int main(int argc, char ** argv)
{
    try
    {
        Map scene_map = readMap("../res/map1.txt");

        if(SDL_Init(SDL_INIT_VIDEO) > 0)
            throw runtime_error(SDL_GetError());

        if(!IMG_Init(IMG_INIT_PNG))
            throw runtime_error(SDL_GetError());

        RendererWindow renderer_window("Bomber Man v1",960,480);

        bool isRunning = true;
        
        SDL_Event event;
        SDL_Texture *  texture = RendererWindow::loadTexture(WALL_IMAGE_PATH);
        SDL_Texture *  texture2 = RendererWindow::loadTexture(GROUND_IMAGE_PATH);
        std::vector<SDL_Texture *> char_texture [4]; 

        char_texture[0].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/back_walk6.jpg"));
        char_texture[0].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/back_walk5.jpg"));
        char_texture[0].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/back_walk4.jpg"));
        char_texture[0].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/back_walk3.jpg"));
        char_texture[0].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/back_walk2.jpg"));
        char_texture[0].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/back_walk1.jpg"));

        char_texture[1].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/front_walk6.jpg"));
        char_texture[1].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/front_walk5.jpg"));
        char_texture[1].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/front_walk4.jpg"));
        char_texture[1].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/front_walk3.jpg"));
        char_texture[1].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/front_walk2.jpg"));
        char_texture[1].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/front_walk1.jpg"));

        


        char_texture[2].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/right_walk6.jpg"));
        char_texture[2].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/right_walk5.jpg"));
        char_texture[2].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/right_walk4.jpg"));
        char_texture[2].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/right_walk3.jpg"));
        char_texture[2].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/right_walk2.jpg"));
        char_texture[2].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/right_walk1.jpg"));

        char_texture[3].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/left_walk6.jpg"));
        char_texture[3].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/left_walk5.jpg"));
        char_texture[3].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/left_walk4.jpg"));
        char_texture[3].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/left_walk3.jpg"));
        char_texture[3].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/left_walk2.jpg"));
        char_texture[3].push_back(RendererWindow::loadTexture("../res/Chars/Bomberman/left_walk1.jpg"));
        

        std::map<char,SDL_Texture*> texture_dict;
        texture_dict.insert(std::pair<char,SDL_Texture*>(BLOCK_WALL,texture));
        texture_dict.insert(std::pair<char,SDL_Texture*>(BLOCK_GROUND,texture2));
        //texture_dict.insert(std::pair<char,SDL_Texture*>(PLAYER,char_texture[0].back()));
        Character p(30,30,32,32,char_texture);
        initializeMapObjectDict(scene_map,texture_dict);
        //Character *  player = scene_map.getPlayer();

        while(isRunning)
        {
            renderer_window.clearScreen();
            renderer_window.renderMap(scene_map);   
            renderer_window.render(p);
            renderer_window.display();
            if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            {
                isRunning = false;
            }
            switch( event.type ){
                case SDL_KEYDOWN:
                    if( event.key.keysym.sym ){
                        p.move(event.key.keysym.sym);
                        event.key.keysym.sym = 0;
                    }
                default:
                    break;
            }
            usleep(10000);
        }

        SDL_Quit();

    }
    catch (runtime_error e)
    {
        std::cout<<"we have a error\n"<<e.what()<<"\n";
    }


    
    return 0;
}