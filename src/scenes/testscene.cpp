#include <iostream>
#include <map>
#include "../../include/game.h"
#include "../../include/scene.h"
#include "../../include/scenes/testscene.h"
#include "../../include/shapesprite.h"
#include "../../include/textsprite.h"
#include "../../include/basesprite.h"

void TestScene::create() {
  sprites["background"] = new ShapeSprite();
  sprites["header"] = new TextSprite();

  static_cast<ShapeSprite*>(sprites["background"])->create(windowPointer, 0, 0, 0, 0, windowPointer->getSize().x, windowPointer->getSize().y, sf::Vector3f(255, 255, 255), "Rectangle", "", "");
  static_cast<TextSprite*>(sprites["header"])->create(windowPointer, 0, 0, 0, 0, 500, 200, sf::Vector3f(0, 0, 0), "", "sixty.ttf", "TEST SCENE");
  sprites["header"]->setPosition<TextSprite*>(windowPointer->getSize().x/2 - sprites["header"]->getWidth()/2, 50, static_cast<TextSprite*>(sprites["header"]));
}

void TestScene::sceneUpdate() {

}
