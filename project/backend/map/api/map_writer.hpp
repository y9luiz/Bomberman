#pragma once

#include <memory>
#include <string>

#include "map.hpp"

namespace backend {
class MapWriter {
 public:
  static void writeToFile(const Map& map, const std::string& filename);
};
}  // namespace backend