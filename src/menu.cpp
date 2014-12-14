#include "../include/menulevel.h"
#include "../include/scene.h"
#include "../include/scenes/startscene.h"

void StartMenu::create() {
  sceneManager.set<StartScene>("StartScene");
}

void StartMenu::menuLevelUpdate() {
}
