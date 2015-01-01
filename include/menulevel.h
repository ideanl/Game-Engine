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
    void setMenuLevelManager(Manager<MenuLevel>* menuLevelMan); 
    void create();
    virtual void menuLevelUpdate() = 0;
    std::string state;
    Manager<Scene> sceneManager;
  protected:
    sf::RenderWindow* windowPointer;
    EventManager* eventManager;
    Manager<MenuLevel>* menuLevelManager;
  private:
    virtual void setStartScene() = 0;
    virtual void addKeys() = 0;
    virtual void addEvents() = 0;
};

//Class for Levels
class Level: public MenuLevel  {
	public:
    virtual void menuLevelUpdate() = 0;
  private:
    virtual void setStartScene() = 0;
    virtual void addKeys() = 0;
    virtual void addEvents() = 0;
};

//Class for Menus
class Menu: public MenuLevel  {
	public:
    virtual void menuLevelUpdate() = 0;
  private:
    virtual void setStartScene() = 0;
    virtual void addKeys() = 0;
    virtual void addEvents() = 0;
};

#endif
