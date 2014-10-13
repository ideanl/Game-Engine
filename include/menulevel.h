#ifndef MENULEVEL_H 
#define MENULEVEL_H
#include <string>
#include "manager.h"
#include "scene.h"

// Parent Class for menus and levels
class MenuLevel {
  public:
    std::string name;
    void update();
    void render();
  protected:
    Manager<Scene> sceneManager;
};

//Class for Levels
class Level: public MenuLevel  {
};

//Class for Menus
class Menu: public MenuLevel  {
};


//Start Menu Class
class StartMenu: public Menu { 
  public:
    StartMenu();
};
#endif
