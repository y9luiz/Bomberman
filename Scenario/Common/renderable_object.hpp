#pragma once

#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
class RenderableObject
{
protected:
    SDL_Texture * texture;
private:
    char * name;
    SDL_Rect rect;
public:

    ~RenderableObject(){
        //clearTexture();
        is_player = false;
    };
    inline void setTexture(SDL_Texture * texture){ this->texture = texture;};
    inline  SDL_Texture* getTexture(){return texture;};
    inline void setHeight(int height){rect.h = height;};
    inline int getHeight(){return rect.h;};
    inline void setWidgth(int width){rect.w = width;};
    inline int getWidth(){return rect.w;};
    inline void setX(int x){rect.x = x;};
    inline int getX(){return rect.x;}
    inline void setY(int y){rect.y = y;};
    inline int getY(){return rect.y;};
    inline void setRect(SDL_Rect & r){rect = r;};
    inline SDL_Rect  getRect(){return rect;};
    inline void setName(const char *name){ 
        this->name = new char[strlen(name)];
        memcpy(this->name,name,strlen(name));
    };
    inline const char *  getName(){return name;};
    inline void clearTexture()
    {
        if(texture != NULL)
        {
            SDL_DestroyTexture(texture);
            texture = NULL;
        }
    }
    bool is_player;
};