#pragma once
#include "Common/renderable_object.hpp"
#include <map>
#include "../Char/char.hpp"
#include "defs.hpp"
class Map{
    public:
        Map();
        int w;
        int h;
        char **data;
        std::map<char,RenderableObject*> dict_texture;
        Character* getPlayer();
        void update();
        void initializePlayer(Character player_texture);

};