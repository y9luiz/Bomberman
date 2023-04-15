#pragma once
#include <vector>

#include "../Memory/sdl_deleter.hpp"
#include "../Scenario/Common/renderable_object.hpp"
#include "../Utils/circular_list.hpp"
// typedef  std::vector<std::shared_ptr<SDL_Texture>> sdl_textures_ptr_list;

/**
 * @brief
 *  Four circular buffer of SDL_Textures pointers
 *
 */

typedef CircularList<SDL_Texture*, SDL_Deleter> SDL_Texture_CircularList;
struct DirectionTextures {
  CircularList<SDL_Texture*, SDL_Deleter> up;
  CircularList<SDL_Texture*, SDL_Deleter> down;
  CircularList<SDL_Texture*, SDL_Deleter> left;
  CircularList<SDL_Texture*, SDL_Deleter> rigth;
};

class Character : public RenderableObject {
 private:
  // 4 types of moviment
  //  up,down,left and right
  DirectionTextures direction_textures_;
  // sdl_textures_ptr_list walk_textures[4];
  int last_key;

 public:
  Character();
  Character(int x, int y, int h, int w, DirectionTextures& direction_textures);
  ~Character();
  void move(int key);
  void loadTextures(const char* image_path);
};
