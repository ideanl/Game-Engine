#include "../include/game.h"
#include <iostream>
#include "../include/manager.h"
#include "../include/menulevel.h"
#include <SFML/Graphics.hpp>

Game::Game(int g_width = 800, int g_height = 600, std::string g_title = "--Title--") {
  width = g_width;
  height = g_height;
  title = g_title;

  //Create window
  window.create(sf::VideoMode(width, height), title);

  menuLevelManager.setWindowPointer(&window);
  eventManager.setWindowPointer(&window);
  menuLevelManager.setEventManager(&eventManager);

  //Set MenuLevel class
  menuLevelManager.set<StartMenu>("StartMenu");

  eventManager.addEvent(sf::Event::Closed, [&] () { window.close();});
  eventManager.addKey(sf::Keyboard::Escape, [&] () {  window.close();});

  //set EventManager window reference
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
