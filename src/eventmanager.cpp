#include "../include/eventmanager.h"

EventManager::EventManager() {

}

void EventManager::setWindowPointer(sf::RenderWindow& window) {
  windowPointer = &window;
}

void EventManager::checkWindow() {
  while(windowPointer->pollEvent(event)) {
    switch(event.type) {
      case sf::Event::Closed:
        windowPointer->close();
        break;
      case sf::Event::KeyPressed:
        if(event.key.code == sf::Keyboard::Escape)
          windowPointer->close();
        break;
      default:
        break;
    }
  }
}

/*
void EventManager::checkLevel(Level& level) {
  levelPointer = &level;
  levelPointer->checkEvent();
}
*/

/*
void EventManager::checkCharacter(character& character) {
  characterPointer = &character;
  characterPointer->checkEvent();
}
*/

EventManager::~EventManager() {

}
