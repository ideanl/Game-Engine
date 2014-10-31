#ifndef SCENE_H
#define SCENE_H
#include <string>
#include <vector>
#include <map>
#include "basesprite.h"
#include "eventmanager.h"

class Scene {
  public:
    std::string name;
	virtual void create() = 0;
    void update();
    void render();
    void setWindowPointer(sf::RenderWindow* window);
    void setEventManager(EventManager* eventMan);
    std::string state;
  protected:
    sf::RenderWindow* windowPointer;
    EventManager* eventManager;
    std::map<std::string, BaseSprite*> sprites;
};

class StartScene: public Scene {
  public:
    void create();
};

class MainScene: public Scene {
  public:
    void create();
};
#endif
