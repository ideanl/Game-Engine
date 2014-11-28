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

// Sets the index to delete from key_list/action_list 
// when menu or scene is destroyed
void EventManager::setDeleteMark(std::string menu_level) {
  cout << deleteIndex_menu << std::endl;
  //if (menu_level == "menu")
  //  deleteIndex_menu = key_list.size();
  //else if (menu_level == "scene")
  //  deleteIndex_scene = key_list.size();
}

//Deletes from key_list/action_list from the delete index
void EventManager::deleteDone(std::string menu_level) {
  if (menu_level == "menu") {
    for(int i = key_list.size() - 1;i >= deleteIndex_menu;i--) {
      key_list.pop_back();
      action_list.pop_back();
    }
  } else if (menu_level == "scene") {
    
  }
}

EventManager::~EventManager() {

}
