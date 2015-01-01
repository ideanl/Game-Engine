#include "../include/menulevel.h"

void MenuLevel::create() {
  setStartScene();
  addKeys();
  addEvents();
}

void MenuLevel::setWindowPointer(sf::RenderWindow* window) {
  windowPointer = window;
  sceneManager.setWindowPointer(windowPointer);
}

void MenuLevel::setEventManager(EventManager* eventMan) {
  eventManager = eventMan;
  sceneManager.setEventManager(eventManager);
}

void MenuLevel::setMenuLevelManager(Manager<MenuLevel>* menuLevelMan) {
  menuLevelManager = menuLevelMan;
  //sceneManager.setMenuLevelManager(menuLevelManager);
}

void MenuLevel::update() {
  sceneManager.update();
  menuLevelUpdate();
}

void MenuLevel::render() {
  sceneManager.render();
}
