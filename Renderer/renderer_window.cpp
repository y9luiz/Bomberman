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

std::unique_ptr<SDL_Texture,SDL_Deleter> RendererWindow::loadTexture(const char * file_path)
{
    SDL_Texture * texture = NULL;

    texture = IMG_LoadTexture(renderer,file_path);
    std::unique_ptr<SDL_Texture,SDL_Deleter> texture_ptr = std::unique_ptr<SDL_Texture,SDL_Deleter>(texture,SDL_Deleter());

    if( texture == NULL)
    {
        throw std::runtime_error(SDL_GetError());
    }
    //std::unique_ptr<SDL_Texture> texture_ptr = std::unique_ptr<SDL_Texture>(*texture,SDL_Deleter());
    return  texture_ptr;
}
    
void RendererWindow::render(SDL_Texture * texture, bool flip)
{
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    
}
#include <iostream>

void RendererWindow::render(RenderableObject & obj, bool flip )
{
    //std::cout<<"bora "<<obj.getTexture()<<"\n";
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.h=32;
    src.w=32;
    
    SDL_Rect dst = obj.getRect();
    dst.x=dst.x;
    dst.w=dst.w;
    dst.h=dst.h;
    if (obj.is_player)
    {
        src.h = src.h*2;
    }
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

    for(int i =0;i<scenario_map.h;i++)
    {
        for(int j=0;j<scenario_map.w;j++)
        {
            render(scenario_map.dict_texture[i*scenario_map.w+j]);

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
