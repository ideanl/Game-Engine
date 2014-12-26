#include <iostream>
#include <map>
#include "../../include/game.h"
#include "../../include/scenes/startscene.h"
#include "../../include/shapesprite.h"
#include "../../include/textsprite.h"
#include "../../include/basesprite.h"
#include "../../include/imagesprite.h"

void StartScene::create() {
  sprites["background"] = new ShapeSprite();
  sprites["header"] = new TextSprite();
  sprites["door"] = new ImageSprite();
  
  static_cast<ShapeSprite*>(sprites["background"])->create(windowPointer, 0, 0, 0, 0, windowPointer->getSize().x, windowPointer->getSize().y, sf::Vector3f(255,0,0), "Rectangle", "", "");
  static_cast<TextSprite*>(sprites["header"])->create(windowPointer, 0, 0, 0, 0, 500, 200, sf::Vector3f(255, 255, 255), "", "sixty.ttf", "Welcome to Sai");
  sprites["header"]->setPosition<TextSprite*>(windowPointer->getSize().x/2 - sprites["header"]->getWidth()/2, 50, static_cast<TextSprite*>(sprites["header"]));
  static_cast<ImageSprite*>(sprites["door"])->create(windowPointer, 120, 50, 0, 0, 80, 120, sf::Vector3f(130, 150, 10), "DOOR.png", "", "");
}

void StartScene::sceneUpdate() {
}
