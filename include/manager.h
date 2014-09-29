#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <map>
#include "../include/scene.h"
#include "../include/level.h"

template <class manager_type> class Manager {
  public:
    manager_type* current;
    template <class data_type> void add(std::string type);
    void set(std::string type);
    std::map<std::string, manager_type*> objects;
  protected:
  private:
};

template <class manager_type> template <class data_type> void Manager<manager_type>::add(std::string type) {
  objects[type] = new data_type;
  objects[type]->name = type;
}

template <class manager_type> void Manager<manager_type>::set(std::string type) {
  current = objects[type];
}
#endif
