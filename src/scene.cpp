#include <iostream>
#include <map>
#include "../include/game.h"
#include "../include/scene.h"
#include "../include/shapesprite.h"

void Scene::setWindowPointer(sf::RenderWindow* window) {
  windowPointer = window;
}


StartScene::StartScene() {
  sprites["background"] = new ShapeSprite();
  //sprites["header"] = new TextSprite();
  static_cast<ShapeSprite*>(sprites["background"])->create(windowPointer, 0, 0, 0, 0, "rectangle", 50, 50, sf::Color::Red);
  //static_cast<ShapeSprite*>(sprites["background"])->create(windowPointer, 0, 0, 0, 0, "rectangle", windowPointer->getSize().x, windowPointer->getSize().y, sf::Color::Red);
  //static_cast<TextSprite*>(sprites["header"])->create(windowPointer, "Welcome to SAI", <file>, 24, sf::Color::Black, windowPointer->getSize().x / 2 , 50);
}

void Scene::update() {
  for(std::map<std::string, BaseSprite*>::iterator it = sprites.begin(); it != sprites.end();++it) {
    it->second->update();
  }
}

void Scene::render() {
  std::cout << windowPointer->getSize().x << std::endl;
  std::cout << "HERE1" << std::endl;
  for(std::map<std::string, BaseSprite*>::iterator it = sprites.begin(); it != sprites.end();++it) {
    it->second->render();
  }
}
