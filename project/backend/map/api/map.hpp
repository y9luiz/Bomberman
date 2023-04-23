#pragma once

#include <stdexcept>
#include <string>
#include <vector>

namespace backend {
class Map {
  using FieldsT = std::vector<std::vector<uint8_t>>;

 public:
  Map(const std::string& name, const FieldsT& fields);
  ~Map() = default;

  Map(const Map&) = delete;
  Map(Map&&) = delete;

  void moveField(uint16_t xOrigin, uint16_t yOrigin, uint16_t xDest,
                 uint16_t yDest);

  inline const std::string& name() const { return m_name; }
  inline const FieldsT& fields() const { return m_fields; }

 private:
  const std::string m_name;
  FieldsT m_fields;
};
}  // namespace backend