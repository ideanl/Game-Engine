#ifndef MENULEVEL_H 
#define MENULEVEL_H
#include <string>

// Parent Class for menus and levels
class MenuLevel {
  public:
    std::string name;
    void update();
    void render();
};

//Class for Levels
class Level: public MenuLevel  {
};

//Class for Menus
class Menu: public MenuLevel  {
};


//Start Menu Class
class StartMenu: public Menu { 
};
#endif
