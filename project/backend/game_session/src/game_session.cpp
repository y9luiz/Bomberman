#include <game_session.hpp>

#include <map_reader.hpp>
#include <map.hpp>

using namespace std;
using namespace backend;

GameSession::GameSession(const string& mapFilePath)
    : m_map(MapReader::readFromFile(mapFilePath)),
      m_loopThread(&GameSession::gameLoop, this) {}

GameSession::~GameSession() {
  stop();
  if (m_loopThread.joinable()) {
    m_loopThread.join();
  }
}

void GameSession::initialize() { m_isPlaying = true; }

void GameSession::gameLoop() {
  initialize();
  while (m_isPlaying) {
    // Read incoming events using zeromq
    // If is a move event, do move
    // if is a top event, do stop
    // if is a restart event, restart
  }
}

void GameSession::stop() { m_isPlaying = false; }