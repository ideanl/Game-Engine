#include <iostream>
#include <map>
#include "../../include/game.h"
#include "../../include/scene.h"
#include "../../include/scenes/testscene.h"
#include "../../include/shapesprite.h"
#include "../../include/basesprite.h"
#include <iostream>

void TestScene::create() {
  sprites["background"] = new ShapeSprite();

  static_cast<ShapeSprite*>(sprites["background"])->create(windowPointer, 0, 0, 0, 0, windowPointer->getSize().x, windowPointer->getSize().y, sf::Vector3f(255, 255, 255), "Rectangle", "", "");
}

void TestScene::sceneUpdate() {

}
