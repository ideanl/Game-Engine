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

void EventManager::addEvent(sf::Event::EventType event, sf::Keyboard::Key key) {
  event_list.push_back(event);
  key_list.push_back(key);
}

std::vector<sf::Keyboard::Key> EventManager::checkKeys() {
  std::vector<sf::Keyboard::Key> final_events;
  while(windowPointer->pollEvent(event)) {
    switch(event.type) {
      case sf::Event::Closed:
        windowPointer->close();
        break;
      case sf::Event::KeyPressed:
        for(int i = 0;i < key_list.size();i++) {
          if (key_list[i] == event.key.code) {
            final_events.push_back(key_list[i]);
            break;
          }
        }
    }
  }
  return final_events;
}

std::vector<sf::Event::EventType> EventManager::checkEvents() {
  std::vector<sf::Event::EventType> final_events;
  while(windowPointer->pollEvent(event)) {
    for(int i = 0;i < event_list.size();i++) {
      if (event_list[i] == event.type) {
        final_events.push_back(event_list[i]);
        break;
      }
    }
  }
  return final_events;
}

EventManager::~EventManager() {

}
