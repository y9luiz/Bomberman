#pragma once
#include "Common/renderable_object.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Block : public RenderableObject
{
    private:
        bool is_indestructible;
    protected:
    public:
        inline bool getIsIndestructible(){return is_indestructible;};
        inline void setIsIndestructible(bool is_indestructible){this->is_indestructible = true;};

};