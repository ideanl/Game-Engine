#ifndef SCENE_H
#define SCENE_H
#include <string>
#include <vector>
#include <map>
#include "basesprite.h"

class Scene {
  public:
    std::string name;
	// creates the scene in memory
	virtual void create() = 0;
	// updates the scene
    void update();
	// draws the scene
    void render();
	// sets the window pointer
    void setWindowPointer(sf::RenderWindow* window);
    std::string state;
  protected:
    sf::RenderWindow* windowPointer;
    std::map<std::string, BaseSprite*> sprites;
};

class StartScene: public Scene {
  public:
  	// creates the start scene in memory
    void create();
};
#endif
