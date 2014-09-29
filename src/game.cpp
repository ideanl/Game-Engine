#include "../include/game.h"
#include "../include/manager.h"
#include "../include/level.h"

Game::Game(int g_width = 800, int g_height = 600, std::string g_title = "--Title--") {
  width = g_width;
  height = g_height;
  title = g_title;
  window.create(sf::VideoMode(width, height), title);
  levelManager.addLevel<Floor1>("Floor1");
  start();
}

void Game::start() {
  while(window.isOpen()) {
    run();
  }
}

void Game::update() {

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
