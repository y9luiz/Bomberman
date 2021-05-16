#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Scenario/Common/renderable_object.hpp"
#include "../Scenario/map.hpp"
#include "../Scenario/defs.hpp"
#include "../Memory/sdl_deleter.hpp"
class RendererWindow
{
private:
    /* data */
    SDL_Window * window;
    char * tittle;
    int width;
    int height;
public:
    static SDL_Renderer* renderer;

    RendererWindow(const char * window_tittle, int width, int height);
    inline ~RendererWindow()
    {
        if(window != NULL)
        {
            SDL_DestroyWindow(window);
            window = NULL;
        }
        if (renderer != NULL)
        {
            SDL_DestroyRenderer(renderer);
            renderer = NULL;
        }
    };

    void render(SDL_Texture * texture,bool flip = false);
    void render(RenderableObject & obj,bool flip = false);
    void renderMap(Map & scenario_map);
    static SDL_Texture* loadTexture(const char * file_path);
    void clearScreen();
    void display();

};

