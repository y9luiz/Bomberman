#include <map.hpp>
#include <map_writer.hpp>
#include <map_reader.hpp>

#include <gmock/gmock.h>

#include <filesystem>
#include <memory>
#include <vector>

using namespace backend;
using namespace testing;
using namespace std;
namespace fs = std::filesystem;

namespace {
const vector<vector<uint8_t>> DefaultMapContent = {
    {'-', '-', '-', '-', '-'}, {'|', 'x', 'x', 'x', '-'},
    {'-', 'x', 'x', 'x', '-'}, {'-', 'x', 'x', 'x', '-'},
    {'-', '-', '-', '-', '-'},
};

constexpr auto DefaultName = "map name";

constexpr auto DefaultFilename = "map.json";

bool isSameMap(const Map& map1, const Map& map2) { return true; }

}  // namespace

TEST(SadPathTests, createEmptyShouldFail) {
  const vector<vector<uint8_t>> empty;
  EXPECT_THROW(Map("", empty), invalid_argument);
}

TEST(SadPathTests, createAsymmetricShouldFail) {
  auto asymetric = DefaultMapContent;
  asymetric.pop_back();
  EXPECT_THROW(Map("", asymetric), invalid_argument);
}

TEST(SadPathTests, createEmptyNamehouldFail) {
  EXPECT_THROW(Map("", DefaultMapContent), invalid_argument);
}

class TestMap : public Test {
 public:
  TestMap() : m_map(DefaultName, DefaultMapContent) {
    EXPECT_EQ(m_map.name(), DefaultName);
    EXPECT_EQ(m_map.fields(), DefaultMapContent);
  }

 protected:
  Map m_map;
};

TEST_F(TestMap, saveMapToFile) {
  MapWriter::writeToFile(m_map, DefaultFilename);

  EXPECT_TRUE(fs::exists(DefaultFilename));
  fs::remove(DefaultFilename);
}

TEST_F(TestMap, loadMapFromFile) {
  MapWriter::writeToFile(m_map, DefaultFilename);

  const auto map = MapReader::readFromFile(DefaultFilename);

  EXPECT_TRUE(isSameMap(*map, m_map));

  fs::remove(DefaultFilename);
}

TEST_F(TestMap, loadMapFromInexistentFile) {
  EXPECT_THROW(MapReader::readFromFile(DefaultFilename), exception);
}

TEST_F(TestMap, moveField) {
  m_map.moveField(0, 0, 1, 1);
  EXPECT_THAT(m_map.fields()[0][0], DefaultMapContent[1][1]);
}
