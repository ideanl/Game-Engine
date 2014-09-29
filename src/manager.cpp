#include "../include/manager.h"

LevelManager::LevelManager() {
}

template <class level_type> void LevelManager::addLevel(std::string type) {
  levels[type] = new level_type;
}

template <class level_type> void LevelManager::setLevel(std::string type) {
  current = &levels[type];
}
