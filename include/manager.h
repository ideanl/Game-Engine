#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <map>

template <class manager_type> class Manager {
  public:
    manager_type* current;
    template <class data_type> void add(std::string type);
    void set(std::string type);
    std::map<std::string, manager_type*> objects;
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
  objects[type] = new data_type;
  objects[type]->setWindowPointer(windowPointer);
  objects[type]->name = type;
}

template <class manager_type> void Manager<manager_type>::set(std::string type) {
  current = objects[type];
}

template <class manager_type> void Manager<manager_type>::update() {
  current->update();
}

template <class manager_type> void Manager<manager_type>::render() {
  current->render();
}
#endif
