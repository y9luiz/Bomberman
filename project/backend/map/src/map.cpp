#include <map.hpp>

using namespace backend;
using namespace std;

namespace {
bool isSquareMap(const Map& map) {
  const auto height = map.fields().size();
  for (const auto& row : map.fields()) {
    if (row.size() != height) {
      return false;
    }
  }
  return true;
}

void validateMap(const Map& map) {
  const auto& fields = map.fields();
  const auto& name = map.name();

  if (fields.empty()) {
    throw invalid_argument("Could not create a map without content");
  }

  if (!isSquareMap(map)) {
    throw invalid_argument("Could not create a map asymmetric map");
  }

  if (name.empty()) {
    throw invalid_argument("Could not create a map without a name");
  }
}
}  // namespace

Map::Map(const string& name, const FieldsT& fields)
    : m_name(name), m_fields(fields) {
  validateMap(*this);
}

void Map::moveField(uint16_t xOrigin, uint16_t yOrigin, uint16_t xDest,
                    uint16_t yDest) {
  const auto field = m_fields[xOrigin][yOrigin];

  m_fields[yOrigin][xOrigin] = m_fields[yDest][xDest];
  m_fields[yDest][xDest] = field;
}