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

void StartScene::create() {
  sprites["background"] = new ShapeSprite();
  sprites["header"] = new TextSprite();
  static_cast<ShapeSprite*>(sprites["background"])->create(windowPointer, 0, 0, 0, 0, "rectangle", windowPointer->getSize().x, windowPointer->getSize().y, sf::Color::Red);
  static_cast<TextSprite*>(sprites["header"])->create(windowPointer, "Welcome to SAI", "sixty.ttf", 64, sf::Color::Black, 0 , 50);
  /*sprites["header"]->move<sf::Drawable> (windowPointer->getSize().x/2 - sprites["header"]->getWidth()/2, 50, static_cast<TextSprite*>(sprites["header"])->getText());*/
  sprites["header"]->move<TextSprite*>(windowPointer->getSize().x/2 - sprites["header"]->getWidth()/2, 50, static_cast<TextSprite*>(sprites["header"]));
}

void Scene::update() {
  for(std::map<std::string, BaseSprite*>::iterator it = sprites.begin(); it != sprites.end();++it) {
    it->second->update();
  }
}

void Scene::render() {
  for(std::map<std::string, BaseSprite*>::iterator it = sprites.begin(); it != sprites.end();++it) {
    it->second->render();
  }
}
