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
    void setWindowPointer(sf::RenderWindow* window);
	virtual void create() = 0;
  protected:
    sf::RenderWindow* windowPointer;
    Manager<Scene> sceneManager;
    sf::RenderWindow* window;
};

//Class for Levels
class Level: public MenuLevel  {
	public:
	  void create();
};

//Class for Menus
class Menu: public MenuLevel  {
	public:
	  virtual void create() = 0;
};


//Start Menu Class
class StartMenu: public Menu { 
  public:
	void create();
};
#endif
