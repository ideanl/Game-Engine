#include "../include/menulevel.h"
#include "../include/scene.h"

void StartMenu::create() {
	sceneManager.add<StartScene>("StartScene");
	sceneManager.set("StartScene");
}

void StartMenu::menuLevelUpdate() {
}
