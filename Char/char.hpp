#pragma once
#include "../Scenario/Common/renderable_object.hpp"
#include "../Utils/circular_list.hpp"
#include <vector>
#include "../Memory/sdl_deleter.hpp"
typedef  std::vector<std::shared_ptr<SDL_Texture>> sdl_textures_ptr_list;

/**
 * @brief 
 *  Four circular buffer of SDL_Textures pointers
 * 
 */
typedef  CircularList<std::shared_ptr<SDL_Texture>> SDL_Texture_CircularList;
struct DirectionTextures
{
    CircularList<std::shared_ptr<SDL_Texture>> up;
    CircularList<std::shared_ptr<SDL_Texture>> down;
    CircularList<std::shared_ptr<SDL_Texture>> left;
    CircularList<std::shared_ptr<SDL_Texture>> rigth;
};


class Character : public RenderableObject {

    private:
        //4 types of moviment
        // up,down,left and right
        DirectionTextures direction_textures_;
        sdl_textures_ptr_list walk_textures[4];
        int last_key;
    public:
        Character();
        Character(int x,int y, int h,int w,  std::vector<std::shared_ptr<SDL_Texture>> walk_textures[4]);
        ~Character();
        void move(int key);
        void loadTextures(const char* image_path);
};