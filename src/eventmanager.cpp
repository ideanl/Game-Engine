#include "../include/eventmanager.h"

EventManager::EventManager() {

}

// sets the window Pointer 
void EventManager::setWindowPointer(sf::RenderWindow& window) {
  windowPointer = &window;
}

// sets the current scene
void EventManager::setScene(Scene* current) {
	currentScene = current;
}

// checks for all events in the game
void EventManager::check() {
	checkWindow();
	checkScene();
	// checkCharacter();
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

void EventManager::checkScene() {
	//currentScene->checkEvent();
}

/*
void EventManager::checkCharacter(character& character) {
  characterPointer = &character;
  characterPointer->checkEvent();
}
*/

EventManager::~EventManager() {

}
