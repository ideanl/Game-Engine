#include "../include/menulevel.h"

void MenuLevel::setWindow(sf::RenderWindow* windowPointer) {
  window = windowPointer;
}

void MenuLevel::update() {
  sceneManager.update();
}

void MenuLevel::render() {
  sceneManager.render();
}
