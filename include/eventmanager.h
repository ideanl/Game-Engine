#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics.hpp>

class EventManager {
  public:
    EventManager();
    // sets the window Pointer
	  void setWindowPointer(sf::RenderWindow& window);
	  // sets the current scene
	  //void setScene(Scene* current);
    void setWindowPointer(sf::RenderWindow* window);
    void addEvent(sf::Event::EventType event = sf::Event::Closed, sf::Keyboard::Key key = sf::Keyboard::Unknown);
    std::vector<sf::Keyboard::Key> checkKeys();
    std::vector<sf::Event::EventType> checkEvents();
    // destructer
    ~EventManager();
  protected:
  private:
    sf::RenderWindow* windowPointer;
	  //Scene* currentScene;
    sf::Event event;
    std::vector<sf::Event::EventType> event_list;
    std::vector<sf::Keyboard::Key> key_list;
};

#endif
