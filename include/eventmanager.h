#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics.hpp>
#include "../include/menulevel.h"
#include "scene.h"

class EventManager {
  public:
    EventManager();
    // sets the window Pointer
	void setWindowPointer(sf::RenderWindow& window);
	// sets the current scene
	void setScene(Scene* current);
	// checks for events in the game
	void check();
    // checks to see if a window event occurs
    void checkWindow();
	// checks the scene to see if an event occurs
	void checkScene();
    // runs the mainCharacter checkEvent loop
    // void checkCharacter(Character& character);
    ~EventManager();
  protected:
  private:
    sf::RenderWindow* windowPointer;
	Scene* currentScene;
	// Character* characterPointer;
    sf::Event event;
};

#endif
