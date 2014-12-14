#include <iostream>
#include <map>
#include "../../include/game.h"
#include "../../include/scene.h"
#include "../../include/scenes/startscene.h"
#include "../../include/shapesprite.h"
#include "../../include/textsprite.h"
#include "../../include/basesprite.h"
#include "../../include/imagesprite.h"
#include "../../include/animationsprite.h"
#include <iostream>

void StartScene::create() {
  sprites["background"] = new ShapeSprite();
  sprites["header"] = new TextSprite();
  sprites["door"] = new ImageSprite();
  sprites["main_character"] = new AnimationSprite();
  
  static_cast<ShapeSprite*>(sprites["background"])->create(windowPointer, 0, 0, 0, 0, windowPointer->getSize().x, windowPointer->getSize().y, sf::Vector3f(255,0,0), "Rectangle", "", "");
  static_cast<TextSprite*>(sprites["header"])->create(windowPointer, 0, 0, 0, 0, 500, 200, sf::Vector3f(255, 255, 255), "", "sixty.ttf", "Welcome to Sai");
  sprites["header"]->setPosition<TextSprite*>(windowPointer->getSize().x/2 - sprites["header"]->getWidth()/2, 50, static_cast<TextSprite*>(sprites["header"]));
  static_cast<ImageSprite*>(sprites["door"])->create(windowPointer, 120, 50, 0, 0, 80, 120, sf::Vector3f(130, 150, 10), "DOOR.png", "", "");

  SpriteConfig* main_character_config = new AnimationConfig(0.3, 10, 4, 3, false, 6);
  static_cast<AnimationSprite*>(sprites["main_character"])->create(windowPointer, 0, 0, 0, 0, 719, 450, sf::Vector3f(0, 0, 0), "main_character.png", "", "", main_character_config);
  //eventManager->addKey(sf::Keyboard::Left, [this] () { static_cast<AnimationSprite*>(sprites["main_character"])->curr_moving = true; } );
  //eventManager->addKey(sf::Keyboard::Left, [this] () { static_cast<AnimationSprite*>(sprites["main_character"])->curr_moving = false; }, "released");
}

void StartScene::sceneUpdate() {
}
