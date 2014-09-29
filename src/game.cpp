#include "../include/game.h"
#include "../include/manager.h"
#include "../include/level.h"

Game::Game(int g_width = 800, int g_height = 600, std::string g_title = "--Title--") {
  width = g_width;
  height = g_height;
  title = g_title;
  window.create(sf::VideoMode(width, height), title);
  eventManager.setWindowPointer(window);
  /* EXAMPLES OF LEVELMANAGER
  levelManager.add<Floor1>("Floor1");
  levelManager.add<Floor1>("Floor2");
  levelManager.set("Floor1");
  std::cout << levelManager.current->name << std::endl;
  levelManager.set("Floor2");
  std::cout << levelManager.current->name << std::endl; */
  start();
}

void Game::start() {
  while(window.isOpen()) {
    run();
  }
}

void Game::update() {
  eventManager.checkWindow();
}

void Game::render() {
  window.clear(sf::Color::Black);
  window.display();
}

void Game::run() {
  update();
  render();
}

Game::~Game() {

}
