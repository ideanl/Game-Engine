#include "../include/menulevel.h"

void MenuLevel::setWindowPointer(sf::RenderWindow* window) {
  windowPointer = window;
  sceneManager.setWindowPointer(windowPointer);
}

void MenuLevel::update() {
  sceneManager.update();
  menuLevelUpdate();
}

void MenuLevel::render() {
  sceneManager.render();
}
