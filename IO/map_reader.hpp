#ifndef __MAP_READER__
#define __MAP_READER__
#include <Scenario/defs.hpp>
#include <Scenario/map.hpp>
#include <exception>
#include <fstream>
#include <string>
#include <vector>

#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include <Scenario/ground_block.hpp>

Map readMap(const char* filename) {
  std::ifstream f(filename);
  if (!f.is_open()) {
    throw std::ios_base::failure(filename);
  }
  std::vector<std::string> lines(1);
  Map m;
  while (f >> lines.back()) {
    lines.push_back(std::string());
  }
  lines.pop_back();  // popping a empty string
  m.data = new char*[lines.size()];
  m.w = lines[0].length();
  m.h = lines.size();
  for (int i = 0; i < lines.size(); i++) {
    m.data[i] = new char[lines[i].length()];
    for (int j = 0; j < lines[i].length(); j++) {
      m.data[i][j] = lines[i][j];
    }
  }
  return m;
}
#endif