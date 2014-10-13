#include "../include/game.h"
#include "../include/scene.h"
#include "../include/shapesprite.h"

StartScene::StartScene() {
  sprites["background"] = new ShapeSprite(game);
  sprites["background"]->create();
}

void Scene::update() {
}

void Scene::render() {
}
