#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <algorithm>
#include "eventmanager.h"
#include "scene.h"
#include <typeinfo>

template <class manager_type> class Manager {
  public:
    template <class data_type> void set(std::string type);
    std::map<std::string, manager_type*> objects;
    void update();
    void render();
    void setWindowPointer(sf::RenderWindow* window);
    void setEventManager(EventManager* eventMan);
  protected:
    manager_type* current = NULL;
    sf::RenderWindow* windowPointer;
    EventManager* eventManager;
  private:
};

template <class manager_type> void Manager<manager_type>::setWindowPointer(sf::RenderWindow* window) {
  windowPointer = window;
}

template <class manager_type> void Manager<manager_type>::setEventManager(EventManager* eventMan) {
  eventManager = eventMan;
}

template <class manager_type> template <class data_type> void Manager<manager_type>::set(std::string type) {
  //Delete old data
  if (current != NULL) {
    current->deleteData();
  }
  objects[type] = new data_type;
  objects[type]->setWindowPointer(windowPointer);
  objects[type]->setEventManager(eventManager);
  objects[type]->create();
  objects[type]->name = type;
  current = objects[type];
}

template <class manager_type> void Manager<manager_type>::update() {
  current->update();
}

template <class manager_type> void Manager<manager_type>::render() {
  current->render();
}
#endif
