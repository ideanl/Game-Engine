#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <algorithm>

template <class manager_type> class Manager {
  public:
    manager_type* current;
    std::vector<std::string>::iterator index;
    template <class data_type> void add(std::string type);
    void set(std::string type);
    std::map<std::string, manager_type*> objects;
    std::vector<std::string> names;
    void next();
    void update();
    void render();
    void setWindowPointer(sf::RenderWindow* window);
  protected:
    sf::RenderWindow* windowPointer;
  private:
};

template <class manager_type> void Manager<manager_type>::setWindowPointer(sf::RenderWindow* window) {
  windowPointer = window;
}

template <class manager_type> template <class data_type> void Manager<manager_type>::add(std::string type) {
  names.push_back(type);
  objects[type] = new data_type;
  objects[type]->setWindowPointer(windowPointer);
  objects[type]->create();
  objects[type]->name = type;
}

template <class manager_type> void Manager<manager_type>::set(std::string type) {
  current = objects[type];
  index = std::find(names.begin(), names.end(), type);
}

template <class manager_type> void Manager<manager_type>::next() {
  index++;
  current = objects[*index];
}

template <class manager_type> void Manager<manager_type>::update() {
  if (current->state == "exiting")
    next();
  current->update();
}

template <class manager_type> void Manager<manager_type>::render() {
  current->render();
}
#endif
