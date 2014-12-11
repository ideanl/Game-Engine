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

void EventManager::addKey(sf::Keyboard::Key key, std::function<void()> lambda, std::string pressed_released) {
  if (pressed_released == "pressed") {
    pressed_key_list.push_back(key);
    pressed_key_action_list.push_back(lambda);
  }
  else if (pressed_released == "released") {
    released_key_list.push_back(key);
    released_key_action_list.push_back(lambda);
  }
}

//Check for events (key pressed, key released, default for events)
void EventManager::check() {
  while(windowPointer->pollEvent(event)) {
    switch(event.type) {
      case sf::Event::KeyPressed:
        for(int i = 0;i < pressed_key_action_list.size();i++) {
          if (pressed_key_list[i] == event.key.code) {
            pressed_key_action_list[i]();
            break;
          }
        }
        break;

      case sf::Event::KeyReleased:
        for(int i = 0;i < released_key_action_list.size();i++) {
          if (released_key_list[i] == event.key.code) {
            released_key_action_list[i]();
            break;
          }
        }

      default:
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
