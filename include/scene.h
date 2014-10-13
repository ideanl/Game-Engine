#ifndef SCENE_H
#define SCENE_H
#include <string>
#include <vector>
#include <map>
#include "basesprite.h"
class Scene {
  public:
    std::string name;
    void update();
    void render();
  protected:
    std::map<std::string, BaseSprite*> sprites;
};

class StartScene: public Scene {
  public:
    StartScene();
};
#endif
