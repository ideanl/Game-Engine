#include "../include/menulevel.h"
#include "../include/scene.h"
#include "../include/scenes/startscene.h"

void StartMenu::create() {
	std::cout << "HERE" << std::endl;
  sceneManager.set<StartScene>("StartScene");
}

void StartMenu::menuLevelUpdate() {
}
