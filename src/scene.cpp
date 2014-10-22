#include "../include/scene.h"

void Scene::update() {
}

void Scene::render() {
}

void StartScene::create(sf::RenderWindow& window) {
	windowPointer = &window;
	character.create(windowPointer, "../res/character.png", 300, 300, 10, 10);
}

void StartScene::render() {
	character.render();
}
