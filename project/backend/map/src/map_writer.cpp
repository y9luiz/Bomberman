#include <map_writer.hpp>
#include "map_file_keys.hpp"

#include <nlohmann/json.hpp>

#include <fstream>

using namespace backend;
using namespace std;
using namespace json_keys;
using json = nlohmann::json;

namespace {
json createJsonFromMap(const Map &map) {
  json content;
  content[MapName] = map.name();
  content[Fields] = map.fields();
  return content;
}
}  // namespace

void MapWriter::writeToFile(const Map &map, const string &filename) {
  ofstream file(filename);
  if (!file.is_open()) {
    throw runtime_error("Could not open " + filename);
  }

  file << createJsonFromMap(map);
}