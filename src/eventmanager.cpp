#include <iostream>
#include "../include/eventmanager.h"

EventManager::EventManager() {
  //addEvent(sf::Event::Closed);
}

void EventManager::setWindowPointer(sf::RenderWindow* window) {
  windowPointer = window;
}

// sets the window Pointer 
void EventManager::setWindowPointer(sf::RenderWindow& window) {
  windowPointer = &window;
}

// sets the current scene
/*void EventManager::setScene(Scene* current) {
	currentScene = current;
}*/

void EventManager::addEvent(sf::Event::EventType event, std::function<void()> lambda) {
  event_list.push_back(event);
  event_action_list.push_back(lambda);
}

void EventManager::addKey(sf::Keyboard::Key key, std::function<void()> lambda) {
  addKeyAction(key, lambda);
}

void EventManager::addKeyAction(sf::Keyboard::Key key, std::function<void()> lambda) {
  key_list.push_back(key);
  key_action_list.push_back(lambda);
}

void EventManager::check() {
  while(windowPointer->pollEvent(event)) {
    if(event.type == sf::Event::KeyPressed) {
      for(int i = 0;i < key_list.size();i++) {
        if(key_list[i] == event.key.code) {
          key_action_list[i]();
          break;
        }
      }
    }
    else {
      for(int i = 0;i < event_list.size();i++) {
        if(event_list[i] == event.type) {
          event_action_list[i]();
          break;
        }
      }
    }
  }
}

EventManager::~EventManager() {

}
