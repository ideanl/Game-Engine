#include <iostream>
#include <map>
#include "../include/game.h"
#include "../include/scene.h"
#include "../include/shapesprite.h"
#include "../include/textsprite.h"
#include "../include/basesprite.h"
#include <iostream>

void Scene::setWindowPointer(sf::RenderWindow* window) {
  windowPointer = window;
}

void Scene::setEventManager(EventManager* eventMan) {
  eventManager = eventMan;
}

void Scene::update() {
  sceneUpdate();
  //Pass relevant events to relevant sprites here into their update functions which handles them...
  for(std::map<std::string, BaseSprite*>::iterator it = sprites.begin(); it != sprites.end();++it) {
    it->second->update();
  }
}

void Scene::render() {
  for(std::map<std::string, BaseSprite*>::iterator it = sprites.begin(); it != sprites.end();++it) {
    it->second->render();
  }
}

Scene::~Scene() {
  for(auto it = sprites.begin();it != sprites.end();it++) {
    delete it->second;
  }
}
