#include "../include/game.h"

Game::Game(int g_width = 800, int g_height = 600, std::string g_title = "--Title--") {
  width = g_width;
  height = g_height;
  title = g_title;
  sf::RenderWindow currWindow(sf::VideoMode(width, height), title);
  window = &currWindow;
  start();
}

void Game::start() {
  while(window->isOpen()) {
    run();
  }
}

void Game::update() {

}

void Game::render() {
  window->clear(sf::Color::Black);
  window->display();
}

void Game::run() {
  update();
  render();
}

Game::~Game() {

}
