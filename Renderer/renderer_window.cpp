#include <renderer_window.hpp>
#include <string.h>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "../Scenario/wall_block.hpp"
RendererWindow::RendererWindow(const char * window_tittle, int width, int height)
{   
    tittle = new char[strlen(window_tittle)];
    memcpy(this->tittle,window_tittle,strlen(window_tittle));
    this->width = width;
    this->height = height;

    this->window = SDL_CreateWindow(window_tittle,0,0,width,height,SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        throw std::runtime_error(SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    if(renderer == NULL)
    {
        throw std::runtime_error(SDL_GetError());
    }
}
SDL_Texture* RendererWindow::loadTexture(const char * file_path)
{
    SDL_Texture * texture = NULL;
    texture = IMG_LoadTexture(renderer,file_path);
    if( texture == NULL)
    {
        throw std::runtime_error(SDL_GetError());
    }
    //std::unique_ptr<SDL_Texture> texture_ptr = std::unique_ptr<SDL_Texture>(*texture,SDL_Deleter());
    return  texture;
}
    
void RendererWindow::render(SDL_Texture * texture, bool flip)
{
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    
}
#include <iostream>

void RendererWindow::render(RenderableObject & obj, bool flip )
{
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.h=block_h_;
    src.w=block_w_;
    
    SDL_Rect dst = obj.getRect();
   
    if(flip){
        SDL_RendererFlip flip;
        flip =SDL_FLIP_HORIZONTAL;
        SDL_RenderCopyEx(renderer,obj.getTexture(),&src,&dst,0,NULL,flip);
    }
    else{
        SDL_RenderCopy(renderer,obj.getTexture(),&src,&dst);
    }
}
void RendererWindow::renderMap(Map & scenario_map )
{

    char val;
    for(int i =0;i<scenario_map.h;i++)
    {
        for(int j=0;j<scenario_map.w;j++)
        {
            val = scenario_map.data[i][j];
            
            if(scenario_map.dict_texture[val]!= nullptr){
                scenario_map.dict_texture[val]->setX(j*block_w_);
                scenario_map.dict_texture[val]->setY(i*block_h_);
                render(*scenario_map.dict_texture[val]);
            }
        }
    }
}
void RendererWindow::clearScreen()
{
    SDL_RenderClear(renderer);
}
void RendererWindow::display()
{   
    SDL_RenderPresent(renderer);
}
