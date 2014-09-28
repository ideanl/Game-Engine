#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics.hpp>
//#include "level.h"

class EventManager {
  public:
    EventManager();
    void setWindowPointer(sf::RenderWindow& window);
    // checks to see if a window event occurs
    void checkWindow();
    // runs the level checkEvent loop
    // void checkLevel(Level& level);
    // runs the mainCharacter checkEvent loop
    // void checkCharacter(Character& character);
    ~EventManager();
  protected:
  private:
    sf::RenderWindow* windowPointer;
    // Level* levelPointer;
    // Character* characterPointer;
    sf::Event event;
};

#endif
