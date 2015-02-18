#include <iostream>
#include <map>
#include "../../include/game.h"
#include "../../include/scenes/startscene.h"
#include "../../include/shapesprite.h"
#include "../../include/textsprite.h"
#include "../../include/basesprite.h"
#include "../../include/imagesprite.h"
#include "../../include/animationsprite.h"

void StartScene::create() {
  sprites["background"] = new ShapeSprite();
  sprites["header"] = new TextSprite();
  //sprites["bg_door"] = new ShapeSprite();
  //sprites["door"] = new AnimationSprite();
  sprites["main_character"] = new AnimationSprite();
  //sprites["char"] = new ImageSprite();

  //AnimationSprite* door = static_cast<AnimationSprite*>(sprites["door"]);
  
  static_cast<ShapeSprite*>(sprites["background"])->create(windowPointer, windowPointer->getSize().x/2, windowPointer->getSize().y/2, 0, 0, windowPointer->getSize().x, windowPointer->getSize().y, sf::Vector3f(255,0,0), "Rectangle", "", "");
  static_cast<TextSprite*>(sprites["header"])->create(windowPointer, 0, 0, 0, 0, 500, 200, sf::Vector3f(255, 255, 255), "", "sixty.ttf", "Welcome to Sai");
  //static_cast<ShapeSprite*>(sprites["bg_door"])->create(windowPointer, 300, 200, 0, 0, 350, 520, sf::Vector3f(0, 0, 0), "Rectangle", "", "");

  sprites["header"]->setPosition<TextSprite*>(windowPointer->getSize().x * .50, 50, static_cast<TextSprite*>(sprites["header"]));

  //SpriteConfig* door_config = new AnimationConfig(0.15, 10, 10, 1, false);
  //door->create(windowPointer, static_cast<ShapeSprite*>(sprites["bg_door"])->getPos().x-static_cast<ShapeSprite*>(sprites["bg_door"])->getWidth()*.50, static_cast<ShapeSprite*>(sprites["bg_door"])->getPos().y-static_cast<ShapeSprite*>(sprites["bg_door"])->getHeight()*.50, 0, 0, 350, 540, sf::Vector3f(0, 0, 100), "door.png", "", "", door_config);

  SpriteConfig* main_character_config = new AnimationConfig(0.2, 10, 4, 3, false, false, 6);
  static_cast<AnimationSprite*>(sprites["main_character"])->create(windowPointer, 0, 0, 0, 0, 402, 535, sf::Vector3f(0, 0, 0), "main_character.png", "", "", main_character_config);
  
  //static_cast<ImageSprite*>(sprites["char"])->create(windowPointer, 0, 0, 0, 0, 1607, 1318, sf::Vector3f(0, 0, 0), "main_character.png", "", "");

  eventManager->addKey(sf::Keyboard::Left, [this] () { static_cast<AnimationSprite*>(sprites["main_character"])->curr_moving = true; } );
  eventManager->addKey(sf::Keyboard::Left, [this] () { static_cast<AnimationSprite*>(sprites["main_character"])->curr_moving = false; }, "released");
  //eventManager->addKey(sf::Keyboard::Up, [door] () { if(door->end()) { door->curr_moving = false; } else { door->curr_moving = true; } }, "pressed");
  //eventManager->addKey(sf::Keyboard::Up, [door] () { door->curr_moving = false; }, "released");
}

void StartScene::sceneUpdate() {
}
