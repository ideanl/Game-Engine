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
    void addEvent(sf::Event::EventType event);
    void addKey(sf::Keyboard::Key key, std::function<void()> lambda);
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
    std::vector<std::function<void()>> action_list;
    void addKeyAction(sf::Keyboard::Key key, std::function<void()> lambda);
};

#endif
