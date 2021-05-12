#pragma once
#include "../Scenario/Common/renderable_object.hpp"
#include <vector>
#include <memory>
class Character : public RenderableObject {

    private:
        //4 types of moviment
        // up,down,left and right
        std::vector<std::shared_ptr<SDL_Texture>> walk_textures[4];
        int last_key;
    public:
        Character();
        Character(int x,int y, int h,int w,  std::vector<std::shared_ptr<SDL_Texture>> walk_textures[4]);
        ~Character();
        void move(int key);
        void loadTextures(const char* image_path);
};