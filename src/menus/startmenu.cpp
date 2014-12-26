#include "../../include/menus/startmenu.h"
#include "../../include/scenes/startscene.h"
#include "../../include/levels/testlevel.h"

void StartMenu::menuLevelUpdate() {

}

void StartMenu::setStartScene() {
  sceneManager.set<StartScene>("StartScene");
}

void StartMenu::addKeys() {
  eventManager->addKey(sf::Keyboard::Space, [&] () {  menuLevelManager.set<TestLevel>("TestLevel");});
}

void StartMenu::addEvents() {

}
