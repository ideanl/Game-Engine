#include "../include/menulevel.h"
#include "../include/scene.h"
#include "../include/scenes/startscene.h"

void StartMenu::create() {
	sceneManager.add<StartScene>("StartScene");
	sceneManager.set("StartScene");
  eventManager->addKey(sf::Keyboard::Escape, [this] () { windowPointer->close();});
}

void StartMenu::menuLevelUpdate() {
}
