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
    void check();
    void addEvent(sf::Event::EventType event, std::function<void()> lambda);
    void addKey(sf::Keyboard::Key key, std::function<void()> lambda, std::string pressed_released = "pressed");
    // destructer
    ~EventManager();
  protected:
  private:
    sf::RenderWindow* windowPointer;
	  //Scene* currentScene;
    sf::Event event;
    std::vector<sf::Event::EventType> event_list;
    std::vector<std::function<void()>> event_action_list;
    std::vector<sf::Keyboard::Key> pressed_key_list;
    std::vector<std::function<void()>> pressed_key_action_list;
    std::vector<sf::Keyboard::Key> released_key_list;
    std::vector<std::function<void()>> released_key_action_list;
};

#endif
