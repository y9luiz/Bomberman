#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <thread>
#include "Scenario/defs.hpp"
#include <Renderer/renderer_window.hpp>
#include <Scenario/wall_block.hpp>
#include <Scenario/map.hpp>
#include "IO/map_reader.hpp"
#include <Char/char.hpp>
#include <unistd.h>
#include <memory>
#include "Memory/sdl_deleter.hpp"
using namespace std;
SDL_Renderer *  RendererWindow::renderer = NULL;

#define NUMBER_OF_PLAYER_SPRITES 6

int main(int argc, char ** argv)
{
    try
    {
        // read the map txt file
        Map scene_map = readMap("../res/map1.txt");
        
        if(SDL_Init(SDL_INIT_VIDEO) > 0)
            throw runtime_error(SDL_GetError());

        if(!IMG_Init(IMG_INIT_PNG))
            throw runtime_error(SDL_GetError());
        
        // create a render object to render the scenario and the objects
        RendererWindow renderer_window("Bomber Man v1",960,480);

        bool isRunning = true;
        
        SDL_Event event;
        
        //store the data from the wall blocks into a share_ptr to be placed on many places of the screen
        std::shared_ptr<SDL_Texture>  texture =  
            std::shared_ptr<SDL_Texture>(RendererWindow::loadTexture(WALL_IMAGE_PATH),SDL_Deleter());
        //do the same with the ground blocks
        std::shared_ptr<SDL_Texture>  texture2 = 
            std::shared_ptr<SDL_Texture>(RendererWindow::loadTexture(GROUND_IMAGE_PATH),SDL_Deleter());
        
       
        auto loadTexturesFromCharacter = 
            /**
             * @brief Lambda function to read all the input images of the disk and store it into
             * 
             * @param texture_folder_path 
             * @param walk_directions 
             */
            [](const std::string texture_folder_path,const std::vector<std::string> walk_directions,DirectionTextures  & direction_textures)
            {

                int size = walk_directions.size();

                const std::string suffix = ".jpg";
                const std::string separator = "/";

                CircularList <SDL_Texture*,SDL_Deleter> char_walk_textures[4];
                // a walk_direction name is the direction that character is walking in a string
                // e.g. back_walk, front_walk
                int i = 0;

                for(auto walk_direction:walk_directions)
                {   
                    for(int j=0;j<NUMBER_OF_PLAYER_SPRITES;j++)
                    {
                        std::string texture_filename = texture_folder_path+walk_direction + std::to_string(j+1)+ suffix;
                        SDL_Texture * ptr = RendererWindow::loadTexture(texture_filename.c_str());
                        char_walk_textures[i].push_back(ptr);    
                    }
                    i++;
                }
                

                direction_textures.up = char_walk_textures[0].copy();
                for(int i=0;i<NUMBER_OF_PLAYER_SPRITES;i++)
                {
                    std::cout<<direction_textures.up.getNextData()<<"\n";
                }
                direction_textures.down = char_walk_textures[1].copy();
                direction_textures.rigth = char_walk_textures[2].copy();
                direction_textures.left = char_walk_textures[3].copy();
                
            };  
        
        std::vector<std::string> walk_directions = {"back_walk","front_walk","right_walk","left_walk"}; 
        DirectionTextures  player_textures;

        loadTexturesFromCharacter("../res/Chars/Bomberman/",walk_directions,player_textures);

        std::map<char,SDL_Texture*> texture_dict;
        texture_dict.insert(std::pair<char,SDL_Texture*>(BLOCK_WALL,texture.get()));
        texture_dict.insert(std::pair<char,SDL_Texture*>(BLOCK_GROUND,texture2.get()));
       
        Character p(30,30,32,32,player_textures);

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
