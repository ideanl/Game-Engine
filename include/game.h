#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "eventmanager.h"
#include "menulevel.h"
#include "manager.h"

class Game {
  public:
    Game(int g_width, int g_height, std::string g_string);
    void start();
    ~Game();
    int width;
    int height;
    std::string title;
    sf::RenderWindow window;
  protected:
  private:
    EventManager eventManager;
    Manager<MenuLevel> menuLevelManager;
    void update();
    void render();
    void run();
};

extern Game game;

#endif 
