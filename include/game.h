#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Game {
  public:
    Game(int g_width, int g_height, std::string g_string);
    void start();
    ~Game();
    int width;
    int height;
    std::string title;
  protected:
  private:
    sf::RenderWindow * window;
    void update();
    void render();
    void run();
};

#endif 
