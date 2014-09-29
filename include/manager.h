#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <map>
#include "../include/scene.h"
#include "../include/level.h"

class Manager {
  public:
    //map<name,  scenes;
    Scene* currentScene;
  protected:
  private:
};

class LevelManager {
  public:
    LevelManager();
    template <class level_type> void addLevel(std::string type);
    template <class level_type> void setLevel(std::string type);
    std::map<std::string, Level> levels;
    Level* current;
};
#endif
