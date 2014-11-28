#include "../include/menulevel.h"

MenuLevel::MenuLevel() {
  eventManager->setDeleteMark("menu");
}

void MenuLevel::setWindowPointer(sf::RenderWindow* window) {
  windowPointer = window;
  sceneManager.setWindowPointer(windowPointer);
}

void MenuLevel::setEventManager(EventManager* eventMan) {
  eventManager = eventMan;
  sceneManager.setEventManager(eventManager);
}

void MenuLevel::update() {
  sceneManager.update();
  menuLevelUpdate();
}

void MenuLevel::render() {
  sceneManager.render();
}

MenuLevel::~MenuLevel() {
  eventManager->deleteDone("menu");
}
