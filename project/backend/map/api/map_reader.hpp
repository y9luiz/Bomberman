#pragma once

#include <memory>
#include <string>

#include "map.hpp"

namespace backend {
class MapReader {
 public:
  static std::unique_ptr<Map> readFromFile(const std::string& filename);
};
}  // namespace backend