#pragma once

#include <atomic>
#include <memory>
#include <thread>

namespace backend {

class Map;

/**
 * @brief This class holds the state of a game session
 *
 */
class GameSession {
 public:
  GameSession(const std::string &mapFilepath);
  ~GameSession();

  GameSession(const GameSession &) = delete;
  GameSession(GameSession &&) = delete;

 private:
  /**
   * @brief Initialize session state
   *
   */
  void initialize();

  /**
   * @brief loop that contains the game routines
   *
   */
  void gameLoop();

  void stop();

  std::unique_ptr<Map> m_map;
  std::atomic<bool> m_isPlaying;
  std::thread m_loopThread;
};
}  // namespace backend