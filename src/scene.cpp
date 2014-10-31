#include <iostream>
#include <map>
#include "../include/game.h"
#include "../include/scene.h"
#include "../include/shapesprite.h"
#include "../include/textsprite.h"
#include "../include/button.h"

void Scene::setWindowPointer(sf::RenderWindow* window) {
  windowPointer = window;
}

void Scene::setEventManager(EventManager* eventMan) {
  eventManager = eventMan;
}

void StartScene::create() {
  eventManager->addEvent(sf::Event::Closed, sf::Keyboard::Escape);
  sprites["background"] = new ShapeSprite();
  sprites["header"] = new TextSprite();
  static_cast<ShapeSprite*>(sprites["background"])->create(windowPointer, 0, 0, 0, 0, "rectangle", windowPointer->getSize().x, windowPointer->getSize().y, sf::Color::Red);
  static_cast<TextSprite*>(sprites["header"])->create(windowPointer, "Welcome to SAI", "sixty.ttf", 64, sf::Color::Black, windowPointer->getSize().x / 2 , 50);
}

void MainScene::create() {
  sprites["background"] = new ShapeSprite();
  sprites["header"] = new TextSprite();
  static_cast<ShapeSprite*>(sprites["background"])->create(windowPointer, 0, 0, 0, 0, "rectangle", windowPointer->getSize().x, windowPointer->getSize().y, sf::Color::Red);
  static_cast<TextSprite*>(sprites["header"])->create(windowPointer, "Welcome to the Main Place", "sixty.ttf", 64, sf::Color::Black, windowPointer->getSize().x / 2 , 50);
}

void Scene::update() {
  //Check event (returns vector<sf::Keyboard::Key>)
  std::vector<sf::Keyboard::Key> stuff = eventManager->checkKeys();
  //std::cout << stuff.size() << std::endl;
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
