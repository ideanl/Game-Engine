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

void EventManager::addEvent(sf::Event::EventType event) {
  event_list.push_back(event);
}

void EventManager::addKey(sf::Keyboard::Key key, std::function<void()> lambda) {
  addKeyAction(key, lambda);
}

void EventManager::addKeyAction(sf::Keyboard::Key key, std::function<void()> lambda) {
  key_list.push_back(key);
  action_list.push_back(lambda);
}

std::vector<sf::Keyboard::Key> EventManager::checkKeys() {
  std::vector<sf::Keyboard::Key> final_events;
  while(windowPointer->pollEvent(event)) {
    switch(event.type) {
      case sf::Event::KeyPressed:
        for(int i = 0;i < key_list.size();i++) {
          if (key_list[i] == event.key.code) {
            action_list[i]();
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
