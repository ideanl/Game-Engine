#include "../include/game.h"
#include <iostream>
#include "../include/manager.h"
#include "../include/menulevel.h"

Game::Game(int g_width = 800, int g_height = 600, std::string g_title = "--Title--") {
  width = g_width;
  height = g_height;
  title = g_title;

  //Create window
  window.create(sf::VideoMode(width, height), title);

  //set EventManager window reference
  eventManager.setWindowPointer(window);

  //Create MenuLevel classes
  menuLevelManager.add<StartMenu>("StartMenu");
  //Set MenuLevel class
  menuLevelManager.set("StartMenu");
  start();
}

void Game::start() {
  while(window.isOpen()) {
    run();
  }
}

void Game::update() {
  eventManager.check();
  menuLevelManager.update();
}

void Game::render() {
  window.clear(sf::Color::Black);
  menuLevelManager.render();
  window.display();
}

void Game::run() {
  update();
  render();
}

Game::~Game() {

}
