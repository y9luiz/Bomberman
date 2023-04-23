#include <map_reader.hpp>
#include "map_file_keys.hpp"

#include <memory>
#include <fstream>

#include <nlohmann/json.hpp>

using namespace backend;
using namespace std;
using namespace json_keys;
using json = nlohmann::json;

namespace {
unique_ptr<Map> createMapFromJson(const json &content) {
  if (!content.contains(MapName)) {
    throw invalid_argument("Json doesn't contain " + string(MapName) + " key");
  }

  if (!content.contains(Fields)) {
    throw invalid_argument("Json doesn't contain " + string(Fields) + " key");
  }

  return make_unique<Map>(content[MapName], content[Fields]);
}
}  // namespace

unique_ptr<Map> MapReader::readFromFile(const string &filename) {
  ifstream file(filename);

  if (!file.is_open()) {
    throw runtime_error("Could not open " + filename);
  }
  json content;
  file >> content;
  return createMapFromJson(content);
}