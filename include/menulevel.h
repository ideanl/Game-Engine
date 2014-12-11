#ifndef MENULEVEL_H 
#define MENULEVEL_H
#include <string>
#include "manager.h"
#include "scene.h"
#include "eventmanager.h"

// Parent Class for menus and levels
class MenuLevel {
  public:
    std::string name;
    void update();
    void render();
    void setWindowPointer(sf::RenderWindow* window);
    void setEventManager(EventManager* eventMan);
    virtual void create() = 0;
    virtual void menuLevelUpdate() = 0;
    virtual void deleteData();
    std::string state;
    Manager<Scene> sceneManager;
  protected:
    sf::RenderWindow* windowPointer;
    EventManager* eventManager;
};

//Class for Levels
class Level: public MenuLevel  {
	public:
    virtual void menuLevelUpdate() = 0;
	  virtual void create() = 0;
};

//Class for Menus
class Menu: public MenuLevel  {
	public:
    virtual void menuLevelUpdate() = 0;
	  virtual void create() = 0;
};


//Start Menu Class
class StartMenu: public Menu { 
  public:
    void create();
    void menuLevelUpdate();
};

class Level1: public Level {
  public:
    void create();
    void menuLevelUpdate();
};
#endif
