#ifndef SCENE_H
#define SCENE_H
#include <string>
class Scene {
  public:
    std::string name;
    void update();
    void render();
};

class StartScene: public Scene {
};
#endif
